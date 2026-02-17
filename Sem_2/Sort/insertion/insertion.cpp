#include <iostream>
using namespace std;
int main()
{
    const int n = 10;
    int temp;
    int a[n] = {1, 26, 62, 14, 67, 49, 812, 140, 23, 22};
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}