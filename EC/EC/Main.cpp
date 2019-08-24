#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Setup(string filename)// Tun this into member function

{

	char isSetup;

	ifstream SetupConfig(filename);

	while (!SetupConfig.eof())
	{
		SetupConfig >> isSetup;
		cout << isSetup << '\n';
	}

}


int main()
{
	string filename;
	char firstChar;
	cout << "Enter file name: "; cin >> filename;
	filename += ".txt";


	ofstream myfile(filename);
	myfile << "Writing this to a file.\n";
	myfile << "000" << filename;
	myfile.close();

	ifstream inFile(filename);
	inFile >> firstChar;
	cout << firstChar << '\n';
	inFile.close();

	return 0;
}