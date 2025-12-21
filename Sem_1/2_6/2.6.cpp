#include <iostream>
using namespace std;
int main()
{
	int n, p, k=0, n2, s=0;
	cin >> n;
	n2 = n;
	p = n / 2;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < s; k++)
		{
			cout << " ";
		}
		for (int q = 0; q < n2; q++)
		{
			cout << "*";
		}
		cout << endl;
		n2--;
		s++;
	}
	return 0;
}