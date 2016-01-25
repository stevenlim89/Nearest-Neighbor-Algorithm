#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    char delimiter = ' ';
    vector<string> coordinates;
    vector<int> feature;
    vector< vector<int> > featureMatrix;

    //string lines [];
    char line[4];

    char fromFile;
    int number;
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
            //place the line from myfile into the
            //line variable:
            //getline (myfile,line);
            count++;
            trainfile.getline(line, 256, delimiter);
            number = atoi(line);
            feature.push_back(number);

            if(count == 785){
                featureMatrix.push_back(feature);
                count = 0;
            } 

        }  
        
        //coordinates = line->System.Split();       
    }

    trainfile.close();

    cout<< featureMatrix.size() << endl;
   
    return 0;
}
