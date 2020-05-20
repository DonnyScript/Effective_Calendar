#include "Functions.h"
#include "To-DoList.h"
#include "Schedule.h"
int main()
{
	string filename = "config.txt";
	ToDoList* To_DoList = new ToDoList("ToDoList.txt");
	Schedule* schedule = new Schedule("Schedule.txt");
	setupCheck(filename);
	WelcomeMessage(filename);
	char option;

	do {
		firstMenu(option);
		switch (option)
		{

		case 'T':
			To_DoList->getToDoList();
			break;

		case 'S':// Make new class or .h file and code schedule
			schedule->getSchedule();
			break;

		case 'Q':
			break;

		default:
			cout << "Please select a valid option: ";
			cin >> option;
			option = toupper(option);
			break;
		}
		} while (option != 'Q');
	
	return 0;
}