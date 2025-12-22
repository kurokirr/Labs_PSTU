#include <iostream>
using namespace std;
int main()
{
    int ch, x;
    cin >> ch;
    int* ptr = &ch;
    cin >> x;
    *ptr = x;
    cout << "chislo= " << ch;
    return 0;
}