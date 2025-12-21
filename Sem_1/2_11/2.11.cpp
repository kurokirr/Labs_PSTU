#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, a;
	bool pf = false;
	bool mf = false;
	cout << "введите длину последовательности" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (!pf && !mf)
		{
			if (a > 0)
			{
				pf = true;
			}
			else if (a < 0)
			{
				mf = true;
			}
		}
	}
	if (pf)
	{
		cout << "сначала ввели положительное число";
	}
	else if (mf)
	{
		cout << "сначала ввели отрицательное число";
	}
	else
	{
		cout << "все элементы были нулевые";
	}
}

