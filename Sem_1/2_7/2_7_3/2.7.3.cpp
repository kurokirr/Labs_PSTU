#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int q = 0; q < n; q++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < n-2; i++)
	{
		cout << "*";
		for (int w = 0; w < n - 2; w++)
		{
			cout << " ";
		}
		cout << "*"<<endl;
	}
	for (int q = 0; q < n; q++)
	{
		cout << "*";
	}
	return 0;
}
