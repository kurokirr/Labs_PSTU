#include <iostream>
using namespace std;
int main()
{
    bool up = true;
    int chislo, posled;
    cin >> chislo;
    last = chislo;
    while (chislo != 0)
    {
        if (chislo >= last)
        {
            last = chislo;
            cin >> chislo;
        }
        else
        {
            last = chislo;
            up = false;
            cin >> chislo;
        }
    }
    if (up) 
    { 
        cout << "po vozrastaniu"; 
    }
    else 
    { 
        cout << "ne po vozrastaniu"; 
    }
    return 0;
}