#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

void setupCheck(string filename)
{
	ifstream configFile(filename);
	if (!configFile.is_open())
	{
		cout << setfill('-') << setw(35) << "First time setup starting!" << '\n';
		ofstream myfile(filename);
		myfile << "Y ";
		cout << "What is your name: ";
		string* name = new string;
		getline(cin, *name);
		myfile << *name;
		configFile.close();
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
			myfile.close();
			return;
		}
	}
	ifstream ToDo("ToDoList.txt");
	if (!ToDo.is_open())
	{
		cout << "Creating To-Do List File \n";
		ofstream input("ToDoList.txt");
	}
}

void WelcomeMessage(string filename)
{
	string name;
	string Message = "Welcome";
	ifstream configFile(filename);
	configFile >> name;
	getline(configFile, name);
	name += ' ';
	cout << "								      ";
	cout << setfill('-') << setw(name.size() + Message.size() + 3) << "-" << endl;
	cout << "								      ";
	cout << "| "<< Message << name << '|' << '\n';
	cout << "								      ";
	cout << setfill('-') << setw(name.size() + Message.size() + 3) << "-" <<endl;
}

void firstMenu(char& option)
{

	cout << "Would you like to see your to-do list?( Type 'T')" << endl;
	cout << "Would you like to see todays schedule?( Type 'S' ) " << endl;
	cout << "Would you like to see the current month?( Type 'M') " << endl;
	cout << "Press Q to quit" << endl;
	cout << "-> ";
	cin >> option;
	option = toupper(option);
}

#endif

