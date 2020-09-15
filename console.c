#include <windows.h>
#include "console.h"

void set_window(int width, int height) {
    /// codigo original: http://www.mediafire.com/file/pc1l6l3v9sij75x/C+++console+game.zip
    COORD coord;
    coord.X = width;
    coord.Y = height;

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = height - 1;
    Rect.Right = width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void set_background_color(int color) {
    /// codigo original: http://tapiov.net/rlutil/
    #if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(hConsole, &csbi);

        SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)color) << 4)); // Background colors take up the second-least significant byte
    #else
        RLUTIL_PRINT(getANSIBackgroundColor(color));
    #endif
}

void set_color(int color) {
    /// codigo original: Fonte: https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks
    WORD wColor;
    //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void hide_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
