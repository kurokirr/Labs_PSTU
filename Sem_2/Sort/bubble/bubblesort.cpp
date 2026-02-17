#include <iostream>
using namespace std;
int main()
{
    const int n = 10;
    int a[n] = { 102, 14, 22, 67, 69, 12, 11, 435, 100, 14 };
    int b;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                b = a[i];
                a[i] = a[i + 1];
                a[i + 1] = b;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}