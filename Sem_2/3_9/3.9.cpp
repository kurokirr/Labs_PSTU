#include <iostream>
using namespace std;
int main()
{
	const int n = 9;
	int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int newsize = n / 2, j = 0;
	int* b = new int[newsize];
	for (int i = 0; i <n; i++)
	{
		if ( (i+1) % 2 == 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < newsize; i++)
	{
		cout << b[i]<<" ";
	}
}