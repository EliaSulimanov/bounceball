#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

HANDLE hStdout;
CONSOLE_SCREEN_BUFFER_INFO consbi;
CONSOLE_CURSOR_INFO conci;
DWORD bytsWritten;

void delay(int milli);

/**
 * Bounce ball program.
 * Writen for Windows 10 console.
 * @return 0 on exit
 */
int main() {
    const int SCREEN_WIDTH = 45, SCREEN_HEIGHT = 20;
    int xpos = 5, ypos = 13, xspeed = 1, yspeed = 1, xnew, ynew, stoper = 1;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    conci.bVisible = FALSE;
    conci.dwSize = 1;
    SetConsoleCursorInfo(hStdout, &conci);

    system("cls");
    while (stoper)
    {
        xnew = xpos + xspeed;
        ynew = ypos + yspeed;
        if(xnew >= SCREEN_WIDTH || xnew <= 0)
            xspeed = -xspeed;
        if(ynew >= SCREEN_HEIGHT || ynew <= 0)
            yspeed = -yspeed;

        consbi.dwCursorPosition.X = xpos;
        consbi.dwCursorPosition.Y = ypos;
        SetConsoleCursorPosition(hStdout, consbi.dwCursorPosition);
        WriteConsole(hStdout, " ", 1, &bytsWritten, NULL);

        consbi.dwCursorPosition.X = xnew;
        consbi.dwCursorPosition.Y = ynew;
        SetConsoleCursorPosition(hStdout, consbi.dwCursorPosition);
        WriteConsole(hStdout, "*", 1, &bytsWritten, NULL);

        xpos = xnew;
        ypos = ynew;

        delay(200);
    }
    return 0;
}

void delay(int milli)
{
    clock_t clock_start = clock();
    while (clock() < clock_start + milli);
}