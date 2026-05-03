#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	int n, k, chislo, m, ch2 = 0, w=0, number;
	cout << "size of the array : ";
	cin >> n;
	int* a = new int[n];
	srand(time(0));
	cout << "original massiv :" << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl << "deleting from : ";
	cin >> k;
	k--;
	cout<< "how much? : ";
	cin >> chislo;
	m = n - chislo + 1;
	int* b = new int[m];
	cout << "new number : ";
	cin >> number;
	for (int i = 0; i < n; i++)
	{
		if ((i >= k) && (ch2 != chislo))
		{
			ch2++;
		}
		else 
		{
			b[w] = a[i];
			w++;
		}
		if (i == n - 1)
		{
			b[w] = number;
		}
	}
	cout << "new massiv : ";
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
	
}