// AifilTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"


int main(int argc, char * argv[]) {

	cout << "Question 1: " << endl;
	Question1::PrintExample();
	cout << endl << endl << endl;
	
	cout << "Question 2: " << endl;
	Question2::PrintExample();
	cout << endl << endl << endl;

	cout << "Question 3: " << endl;
	Question3::PrintExample(argc, argv);
	cout << endl << endl << endl;

	cout << "Question 4: " << endl;
	Question4::PrintExample();
	cout << endl << endl << endl;

	cin.get();
	cin.get();	
}
