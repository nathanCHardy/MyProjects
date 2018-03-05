#include<fstream>
#include<string>
#include<iostream>
#include<conio.h>
#include<thread>
#include "Utility.h"
#include "StorySync.h"
using namespace std;
//varibles, pointers, external, etc....
extern string fileName;
char **s = 0;
char stuff;
int col = 1;
int row = 1;
int rowx1, rowx2, rowx3;
int coly1, coly2, coly3;
int level = 1;
int deathNote;
int *deathptr = &deathNote;
int* Rptr = nullptr;
int* Cptr = nullptr;
int* levptr = &level;
int* x1ptr = &rowx1;
int* x2ptr = &rowx2;
int* x3ptr = &rowx3;
int* y1ptr = &coly1;
int* y2ptr = &coly2;
int* y3ptr = &coly3;
bool myExit = true;
bool Pmove = false;
bool level1 = false;
bool level2 = true;
bool level3 = true;
bool* lev1ptr = &level1;
bool* lev2ptr = &level2;
bool* lev3ptr = &level3;
bool* mptr = &Pmove;
//proto functions
void Gameloop();
int levelSize();
void levelFile();
void PlayAgain();
void GameOver();
void trapsLocation();
void RandomDeathNote();
void LevelComplete();
void Menu();
void Controls();
//function that dynamically allocates an array
void arraySizer(char** , int size)
{
	s = new char *[size];
	for (int i = 0; i < size; i++)
	s[i] = new char[size];
}
//delete dynamic array
void ReleaseDynamicMem(char **, int size)
{
	for (int i = 0; i < size; i++)
		delete[] s[i];
	delete[] s;
}
//open, read, and populate array
void ReadandPop(char**, string fileName, int size)
{
	ifstream inFile(fileName);
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		inFile >> s[y][x];
	}
}
//display array contents
void Display(char**, int size)
{
	//clear the screen
	clear();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}
