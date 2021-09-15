#pragma warning(disable : 4996)
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>

#include "functions.h"

using namespace std;

void usrWriteLine()  //Creates file if it doesnt exist and allows user to make entry
{
	ofstream GovernmentSpyDevice("GovernmentSpyDevice.txt", ios::app); //appends at the end of the file
	string msg;
	string msgType;
	int usrWriteTypeChoice;
	cout << "Choose Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrWriteTypeChoice; //users choice
	cout << "\n";
	time_t timetoday; //make time_t object
	time(&timetoday); //getting the time
	string currentTime = asctime(localtime(&timetoday)); //formats the time
	string usrstr;

	switch (usrWriteTypeChoice) //switch statement for the different options for functionality
	{
	case 1: //reminder case
		cout << "What do you want the government to remember?" << endl;
		getline(cin >> ws, usrstr); //entry
		msg = "REMINDER: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 2: //message case
		cout << "What do you want to tell the government?" << endl;
		getline(cin >> ws, usrstr); //entry
		msg = "MESSAGE: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 3: //schedule case
		cout << "Please set a time to meet with the government." << endl;
		getline(cin >> ws, usrstr); //entry
		msg = "SCHEDULE: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	case 4: //alarm case
		cout << "When would you like the government to alert you?" << endl;
		getline(cin >> ws, usrstr); //entry
		msg = "ALARM: " + usrstr + " -" + currentTime;
		GovernmentSpyDevice << msg << endl;
		break;
	default:
		break;
	}

	cout << "\nSAVED- " + msg << endl;
}

void searchFile() //searching for a tag
{
	ifstream GovernmentSpyDeviceRead("GovernmentSpyDevice.txt");
	int usrTypeChoice;
	cout << "What type of item would you like to search?" << endl;
	cout << "Reminder, Message, Schedule, or Alarm. (1/2/3/4)" << endl;
	cin >> usrTypeChoice;
	cout << "\n";
	string type;
	switch (usrTypeChoice) //switch statement to find the specific tag the user chose
	{
	case 1: //reminder tag
		type = "REMINDER:";
		cout << "This is what the goverment remembers you said." << endl;
		break;
	case 2: //message tag
		type = "MESSAGE:";
		cout << "The government told me to tell you:" << endl;
		break;
	case 3: //schedule tag
		type = "SCHEDULE:";
		cout << "The government always knows what youre doing at all times!" << endl;
		break;
	case 4: //alarm tag
		type = "ALARM:";
		cout << "The government is telling you its time!:" << endl;
		break;
	default:
		break;
	}

	string line;
	while (getline(GovernmentSpyDeviceRead, line)) //searches through the files line by line
	{
		if (line.find(type) != string::npos) { //if type exist in line then print line
			cout << line << endl;
			cout << "\n";
		}
	}
	cout << "\n";
}

void readFile() //read entire file
{
	ifstream GovernmentSpyDeviceRead("GovernmentSpyDevice.txt");
	string line;
	while (getline(GovernmentSpyDeviceRead, line)) { //printing line by line of the file
		cout << line << endl;
	}
}