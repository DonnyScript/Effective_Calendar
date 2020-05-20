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
		Date << "To-Do List\n";
		Date.close();


		ifstream ToDoList(this->filename);
		string line;

		while (!ToDoList.eof())
		{
			getline(ToDoList, line);
			cout << line << '\n';
		}
		cout << setfill('_') << setw(50) << '_' << endl;
		ToDoList.close();
		this->Menu();


	}
};