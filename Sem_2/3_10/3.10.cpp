#include <iostream>
using namespace std;
int main()
{
	const int n = 3;
	const int m = 3;
	int a[n][m] = { { 1, 2, 3 },{ 4, 5, 6 }, {7, 8, 9} };
	int b = 0;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = s; j < m; j++)
		{
			b = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = b;	
		}
		s++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
}