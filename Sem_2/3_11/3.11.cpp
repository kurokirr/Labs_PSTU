#include <iostream>
using namespace std;
int main()
{
	const int n = 3, m = 3;
	int a[n][m] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < n; q++)
		{
			if (i == q)
			{
				a[i][q] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < n; q++)
		{
			cout << a[i][q] << " ";
		}
		cout << endl;
	}
}