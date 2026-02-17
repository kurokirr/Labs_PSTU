#include <iostream>
using namespace std;
int main()
{
	bool f = true;
	const int n = 7;
	int a[n] = { 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] >= a[i + 1])
		{
			f = false;
			break;
		}
	}
	if (f)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
}