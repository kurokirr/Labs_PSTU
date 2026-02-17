#include <iostream>
using namespace std;
int main()
{
	const int n = 3, m = 3;
	int a[n][m] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
	int stroka, t;
	cin >> stroka; 
	stroka--;
	for (int i = 0; i < m - 1; i++)
	{
		for (int q = 0; q < m - 1 - i; q++)
		{
			if (a[stroka][q] > a[stroka][q + 1])
			{
				for (int e = 0; e < n; e++)
				{
					t = a[e][q + 1];
					a[e][q + 1] = a[e][q];
					a[e][q] = t;
				}
			}
		}
	}
	cout << "matrix is below" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
		{
			cout << a[i][q] << " ";
		}
		cout << endl;
	}
}
