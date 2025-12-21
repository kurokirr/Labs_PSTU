#include <iostream>
using namespace std;
int main()
{
    setLocale(LC_ALL, "Rus");
    int ch, s;
    bool fhod = false;
    cin >> ch >> s;
    while (ch > 0)
    {
        if (ch % 10 == s)
        {
            fhod = true;
        }
        ch /= 10;
    }
    if (fhod)
    {
        cout << "число входит";
    }
    else
    {
        cout << "число не входит";
    }
    return 0;
}