//function that simulates character moving, and other functionality
void GameMovement()
{
	//holds the character
	char m = '0';
	//gets the address of the column and row variables
	Cptr = &col;
	Rptr = &row;
	//call to game over, checks for trap location
	GameOver();
	//waits for keyboard hits
		if (_kbhit())
		{
			//gets characters as unbuffered input, no enter key
			stuff = _getch();
			//will explain one, then the rest are the same
			//if the user enters 2, no enter key is needed
			if (stuff == '2')
			{
				//checks to see if the step is a 0 or exit gate ]
				if (s[row + 1][col] == '0' || s[row + 1][col] == ']')
				{
					//adds one to the row
					*Rptr += 1;
					//places the player * in the new tile
					s[row][col] = '*';
					//places the tile where the player was located
					s[row - 1][col] = m;
					//sets the player moved flag to true
					*mptr = true;
				}
			}
			//same as above
			else if (stuff == '8')
			{
				if (s[row - 1][col] == '0' || s[row - 1][col] == ']')
				{
						*Rptr -= 1;
						s[row][col] = '*';
						s[row + 1][col] = m;
						*mptr = true;
				}
			}
			//same as above, except the move to the exit
			else if (stuff == '6')
			{
				if (s[row][col + 1] == '0' || s[row][col + 1] == ']')
				{
					//checks if the exit is located
					if (s[row][col + 1] == ']')
					{
						//add one to the column
						*Cptr += 1;
						//places player on the exit
						s[row][col] = '*';
						//places tile where player was
						s[row][col - 1] = m;
						//calls levelcomplete function
						LevelComplete();
						//resets row and column
						*Rptr = 1;
						*Cptr = 1;
						//calls game loop to start new level
						Gameloop();
						*mptr = true;
					}
					else
					{
						*Cptr += 1;
						s[row][col] = '*';
						s[row][col - 1] = m;
						*mptr = true;
					}
				}
			}
			else if (stuff == '4')
			{
				if (s[row][col - 1] == '0' || s[row][col - 1] == ']')
				{
					*Cptr -= 1;
					s[row][col] = '*';
					s[row][col + 1] = m;
					*mptr = true;
				}
			}
			else if (stuff == 'm')
			{
					//delete dynamic array
				ReleaseDynamicMem(s, levelSize());
				//reset level variable
				*levptr = 1;
				//flags for each level are reset
				*lev1ptr = false;
				*lev2ptr = true;
				*lev3ptr = true;
				//calls levelfile
				levelFile();
				//resizes array
				arraySizer(s, levelSize());
				//read and populate array
				ReadandPop(s, fileName, levelSize());
				//sets game loop variable to false
				myExit = false;
				//resets the tile you are one
				s[row][col] = m;
				//resets row and column
				*Rptr = 1;
				*Cptr = 1;
				//places player on starting tile
				s[1][1] = '*';
				//clears the screen
				ClearScreen();
				//return to menu
				Menu();
			}
	}
}
//menu function
void Menu()
{
	//clears the screen
	ClearScreen();
	//store menu choice of the user
	int choice = 0;
	//sets gameloop to true
	myExit = true;
	//loops until user chooses a valid choice
	while (choice <= 0 || choice > 3)
	{
		cout << "Welcome to \"Programers Path\"" << endl;
		cout << "1. Play game" << endl;
		cout << "2. Controls" << endl;
		cout << "3. Exit game" << endl;
		cin >> choice;
		//calls functions based on user choice
			if (choice == 1) 
			{
				thread t(Gameloop);
				t.join();
			}
			else if (choice == 2) Controls();
			else if (choice == 3)
			{
				myExit = false;
				break;
			}
			//validate user choice
			else if (choice <= 0 || choice > 3)
			{
				cout << "Invalid option" << endl;
				system("pause");
				//flush stream
				cin.clear();
				fflush(stdin);
				Menu();
			}
			return;
	}
}
//game control function
void Controls()
{
	ClearScreen();
	cout << "4 is left, 6 is right, 8 is up, 2 is down." << endl;
	cout << "Press 'm' while in-game resets game and returns to main menu." << endl;
	system("pause");
	Menu();
}
//main game loop function
void Gameloop()
{
	//checks and resizes array for each level
	if (level >= 2 && level <= 3)
	{
		//call levelfile function for level file name
		levelFile();
		//resize array
		arraySizer(s, levelSize());
		//read and populate array
		ReadandPop(s, fileName, levelSize());
	}
	//if you finish the game
	else if (level >= 4)
	{
		//call end game function
		endGame();
		return;
	}
	//populates tiles with traps to avoid or die trying
	thread trap(trapsLocation);
	trap.join();
	//clear screen
	ClearScreen();
	//start the story appropriate for each level
	StoryStart();
	//clear screen again
	ClearScreen();
	//display level grid
	Display(s, levelSize());
	while (myExit == true)
	{
		//if the player move flag is true, display the changes
		if (Pmove == true)
		{
			Display(s, levelSize());
			//reset player move to false
			*mptr = false;
		}
		//multithread game movement function
		thread t(GameMovement);
		//rejoins thread to main thread
		t.join();
	}
}
//return value based on the level you are on, which is used as array size
int levelSize()
{
	if (level1 == false)
	{
		return 30;
	}
	else if (level2 == false)
	{
		return 24;
	}
	else if (level3 == false)
	{
		return 12;
	}
	return 0;
}
//returns file name based on the level you are on
void levelFile()
{
	string* lptr = nullptr;
	lptr = &fileName;
	if (level1 == false)
	{
		*lptr = "level3.txt";
	}
	else if (level2 == false)
	{
		*lptr = "level2.txt";
	}
	else if (level3 == false)
	{
		*lptr = "level1.txt";
	}
}
//what to do on level completion
void LevelComplete()
{
	//free dynamic allocated memory
		ReleaseDynamicMem(s, levelSize());
		//add one to the level counter
		*levptr += 1;
		//resets level flags based on level completed
	if (level == 2)
	{
		*lev1ptr = true;
		*lev2ptr = false;
	}
	else if (level == 3)
	{
		*lev2ptr = true;
		*lev3ptr = false;
	}
}
//random placement of traps
void trapsLocation()
{
	//random garbage
	unsigned seed = time(0);
	const int MIN_VALUE = 1;
	const int MAX_VALUE = levelSize() - 2;
	srand(seed);
	//sets traps location of the grid
	*x1ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	*x2ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	*x3ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	*y1ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	*y2ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	*y3ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	//traps in a wall only work for ghosts.........
	while (s[rowx1][coly1] != '0'  || s[rowx2][coly2] != '0' || s[rowx3][coly3] != '0')
	{
		*x1ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		*x2ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		*x3ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		*y1ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		*y2ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		*y3ptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}
}
//you died, what a bummer
void GameOver()
{
	//if you encounter a trap location
	if (row == rowx1 && col == coly1 || row == rowx2 && col == coly2 || row == rowx3 && col == coly3)
	{
		//release memory
		ReleaseDynamicMem(s, levelSize());
		//set level counter to 1
		*levptr = 1;
		//gets file name
		//resets level flags to default
		*lev1ptr = false;
		*lev2ptr = true;
		*lev3ptr = true;
		levelFile();
		//resets columns and rows, ie player position
		*Rptr = 1;
		*Cptr = 1;
		//resize array
		arraySizer(s, levelSize());
		//populate array and read file
		ReadandPop(s, fileName, levelSize());
		//clear the screen
		ClearScreen();
		//sets exit flag
		myExit = false;
		//tells you that you died
		RandomDeathNote();
		
		//calls menu
		//Menu();
	}
}
//display a random humerous note on your death
void RandomDeathNote()
{
	unsigned seed = time(0);
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 5;
	srand(seed);
	*deathptr = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	if (deathNote == 1)
	{
		cout << "You stepped on a rusty byte and died, sorry" << endl;
		PlayAgain();
		
	}
	else if (deathNote == 2)
	{
		cout << "You fell into a memory leak, oops" << endl;
		PlayAgain();
	}
	else if (deathNote == 3)
	{
		cout << "You are now part of a dynamic array, that sucks" << endl;
		PlayAgain();
	}
	else if (deathNote == 4)
	{
		cout << "You are trapped in an infinite loop...." << endl;
		PlayAgain();
	}
	else if (deathNote == 5)
	{
		cout << "Critical system error in creating death comment" << endl;
		PlayAgain();
	}
}
//play again function
void PlayAgain()
{
	char YesOrNo = ' ';
	while (YesOrNo != 'y' || YesOrNo != 'Y' || YesOrNo != 'n' || YesOrNo != 'N')
	{
		cout<<"Play again y/n"<<endl;
	    cin>>YesOrNo;
		if (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			Menu();
			break;
		}
		else if (YesOrNo == 'n' || YesOrNo == 'N')
		{
			return;
		}
		ClearScreen();
	}
}