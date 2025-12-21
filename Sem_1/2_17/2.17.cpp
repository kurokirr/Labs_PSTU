#include <iostream>
#include <cmath>
int main()
{
    int n;
    float sum, x, f= 1;
    cin >> n >> x;
    sum = 1 + x;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
        sum += pow(x, i) / f;
    }
    cout << "sum = " << sum;
    return 0;
}