#include <iostream>
using namespace std;
int main()
{
	const int n = 8;
	int a[n] = { 1, 2, 8, 4, -5, 6, 7, 8 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	cout << "min = " << min << " max = " << max;
}