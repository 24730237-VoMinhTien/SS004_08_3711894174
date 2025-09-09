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
void getChar(int &huong);

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
    {
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
    void Score();
    void reset();
};

int main()
{
    CONRAN app;
    app.menu();
    return 0;
}

void CONRAN::reset()
{
    ran.length = 3;
    createSnake();
    score = 0;
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
        cout << "Lua chon:\n";
        choice = _getch();
        SetColor(7);
        switch (choice)
        {
        case '1':
            start();
            break;
        case '2':
            SetColor(14);
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
            SetColor(12);
            cout << "Thoat khoi chuong trinh.";
            _getch();
            return;
        default:
            SetColor(13);
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
    createSnake();
    drawSnake();
    food.x = 40;
    food.y = 16;
    drawFood();

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

        move(x, y);
        drawSnake();
        Sleep(100);
        Score();
        eatFood();

        if (isGameOver())
        {
            gotoxy(50, 14);
            SetColor(12); // Màu đỏ cho game over
            cout << "Ket thuc!!!";
            SetColor(7); // Reset màu
            gotoxy(50, 15);
            cout << "Diem la : " << score;
            gotoxy(40, 16);
            cout << "Nhan phim bat ky de tro ve menu.";
            _getch();
            reset();
            break;
        }
    }
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
    // Thay đổi phần thân rắn
    // Lưu phần cuối của thân rắn để xóa sau khi di chuyển
    Point prevTail = ran.body[ran.length - 1];

    // Dời thân rắn từ cuối về phía trước
    for (int i = ran.length - 1; i > 0; i--)
    {
        ran.body[i] = ran.body[i - 1];
    }

    // Thay đổi phần đầu rắn
    //  Cập nhật phần đầu rắn
    ran.body[0].x = x;
    ran.body[0].y = y;
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
    SetColor(14); // Vàng cho quả
    gotoxy(food.x, food.y);
    cout << (char)42;
    SetColor(7); // Reset màu
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
        } while (checkFood());
        drawFood();
    }
}

bool CONRAN::checkFood()
{
    for (int i = 0; i < ran.length; ++i)
    {
        if (food.x == ran.body[i].x && food.y == ran.body[i].y)
        {
            return true;
        }
    }
    return false;
}
// Điều hướng rắn
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

void CONRAN::Score()
{
    if (ran.body[0].x == food.x && ran.body[0].y == food.y)
    {
        gotoxy(107, 2);
        SetColor(13); // Màu tím cho điểm
        score += 5;
        cout << "Score: " << score;
        SetColor(7); // Reset màu
    }
}