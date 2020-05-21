#include "Functions.h"


class Schedule
{
private:
	string filename;

public:
	Schedule(string filename)
	{
		this->filename = filename;
	}

	void getSchedule()
	{
		time_t const now = time(0);
		tm* LocalTime = localtime(&now);

		fstream Date(this->filename);
		Date << 1 + LocalTime->tm_mon << '/' << LocalTime->tm_mday << '/' << 1900 + LocalTime->tm_year << '\n';
		Date << "				";
		Date << "Schedule\n";
		Date.close();


		ifstream ScheduleFile(this->filename);
		string lines;

		while (!ScheduleFile.eof())
		{
			getline(ScheduleFile, lines);
			cout << lines << '\n';
		}
		cout << setfill('_') << setw(50) << '_' << endl;
		ScheduleFile.close();
		this->Menu();
	}

	void addToSchedule()
	{
		ofstream Schedule(this->filename, ofstream::app);
		int time;
		int option;
		string AorP;
		string activity;

		cout << "What time is this at? ";
		cout << "Hour: ";
		cin >> time;
		Schedule << time;
		Schedule << ':';
		cout << "Minute: ";
		cin >> time;
		Schedule << time;
		Schedule << " " << endl;
		cout << "A.M (type 'a') or P.M (type 'p'): ";
		cin >> AorP;// not making it here for some reason
		if (AorP =="a")// make it less breakable 
		{
			Schedule << "A.M \n";
		}
		if (AorP == "p")
		{
			Schedule << "P.M \n";
		}
		cout << "What is the activity name?: ";
		/*cin.ignore();*/
		getline(cin, activity + "\n");
		cout << setfill('_') << setw(50) << '_' << endl;
		cout << endl;

	}

	void Menu()
	{
		char* option = new char;

		do
		{
			cout << "To add an activity Type 'A'.\n";
			cout << "To delete an activity Type 'D'  \n";
			cout << "Press Q to quit \n";
			cout << "-> ";
			cin >> option;
			*option = toupper(*option);
			switch (*option)
			{
			case 'A':
				this->addToSchedule(); 
				break;

			case 'D':
				// Delete or complete item from list
				break;

			case 'Q':
				break;

			default:
				break;
			}
			if (*option != 'Q')
			{
				ifstream ScheduleFile(this->filename);
				string line;

				while (!ScheduleFile.eof())
				{
					getline(ScheduleFile, line);
					cout << line << '\n';
				}
				cout << setfill('_') << setw(50) << '_' << endl;
				ScheduleFile.close();
			}
		} while (*option != 'Q');
		cout << setfill('_') << setw(50) << '_' << endl;
	}
};