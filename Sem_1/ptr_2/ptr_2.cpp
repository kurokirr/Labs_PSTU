#include <iostream>
using namespace std;
int main()
{
    int c1, c2, t;
    cin >> c1 >> c2;
    int* ptr1 = &c1;
    int* ptr2 = &c2;
    t = *ptr1;
    *ptr1 = c2;
    *ptr2 = t;
    cout << "chislo odin= " << c1 << endl << "chislo dva = " << c2;
    return 0;
}