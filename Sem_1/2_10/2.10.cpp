#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, k, a;
	cout << "введите длину последовательности" << endl;
	cin >> n;
	cout << "введите первое число" << endl;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cout << "введите след.число" << endl;
		cin >> a;
		if (k <= a)
			k = a;
	}
	cout << k;
}