#include <iostream>
using namespace std;
int main()
{
	int n, p, s = 1;
	cin >> n;
	p = n - 1;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < p; q++)
		{
			cout << " ";
		}
		for (int w = 0; w < s; w++)
		{
			cout << "*";
		}
		p--;
		s++;
		cout << endl;
	}
}
