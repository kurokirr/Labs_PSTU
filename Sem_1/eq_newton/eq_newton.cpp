#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 3 * x - 4 * log(x) - 5;
}
double df(double x) {
    return 3 - (4 / x);
}
double ddf(double x) {
    return 4 / pow(x, 2);
}

int main() {
    double e, a, b, x0, x1;
    cin >> e >> a >> b;
    int i = 0;
    if ((f(a) * ddf(a)) > 0) {
        x0 = a;
    }
    else {
        x0 = b;
    }
    x1 = x0 - f(x0) / df(x0);
    while (abs(x1 - x0) > e) {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
        i++;
    }
    cout << x1 << endl << i;
}
