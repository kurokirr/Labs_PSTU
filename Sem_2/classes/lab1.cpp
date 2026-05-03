#include <iostream>

class Product
{
    int pr;
    int count;

public:
    Product(int a, int b) : pr(a), count(b) {}

    ~Product() {};

    void cost()
    {
        std::cout << "cost = " << pr * count << "\n";
    }
};

int main()
{
    Product game(99, 100);

    game.cost();
}