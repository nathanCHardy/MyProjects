#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
//created header files
#include "GameMech.h"
#include "StorySync.h"
#include "Utility.h"
using namespace std;
//external variables
extern char **s;
extern bool level1;
extern bool level2;
extern bool level3;
//name of the file, which in turn contains level information
string fileName;

int main()
{
	//set window size
	HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 800, 500, TRUE); // 800 width, 100 height

	//calls the levelFile function, which puts the file name based on level into filename variable
    levelFile();
	//dynamically sizes array
	arraySizer(s, levelSize());
	//function to read file and populate array 
	ReadandPop(s, fileName, levelSize());
	//calls the menu function
	Menu();
	return 0;
}