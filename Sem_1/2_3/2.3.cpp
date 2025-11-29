#include <iostream>
using namespace std;
	int n, tmp, sum = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		tmp = 1;
		for (int j = i; j <= i * 2; j++)
		{
			tmp *= j;
		}
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}