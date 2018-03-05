#include<iostream>
#include<windows.h>
#include<stdexcept>
#include<stdlib.h>
#include<string>
using namespace std;
//function to reset cursor position on the screen, thereby allowing a redraw of the array contents to look more natural
void clear() {
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

}
//resets screen
void ClearScreen() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
//function to validate user input
bool Validate(int s)
{
	if (s >= 0 && s <= 9)
	{
		return true;
	}
	else return false;
}
