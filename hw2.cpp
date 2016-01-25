#include <stdio.h>
#include <ifstream>
#include <Strings>

main() {

    String delimiter = " ";
    array<String> coordinates;


    String lines [];
    String line;


    ifstream trainfile ("hw2train.txt");

    //check to see if the file is opened:
	  if (trainfile.is_open())
	  {
        //while there are still lines in the
		//file, keep reading:
        while (! trainfile.eof() )
        {
      	//place the line from myfile into the
      	//line variable:
	 	getline (myfile,line);
   	 
    	coordinates = line->System.Split();       
	}
}
