#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <thread>
#define MAX_RIGHT 104
#define MAX_LEFT 10
#define MAX_ABOVE 1
#define MAX_UNDER 25

void gotoxy(int column, int line); // Hàm goto
using namespace std;

// Hàm thiết lập màu sắc
void SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Hàm tọa độ xy
void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}

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
        int length; // Độ dài rắn
    };

    Ran ran;
    int score;
    Point food;

public:
    CONRAN()
    { // Hàm khởi tạo giá trị ban đầu
        ran.length = 3;
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

int main()
{
    CONRAN app;
    app.menu();
    return 0;
}

void CONRAN::menu()
{
    char choice;
    do
    {
        system("cls");
        cout << "MENU\n";
        cout << "1. Bat Dau\n";
        cout << "2. Thong Tin\n";
        cout << "3. Thoat\n";
        cout << "Lua chon: ";
        choice = _getch();

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
        default:
            cout << "Khong hop le, vui long chon lai.\n";
            _getch();
            break;
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
    int x_head = 50;
    int y_head = 10;
    for (int i = 0; i < ran.length; i++)
    {
        ran.body[i].x = x_head--;
        ran.body[i].y = y_head;
    }
}

void CONRAN::drawSnake()
{
    for (int i = 0; i < ran.length; i++)
    {
        gotoxy(ran.body[i].x, ran.body[i].y);
        if (i == 0)
        {
            SetColor(12); // Màu đỏ cho đầu rắn
            cout << (char)254;
        }
        else
        {
            SetColor(10); // Màu xanh lá cho thân
            if (ran.body[i].x == ran.body[i - 1].x)
            {
                cout << (char)186; // thân dọc
            }
            else if (ran.body[i].y == ran.body[i - 1].y)
            {
                cout << (char)205; // Thân ngang
            }
            else
            {
                cout << (char)177; // Thân chung
            }
        }
        SetColor(7); // Quay lại màu mặc định
    }
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
    return false;
}
