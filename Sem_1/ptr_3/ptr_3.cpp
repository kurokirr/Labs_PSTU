#include <iostream>
using namespace std;
int main()
{
    float c1, c2, sum = 0;
    cin >> c1 >> c2;
    float* ptr1 = &c1;
    float* ptr2 = &c2;
    sum = *ptr1 + *ptr2;
    cout << "sum = " << sum;
    return 0;
}