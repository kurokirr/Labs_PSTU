#include <iostream>
using namespace std;
int main()
{
	int n, p, d = 1, s;
	cin >> n;
	p = n / 2;
	s = p;
	for (int i = 0; i <=p; i++)
	{
		for (int q = 0; q < s; q++)
		{
			cout << " ";
		}
		for (int r = 0; r < d; r++)
		{
			cout << "*";
		}
		s--;
		cout<<endl;
		d += 2;
	}
	return 0;
}