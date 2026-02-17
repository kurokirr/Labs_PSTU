#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	const int n = 10;
	int a[n]; //= { 1, 2, 3, 4, 5, 6, 7, 0, 8, 9 }(для проверки);
	bool zero = false, uslovie = false;
	int newsize = n, j = 0, chet = 0;
	srand(time(0));
	cout << "original massiv : ";
	for (int i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 100;
	if (a[i] == 0)
		{
			zero = true;
		}
		cout << a[i] << " ";
	}
	//zero = true (для проверки);
	if (zero == true)
	{
		newsize = n - 1;
	}
	for (int i = 0; i < n; i++)
	{
		if ((a[i] % 2 == 0) && (a[i] != 0))
		{
			chet++;
		}
	}
	newsize += chet;
	int* b = new int[newsize];
	for (int i = 0; i < n; i++)
	{
		if ((a[i] == 0) && (uslovie == false))
		{
			uslovie == true;
		}
		else {
			b[j] = a[i];
			j++;
			if (a[i] % 2 == 0)
			{
				b[j] = a[i - 1] + 2;
				j++;
			}
		}
	}
	cout << endl << "new massiv      : ";
	for (int i = 0; i < newsize; i++)
	{
		cout << b[i] << " ";
	}
}