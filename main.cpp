#include <iostream>
#include <windows.h>
#include <conio.h>
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

//Hàm tọa đõ xy
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x - 1, y - 1};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
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

    void TaoRan();
    void VeRan();
    void DiChuyen(int x, int y);
    void testDiChuyen();
};

int main()
{
    CONRAN ran;
    ran.TaoRan();
    ran.VeRan();

    //Hàm test di chuyển
    ran.testDiChuyen();
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

//Điều hướng rắn
void getChar(int &huong)
{
    if (_kbhit())
    {
        char c = _getch();
        if (c == -32)
        { // Kiểm tra phím mũi tên
            c = _getch();
            if (c == 72 && huong != 0)
            {
                huong = 1;
            }
            else if (c == 80 && huong != 1)
            {
                huong = 0;
            }
            else if (c == 75 && huong != 2)
            {
                huong = 3;
            }
            else if (c == 77 && huong != 3)
            {
                huong = 2;
            }
        }
                else
        {
            if ((c == 'w') && huong != 0)
                huong = 1;
            else if ((c == 's') && huong != 1)
                huong = 0;
            else if ((c == 'a') && huong != 2)
                huong = 3;
            else if ((c == 'd') && huong != 3)
                huong = 2;
        }
    }
}

//Tách hàm di chuyển
void CONRAN::DiChuyen(int x, int y)
{
    //Thay đổi phần thân rắn
    // Lưu phần cuối của thân rắn để xóa sau khi di chuyển
    Point prevTail = ran.body[ran.length - 1];

    // Dời thân rắn từ cuối về phía trước
    for (int i = ran.length - 1; i > 0; i--)
    {
        ran.body[i] = ran.body[i - 1];
    }

    //Thay đổi phần đầu rắn
    // Cập nhật phần đầu rắn
    ran.body[0].x = x;
    ran.body[0].y = y;
}

void CONRAN::testDiChuyen()
{
    int x = ran.body[0].x;
    int y = ran.body[0].y;
    int huong = 2; // ban đầu đi sang phải

    while (true)
    {
         getChar(huong);

         if (huong == 0)
             y++;
         else if (huong == 1)
             y--;
         else if (huong == 2)
             x++;
         else if (huong == 3)
             x--;

        // Xóa phần cuối của thân
        gotoxy(ran.body[ran.length - 1].x, ran.body[ran.length - 1].y);
        cout << " ";

        DiChuyen(x, y);
        //Vẽ lại rắn sau khi đã thay đổi xy
        VeRan();
        Sleep(100); //Tăng tốc độ của rắn
    }
}
