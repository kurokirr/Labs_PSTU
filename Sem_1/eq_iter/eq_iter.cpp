#include <iostream>
#include <cmath>
using namespace std;

double fi(double x) {
    return (4 * log(x) + 5) / 3;
}
double dfi(double x) {
    return 4 / (3 * x);
}
int main() {
    double e, a, b, x0, x1;
    cin >> e >> a >> b;
    int i = 1;
    if (dfi(a) < 1) {
        x0 = a;
    }
    else {
        x0 = b;
    }
    x1 = fi(x0);
    while (abs(x1 - x0) > e) {
        x0 = x1;
        x1 = fi(x0);
        i++;
    }
    cout << x1 << endl << i;
}