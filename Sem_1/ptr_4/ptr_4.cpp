#include <iostream>
using namespace std;
int main()
{
    int number;
    float t, min, max;
    float* ptr_max = &max;
    float* ptr_min = &min;
    cin >> number;
    cin >> *ptr_max;
    *ptr_min = *ptr_max;
    for (int i = 2; i <= number; i++)
    {
        cin >> t;
        if (t > *ptr_max) 
        { 
            *ptr_max = t; 
        }
        if (t < *ptr_min) 
        { 
            *ptr_min = t; 
        }
    }
    cout << "max = " << *ptr_max << endl << "min = " << *ptr_min;
    return 0;
}