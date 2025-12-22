#include <iostream>
using namespace std;
int main()
{
    int n, f = 1;
    int* ptr_n = &n;
    int* ptr_f = &f;
    cin >> *ptr_n;
    for (int i = 2; i <= n; i++)
    {
        *ptr_f *= i;
    }
    cout << *ptr_f;
    return 0;
}