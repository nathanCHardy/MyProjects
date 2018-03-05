#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//structure
struct bins
{
	string partName;
	int partStock;
};
//array of structures
bins pBins[10];
//proto functions
void Bmenu(bins b[]);
void addParts(bins p[], int);
void directFlow(int);
void removeParts(bins p[], int);
int main()
{
	//stream reader object, opening text file "parts.txt"
	ifstream inputFile("parts.txt");
	//temp container for numeric values
	string temp;
	//read file into structure array
	if (inputFile)
	{
		for (int i = 0; i < 10; i++)
		{
			//read whole line of file
			getline(inputFile, pBins[i].partName);
			getline(inputFile, temp);
			//convert stock from string to integer
			pBins[i].partStock = atoi(temp.c_str());
		}
	}
	else cout << "File not found" << endl;
	inputFile.close();
	//call to menu function
	Bmenu(pBins);
	return 0;
}
//menu function 
void Bmenu(bins p[])
{
	//user menu choice
	int uChoice = 0;
	//main menu loop
	while (uChoice != 11)
	{
		//display array as menu items
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << ". " << p[i].partName << "- in stock-" << p[i].partStock << endl;
		}
		//exit function
		cout << "11. Exit" << endl;
		//what I want you to do
		cout << "Choose bin to modify" << endl;
		//gets your choice of menu items
		cin >> uChoice;
		//if menu item is not exit, call direct flow function
		if (uChoice >= 1 && uChoice <= 10) directFlow(uChoice);
		//clear screen
		system("cls");
	}
	ofstream outFile("parts.txt");
	for (int i = 0; i < 10; i++)
	{
		outFile << p[i].partName << endl;
		outFile << p[i].partStock << endl;
	}
	outFile.close();
	cout << "Inventory updated" << endl;
	return;
}
//gives user choice of add or delete items 
void directFlow(int Uchoice)
{
	//menu choice
	int addRem;
	//display menu
	cout << "1. Add parts to bin" << endl;
	cout << "2. Remove parts from bin" << endl;
	//gets your choice
	cin >> addRem;
	//calls addParts if you choose 1
	if (addRem == 1) addParts(pBins, Uchoice);
	//otherwise removeParts if 2 is chosen
	else if (addRem == 2) removeParts(pBins, Uchoice);
}
//function to add parts to the bins
void addParts(bins p[], int ch)
{
	//pointer variable
	bins* bPtr = nullptr;
	//holds user variable
	int parts = 0;
	//menu item minus one for array values
	ch = ch - 1;
	//put address of chosen structure array into pointer variable
	bPtr = &p[ch];
	//asks user how much to mod bin
	cout << "Add how many " << p[ch].partName <<"(s)" << endl;
	cin >> parts;
	//validatation for positive numbers
	if (parts > 0)
	{
		//validatation for bin limit of 30 units
		if (parts + p[ch].partStock <= 30)
		{
			//bin modified message
			cout << parts << " " <<p[ch].partName  << "(s) ordered" << endl;
			//change stock value by using structure pointer
			bPtr->partStock += parts;
		}
		//bin only holds so much message
		else
		{
			cout << "Bin can only hold 30 pieces, check inventory first" << endl;
		}
	}
	//enter a positive value, really
	else cout << "Enter positive values" << endl;
	system("pause");
}
//same as above but subtract parts
void removeParts(bins p[], int ch)
{
	bins* bPtr = nullptr;
	int parts = 0;
	ch = ch - 1;
	bPtr = &p[ch];
	cout << "Take out how many " << p[ch].partName <<"(s)" << endl;
	cin >> parts;
	if (parts > 0)
	{
		//validatation to ensure value does not exceed in stock value
		if (parts <= p[ch].partStock)
		{
			cout << parts << " " << p[ch].partName << "(s) taken out" << endl;
			bPtr->partStock -= parts;
		}
		//if you do take more than you need
		else
		{
			cout << "Exceeds number in stock, check inventory first" << endl;
		}
	}
	else cout << "Enter positive values" << endl;
	system("pause");
}
