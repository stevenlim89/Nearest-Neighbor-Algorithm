#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> Pair;

struct Order
{
    bool operator()(Pair const& a, Pair const& b) const
    {
        return a.first > b.first;
    }
};

int distance(const vector<int>& v1, const vector<int>& v2){
    int sum = 0;
    for(int i = 0; i < v1.size() - 1; i++){
        sum += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }

    return sum;
}

double nearestNeighborError(vector< vector<int> > training_set, vector < vector<int> > test_set, int k){
    vector< pair<int,int> > nearest;
    int dist = 0;
    int label = 0;
    pair<int, int> p;
    priority_queue < Pair, vector<Pair>, Order > queue;
    int labelArray [10];
    int temp = 0;
    int highestCount = 0;
    int errorCount = 0;
    int distCounter = 0;

    // Get distance and label to put in pair
    for(int index = 0; index < test_set.size(); index++){
        for(int ts = 0; ts < training_set.size(); ts++){
           dist = distance(training_set[ts], test_set[index]);
           label = training_set[ts][training_set[ts].size() - 1];
           p.first = dist;
           p.second = label;
           queue.push(p);
        }

        for(int i = 0; i < k; i++){
            labelArray[queue.top().second]++;
            //cout << "Queue size: " <<  queue.top().second << endl; 
            queue.pop();
        }

        for(int arr = 0; arr < 10; arr++){
            if(labelArray[arr] >= highestCount) {
                //cout << "This is the label in array: " << arr << " count:" << labelArray[arr] << endl;
                temp = arr; 
                highestCount = labelArray[arr]; 
            }
            labelArray[arr] = 0;
        }

        highestCount = 0;

        //cout << "This is the test_set label: " << test_set[index][test_set[index].size()-1] << endl;
        if (temp != test_set[index][test_set[index].size()-1]){
            cout << "This is the index: " << index << " temp:" << test_set[index][test_set[index].size()-1] << endl;
           errorCount++; 
        }
            

        while(!queue.empty()){
            queue.pop();
        }

        temp = 0;
    }

    return (double)errorCount/test_set.size();

}

int main() {

    char delimiter = ' ';

    // feature vector
    vector<int> feature;

    // Matrix to hold all feature vecttors
    vector< vector<int> > featureMatrix;

    // Variable to hold char number from file
    char line[4];

    // Variable to hold number that used to be a char
    int number;

    // Counter to check when to put into featureMatrix
    int count = 0;

    ifstream trainfile; 
    trainfile.open("hw2train.txt");

    //check to see if the file is opened:
    if (trainfile.is_open())
    {
        //while there are still lines in the
        //file, keep reading:
        while (! trainfile.eof() )
        {
            count++;

            // Get character from file and store in variable line
            trainfile.getline(line, 256, delimiter);

            // line is a character so convert to int
            number = atoi(line);

            // add to feature vector
            feature.push_back(number);

            // If counter is 785, then feature vector has been filled and you can add it to matrix
            if(count == 785){
                featureMatrix.push_back(feature);

                // reset values
                count = 0;
                feature.clear();
            } 

        }     
    }

    trainfile.close();

    /* Testing purposes
    for(int i = 0; i < featureMatrix[2].size(); i++){
        cout<<featureMatrix[2][i] << endl;
    }*/

    double value = nearestNeighborError(featureMatrix, featureMatrix, 1);

    cout << "This is the error: " << value << endl;
   
    return 0;
}
