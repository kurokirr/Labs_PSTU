#include <iostream>
using namespace std;
int main()
{
	const int n = 8;
	int a[n] = { 0, -2, 5, 2, 1, 6, 7, 8 };
	int k;
	cin >> k;
	for (int q = 0; q < k; q++)
	{
		for (int i = 0; i < n; i++)
		{
			a[i]--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}