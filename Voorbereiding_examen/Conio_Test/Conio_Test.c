#include <stdio.h>
#include <conio.h>      // for _kbhit(), _getch()
#include <windows.h>    // for Win32 console cursor functions

void gotoxy(int x, int y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clrscr()
{
    DWORD n;
    DWORD size;
    COORD coord = { 0, 0 };
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(h, &info);
    size = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(h, ' ', size, coord, &n);
    FillConsoleOutputAttribute(h, info.wAttributes, size, coord, &n);
    SetConsoleCursorPosition(h, coord);
}

int main()
{
    int x = 10, y = 10;
    int ch;

    clrscr();

    printf("Move '@' with arrow keys.\nPress Q to quit.\n");

    gotoxy(x, y);
    putchar('@');

    while (1)
    {
        if (_kbhit())
        {
            ch = _getch();

            gotoxy(x, y);
            putchar(' ');   // erase old char

            if (ch == 0 || ch == 224) // arrow prefix
            {
                ch = _getch();
                switch (ch)
                {
                case 72: y--; break; // up
                case 80: y++; break; // down
                case 75: x--; break; // left
                case 77: x++; break; // right
                }
            }
            else if (ch == 'q' || ch == 'Q')
                break;

            gotoxy(x, y);
            putchar('@');
        }
    }

    return 0;
}
