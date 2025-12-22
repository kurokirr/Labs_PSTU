#include <iostream>
using namespace std;
int main()
{
    int sum = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            sum -= i;
        }
        else
        {
            sum += i;
        }
    }
    cout << "sum = " << sum;
    return 0;
}