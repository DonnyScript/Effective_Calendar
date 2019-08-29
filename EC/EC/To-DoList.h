#include "Functions.h"

class ToDoList
{

private:
	string filename;

public: 
	ToDoList(string filename)
	{
		this->filename = filename;
	}


	void getToDoList()// Make script to print this
	{
		time_t const now = time(0);
		tm* LocalTime = localtime(&now);

		fstream Date(this->filename);
		Date << 1 + LocalTime->tm_mon << '/' << LocalTime->tm_mday << '/' << 1900 + LocalTime->tm_year << '\n';
		Date << "				";
		Date << "To-Do List\n";
		Date.close();

		ifstream ToDoList(this->filename);
		string line;

		while (!ToDoList.eof())
		{
			getline(ToDoList, line);
			cout << line << '\n';
			
		}
		ToDoList.close();
		this->Menu();

	}


	void addToList()
	{
		ofstream ToDoList(this->filename, ofstream::app);
		string addItem;
		int option;
		string find;

			cout << "Add the activity: ";
			cin.ignore();
			getline(cin, addItem);
			cout << "What Tier? (1,2,3): ";
			cin >> option;
			cout << endl;
			switch (option)
			{
				case 1:
					addItem = "-" + addItem;
					ToDoList << addItem << endl;
					ToDoList.close();
					break;

				case 2:
					addItem = "--" + addItem;
					ToDoList << addItem << endl;
					ToDoList.close();


				case 3:
					addItem = "---" + addItem;
					ToDoList << addItem << endl;
					ToDoList.close();

			default:
				break;
			}
	}

	void DeleteFromList()
	{
		int LineNum;
		cout << "What line number: ";
		cin >> LineNum;
		LineNum += 2;

		ifstream is("ToDoList.txt");

		ofstream ofs;
		ofs.open("temp.txt", ofstream::out);

		 
		char c;
		int line_no = 1;
		while (is.get(c))
		{
			 
			if (c == '\n')
			{
				line_no++;
			}

			
			if (line_no != LineNum)
			{
				ofs << c;
			}
		}

		 
		ofs.close();
		is.close();

		remove("ToDoList.txt");
		rename("temp.txt", "ToDoList.txt");
	}


	void Menu()
	{
		char* option = new char;

		do
		{
			cout << "Would you like to add your list?( Type 'A')\n";
			cout << "Would you like to delete?( Type 'D' ) \n";
			cout << "To quit Press Q \n";
			cin >> option;
			switch (*option)
			{
			case 'A':
				this->addToList();
				break;

			case 'D':
				this->DeleteFromList();
				break;

			case 'Q':
				break;

			default:
				break;
			}
			if (*option != 'Q')
			{
				ifstream ToDoList(this->filename);
				string line;

				while (!ToDoList.eof())
				{
					getline(ToDoList, line);
					cout << line << '\n';

				}
				ToDoList.close();
			}
		} while (*option != 'Q');
	}
};
