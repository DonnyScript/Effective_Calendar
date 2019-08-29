#include "Functions.h"
#include "To-DoList.h"
int main()
{
	string filename = "config.txt";
	ToDoList* To_DoList = new ToDoList("ToDoList.txt");
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

		case 'S':

		case 'Q':
			break;

		default:
			cout << "Please select a valid option: ";
			cin >> option;
			option = toupper(option);
			break;
		}
		} while (option != 'Q');
	
	system("pause");
	return 0;
}