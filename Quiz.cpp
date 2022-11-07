#include"Quiz.h"

/******************************Method Definitions**********************************/
//Quiz: openStateFile
//open the state name and capital file
void Quiz::openStateFile()
{
	inState.open("StateInfo.txt");

	//test
	testStateFile();
}

//Quiz: testStateFile()
//test if the StateName.txt file opened properly
void Quiz::testStateFile()
{
	using std::cerr;
	using std::endl;

	if (!inState)	//if file cannot be opened
	{
		cerr << "StateInfo.txt file did not open properly" << endl;
		exit(9998);
	}
}


//Quiz: closeStateFile
//close the StateName.txt file
void Quiz::closeStateFile()
{
	inState.close();
}


//Quiz: populateName
//populate the stateName array with the contents of the StateName.txt file
void Quiz::populateInfo()
{
	using std::getline;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			getline(inState, stateInfo[i][j]);
			//std::cout << " " << stateInfo[i][j]; //for testing
		}

		//std::cout << std::endl; //for testing
	}

}


//Quiz: questions
//prompt the user for the capital of a state until all states asked
void Quiz::questions()
{
	using std::cout;
	using std::cin;
	using std::endl;

	//local variable
	string answer;

	//begin quiz
	for (int i = 0; i < ROW; i++)
	{

		//ask question and get user input
		cout << "What is the capital of " << stateInfo[i][0] << " ?: ";
		getline(cin, answer);
		
		//convert answer to lowercase
		convertCase(answer, i);

		//compare answers
		compare(answer, i);

	}

}

//Quiz: convertCase
//convert the user's answer and the capital array answer to lowercase for comparison
void Quiz::convertCase(string& a, const int index)
{

	//convert user answer
	for (int k = 0; k < a.length(); k++)
		a[k] = tolower(a[k]);

	//convert correct answer
	for (int m = 0; m < stateInfo[index][1].length(); m++)
		stateInfo[index][1][m] = tolower(stateInfo[index][1][m]);

	//display user input and correct answer
	std::cout << "answer = " << a << std::endl;
	std::cout << "correct answer = " << stateInfo[index][1] << std::endl << std::endl;

}

//Quiz: compare
//compare the user's answer to the correct answer
void Quiz::compare(const string ans, const int i)
{

	//increment numCorect variable if the answer is correct
	if (ans == stateInfo[i][1])
		numCorrect++;

}

//Quiz: display
//display the output
void Quiz::display()
{
	//calculations for percentage grade
	double eqNum = numCorrect;
	double percent = (eqNum / 50)*100;

	using std::cout;
	using std::endl;

	//prompt and grade given at end
	cout << endl << endl;
	cout << "You answered " << numCorrect << " questions correctly." << endl;
	cout << "Your grade for this quiz is %" << percent << endl << endl;
}



//Quiz: driver
//order of execution
void Quiz::driver()
{
	//open the file
	openStateFile();

	//populate the array
	populateInfo();

	//close the input files
	closeStateFile();

	//start quiz
	questions();

	//display results
	display();

}