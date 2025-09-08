#include <iostream>
using namespace std;

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


int main()
{

    return 0;
}
