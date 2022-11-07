#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<string_view>
using std::ifstream;
using std::string;

class Quiz
{
private:
	ifstream inState;				//holds the state names and respective capitals

	const static int ROW = 50;		// 50 x 2 | 50 rows 2 columns
	const static int COL = 2;

	string stateInfo[ROW][COL];


	int numCorrect = 0;				//number of correct responses from the user

									//methods
	void openStateFile();			//Open file used for data population
	void testStateFile();			//Test if it opens
	void closeStateFile();			//Close file after population to save memory
	void populateInfo();			//Function used to populate array
	void convertCase(string&, const int); //.tolower function to compare strings of answer to user input
	void questions();				//Function that asks questions to user for user input
	void compare(const string, const int); //compare the lower case answer to the lower case user input
	void display();					//Function that prints the final scre of the user

public:
	void driver();					//order of execution

};
