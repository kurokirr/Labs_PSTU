
// 3x - 4lnx - 5
// [2;4]

#include <iostream>
#include <cmath>
using namespace std;
const double E = 0.0000001;
double f(double x)
{
	return ((3 * x) - (4 * log(x)) - 5);
}

int main()
{
	double a = 2, b = 4, c;
	while (b - a > E)
	{
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	cout << c << endl;
	return 0;
}
