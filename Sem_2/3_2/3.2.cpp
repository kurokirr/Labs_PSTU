#include <iostream>
using namespace std;
int main()
{
	const int n = 7;
	int a[n] = { 1, 2, 3, 4, 5, 6, 7 };
	int max = a[0], count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
		{
			count++;
		}
	}
	cout << "max = " << max << "count = " << count;
}