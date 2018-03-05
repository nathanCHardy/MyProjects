#include<iostream>
#include<string>
#include<Windows.h>
//I made this header, cool
#include "Utility.h"
using namespace std;
//external variables, ie variables present in another c++ file
extern bool level1;
extern bool level2;
extern bool level3;
extern bool myExit;
//function to display story info by way of level
void StoryStart()
{
	if (level1 == false)
	{
		//clear and flush the stream
		cin.clear();
		fflush(stdin);
		cout<< "You are one of the few and proud, a novice programmer"<<endl;
		cout<< "Everyday you type away at your keyboard," <<endl; 
		cout<<"a dark force watched you from the shadows" <<endl;
		cout<< "An evil force living inside your computer grew to hate you and all your kind"<<endl;
		system("pause");
		cout<<"One day the evil force gathered it's power to strike back at you"<<endl;
		cout<< "A mystic portal opens inside of your monitor and sucks you inside"<<endl;
		cout << "You feel a strange sense of distortion and pass out"<<endl;
		system("pause");
		cout<< "You awake to find yourself wearing an asterisk suit"<<endl;
		cout<<"with a note pinned on your chest"<<endl;
		cout<< "You read the note to yourself as follows"<<endl;
		system("pause");
		cout<< "I am the Dark Lord Vectormort, and I have trapped you inside my dungeon of doom"<<endl;
		cout<<"You must face three levels to find you way home safely" <<endl;
		cout<<"Use the numbers 2, 4, 6, 8 to navigate and find the exit ]"<<endl;
		cout<<"But beware invisible traps placed in each level"<<endl;
		system("pause");
		
	}
	//level 2 story
	else if (level2 == false)
	{
		cout<<"You find another note placed on the wall of the new level"<<endl;
		cout << "Welcome to level 2" << endl;
		cout<<"Smaller in size, bigger in danger foolish programmer"<<endl;
		system("pause");
	}
	//level 3 story
	else if (level3 == false)
	{
		cout<<"Again another note in the same hand"<<endl;
		cout << "Small dungeon, big danger, have a nice day on level 3" <<endl;
		system("pause");
	}
}
//finish the game and see the ending storyline
void endGame()
{
	ClearScreen();
	cout << "Congrats, your programming skills have led you" << endl;
	cout << "to victory over the Dark Lord" << endl;
	system("pause");
	cout << "The mystic portal opens and you once again feel" << endl;
	cout << "the a strange feeling of distortion" << endl;
	system("pause");
	cout << "When you regain your senses you find yourself at your" << endl;
	cout << "desk, as if nothing at all occured" << endl;
	system("pause");
	cout << "Did that really happen, or was it a dream" << endl;
	cout << "Then again, maybe you should not watch Youtube and eat curry at the same time" << endl;
	cout << "Thanks for playing, bye....." << endl;
	system("pause");
	myExit = false;
}