#include "Functions.h"
#include "To-DoList.h"
int main()
{
	string filename = "config.txt";
	ToDoList* To_DoList = new ToDoList("ToDoList.txt");
	setupCheck(filename);
	WelcomeMessage(filename);
	char* option = new char;
	firstMenu(option);


	switch (*option)
	{

	case 'T':
		To_DoList->getToDoList();
		break;

	case 'S':




	default: 
		cout << "Please select a valid option.\n";
		break;
	}

	
	system("pause");
	return 0;
}