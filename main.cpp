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
    ran.VeRan();
    return 0;
}

void CONRAN::VeRan()
{
    for (int i = 0; i < ran.length; i++)
    {
        gotoxy(ran.body[i].x, ran.body[i].y);
        if (i == 0)
        {
            cout << (char)254;
        }
        else
        {
            if (ran.body[i].x == ran.body[i - 1].x)
            {
                cout << (char)186;             }
            else if (ran.body[i].y == ran.body[i - 1].y)
            {
                cout << (char)205;             }
            else
            {
                cout << (char)177;             }
        }
    }
}



