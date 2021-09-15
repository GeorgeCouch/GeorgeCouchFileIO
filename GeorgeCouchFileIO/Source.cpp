/* Block Comment Header
Name George Couch and Brett Smitch
Date 09/15/2021
Our government spy device that takes down reminders, alarms, schedule, and messages
*/
#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"

using namespace std;

int main()
{
	int usrChoice;
	string contChoice = "y";
	while (contChoice == "y") //loop to keep using the Government Spy Device
	{
		cout << "What would you like the government to track I mean what do you want to do?" << endl;
		cout << "Make A Note | Get Tagged Notes | Get All Notes (1/2/3)" << endl;
		cin >> usrChoice; //gets what the user wants to do
		cout << "\n";
		switch (usrChoice) //switch statement for the different options
		{
		case 1: //make a note choice
			usrWriteLine();
			break;
		case 2: //get tagged note choice
			searchFile();
			break;
		case 3: //get all notes choice
			readFile();
			break;
		default:
			break;
		}
		cout << "Would you like to do anything else? (y/n)" << endl;
		getline(cin >> ws, contChoice); //gets if the user wants to keep using the Government spy device
		cout << "\n";
	}
}