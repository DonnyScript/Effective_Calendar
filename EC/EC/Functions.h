#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void setupCheck(string filename)
{
	ifstream configFile(filename);
	if (!configFile.is_open())
	{
		cout << "		First time setup starting!" << '\n';
		ofstream myfile(filename);
		myfile << "Y ";
		cout << "What is your name: ";
		string* name = new string;
		cin >> *name;
		myfile << *name;
	}
	else if (configFile.is_open())
	{
		char* setupStatus = new char;
		configFile >> setupStatus;
		if (*setupStatus != 'Y')
		{
			ofstream myfile(filename);
			myfile << "Y ";
			cout << "What is your name: ";
			string* name = new string;
			cin >> *name;
			myfile << *name;
			return;
		}

	}
}

void WelcomeMessage(string filename)
{
	string name;
	string Message = "Welcome";
	ifstream configFile(filename);
	configFile >> name;
	getline(configFile, name);
	cout << setfill('-') << setw(name.size() + Message.size() + 3) << "-" << endl;
	cout << "| "<< Message << name << '|' << '\n';
	cout << setfill('-') << setw(name.size() + Message.size() + 3) << "-" <<endl;


}




#endif

