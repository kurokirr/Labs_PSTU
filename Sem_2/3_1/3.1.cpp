#include <iostream>
using namespace std;
int main()
{
	const int n = 7;
	int a[n] = { 1, 2, 3, 4, 5, 6, 7 };
	int b, c = n - 1;
	for (int i = 0; i < n/2; i++)
	{
		b = a[i];
		a[i] = a[c];
		a[c] = b;
		c--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}