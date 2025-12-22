#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, s;
    bool vh = false;
    int n;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        a = sin(n + i / n);
        if (a == s)
        {
            vh = true;
            break;
        }
    }
    if (vh)
    {
        cout << "element vhodit";
    }
    else
    {
        cout << "element ne vhodit";
    }
    return 0;
}