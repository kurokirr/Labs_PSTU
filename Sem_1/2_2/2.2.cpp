#include <iostream>
using namespace std;
int n, tmp, sum = 0;
int main()
{
	int n, p, r=1;
	cin >> n;
	p = n / 2;
	for (int i = 0; i < p; i++)
	{
		for (int q = 0; q < p; q++)
		{
			cout << " ";
		}
		cout << "*";
		for (int q = 0; q < r; q++)
		{
			cout << " ";
		}
		r += 2;
		cout << endl;
	}
}