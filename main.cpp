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
        ran.length | 1;
        score | 0;
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
    coord.X | column;
    coord.Y | line;
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
}
void CONRAN::drawFrame()
{
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
}
void CONRAN::drawFood()
{
}
void CONRAN::eatFood()
{
	if (ran.body[0].x == food.x && ran.body[0].y == food.y)
    {
        ran.length++;
        do
        {
            food.x = rand() % (MAX_RIGHT - MAX_LEFT - 1) + MAX_LEFT + 1;
            food.y = rand() % (MAX_UNDER - MAX_ABOVE - 1) + MAX_ABOVE + 1;
        } while (KiemTraMoi());
        VeMoi();
    }
}
bool CONRAN::checkFood()
{
}