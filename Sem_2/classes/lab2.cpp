#include <iostream>
using namespace std;
class Road
{
    string pointa;
    string pointb;
    float time;

public:

    Road() : pointa(""), pointb(""), time(0) {}
    Road(string a, string b, float t) : pointa(a), pointb(b), time(t) {}
    Road(const Road& r)
    {
        pointa = r.pointa;
        pointb = r.pointb;
        time = r.time;
    }

    ~Road() {}

    void print()
    {
        cout << "ыефке of movement: " << pointa<< "\n end of movement: " << pointb<< "\n  Occupied time: " << time << "\n";
    }
};

int main()
{
    Road m228;
    Road m1337("Moscow", "Perm", 17);
    Road m6767(m1337);

    m228.print();
    m1337.print();
    m6767.print();
}