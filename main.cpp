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

    void VeRan();
};

int main()
{
    CONRAN ran;
    ran.TaoRan();
    ran.VeRan();
    return 0;
}

//Tạo ra con rắn tại vị trí xy
void CONRAN::TaoRan()
{
    int x_head = 50;
    int y_head = 10;
    for (int i = 0; i < ran.length; i++)
    {
        ran.body[i].x = x_head--;
        ran.body[i].y = y_head;
    }
}

//Cho hình dạng khởi đầy của con rắn
void CONRAN::VeRan()
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
                cout << (char)186;  //thân dọc
            }
            else if (ran.body[i].y == ran.body[i - 1].y)
            {
                cout << (char)205;  //Thân ngang
            }
            else
            {
                cout << (char)177;  //Thân chung
            }
        }
        SetColor(7); // Quay lại màu mặc định
    }
}



