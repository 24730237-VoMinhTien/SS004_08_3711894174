#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

void gotoxy(int column, int line);

class CONRAN
{
private:
    struct Point
    {
        int x, y;
    };

    struct Ran
    {
        Point body[100];
        int length;
    };

    Ran ran;
    int score;
    Point food;

public:
    CONRAN()
    {
        ran.length = 1;
        score = 0;
    }
    void Menu();
};

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}

int main()
{
    CONRAN app;
    app.Menu();
    return 0;
}

void CONRAN::Menu()
{
    do
    {
        system("cls");
        cout << "Menu\n";
        cout << "1. Bat Dau\n";
        cout << "2. Thong Tin\n";
        cout << "3. Thoat\n";

        char choice = _getch();
        switch (choice)
        {
        case '1':

        case '2':

        case '3':
        }
    } while (true);
}