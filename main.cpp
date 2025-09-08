#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

#define MAX_RIGHT 104
#define MAX_LEFT 10
#define MAX_ABOVE 1
#define MAX_UNDER 25

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

    void start();
    void drawFrame();
    void createSnake();
    void drawSnake();
    void move(int x, int y);
    bool isGameOver();
    void drawFood();
    void eatFood();
    bool checkFood();

    void menu();
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
    app.menu();
    return 0;
}

void CONRAN::menu()
{
    do
    {
        system("cls");
        cout << "MENU\n";
        cout << "1. Bat Dau\n";
        cout << "2. Thong Tin\n";
        cout << "3. Thoat\n";

        char choice = _getch();
        switch (choice)
        {
        case '1':
            start();
            break;
        case '2':
            cout << "============================================================================" << endl;
            cout << "|                                                                          |" << endl;
            cout << "|                              HUONG DAN                                   |" << endl;
            cout << "|                                                                          |" << endl;
            cout << "============================================================================" << endl;
            cout << "|  Dieu khien ran:                                                         |" << endl;
            cout << "|  - Su dung phim mui ten hoac AWSD de dieu khien ran an moi.              |" << endl;
            cout << "============================================================================" << endl;
            cout << "|  Nhom 9:                                                                 |" << endl;
            cout << "|  Le Duc Anh            - 24730174                                        |" << endl;
            cout << "|  Nguyen Thi Chau Giang - 24730189                                        |" << endl;
            cout << "|  Nguyen Phu Nam        - 24730211                                        |" << endl;
            cout << "|  Vo Minh Tien          - 24730237                                        |" << endl;
            cout << "============================================================================" << endl;
            cout << "|                     Nhan phim bat ky de tro ve menu.                     |" << endl;
            cout << "============================================================================" << endl;
            _getch();
            break;
        case '3':
            cout << "Thoat khoi chuong trinh.";
            return;
            _getch();
            break;
        default:
            cout << "Khong hop le, vui long chon lai.\n";
            break;
            _getch();
        }
    } while (true);
}

void CONRAN::start()
{
    system("cls");
    drawFrame();
}
void CONRAN::drawFrame()
{
    for (int i = MAX_LEFT; i <= MAX_RIGHT; i++)
    {
        gotoxy(i, MAX_ABOVE);
        cout << (char)220;
        gotoxy(i, MAX_UNDER + 1);
        cout << (char)223;
    }
    for (int i = MAX_ABOVE + 1; i <= MAX_UNDER; i++)
    {
        gotoxy(MAX_LEFT, i);
        cout << (char)221;
        gotoxy(MAX_RIGHT, i);
        cout << (char)222;
    }
}
void CONRAN::createSnake()
{
}
void CONRAN::drawSnake()
{
}
void CONRAN::move(int x, int y)
{
}
bool CONRAN::isGameOver()
{
    if (ran.body[0].x == MAX_LEFT || ran.body[0].x == MAX_RIGHT || ran.body[0].y == MAX_ABOVE || ran.body[0].y == MAX_UNDER)
        return true;

    for (int i = 1; i < ran.length; i++)
    {
        if (ran.body[i].x == ran.body[0].x && ran.body[i].y == ran.body[0].y)
            return true;
    }
    return false;
}
void CONRAN::drawFood()
{
}
void CONRAN::eatFood()
{
}
bool CONRAN::checkFood()
{
}