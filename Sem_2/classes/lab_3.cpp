#include <iostream>
#include <clocale>
using namespace std;

class Pair {
private:
    int first;
    double second;

public:
    // Конструктор без параметров
    Pair() {
        first = 0;
        second = 0;
    }

    // Конструктор с параметрами
    Pair(int f, double s) {
        first = f;
        second = s;
    }

    // Конструктор копирования
    Pair(const Pair& other) {
        first = other.first;
        second = other.second;
    }

    // Деструктор
    ~Pair() {}

    // Селекторы
    int getFirst() {
        return first;
    }

    double getSecond() {
        return second;
    }

    // Модификаторы
    void setFirst(int f) {
        first = f;
    }

    void setSecond(double s) {
        second = s;
    }

    // Перегрузка оператора присваивания
    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    // Перегрузка вывода
    friend ostream& operator<<(ostream& out, const Pair& p) {
        out << p.first << ":" << p.second;
        return out;
    }

    // Перегрузка ввода
    friend istream& operator>>(istream& in, Pair& p) {
        cout << "Введите первое число: ";
        in >> p.first;
        cout << "Введите второе число: ";
        in >> p.second;
        return in;
    }

    // Сравнение <
    bool operator<(const Pair& other) {
        if (first < other.first)
            return true;
        if (first == other.first && second < other.second)
            return true;
        return false;
    }

    // Сравнение >
    bool operator>(const Pair& other) {
        if (first > other.first)
            return true;
        if (first == other.first && second > other.second)
            return true;
        return false;
    }

    // Префиксный --
    Pair& operator--() {
        --first;
        return *this;
    }

    // Постфиксный --
    Pair operator--(int) {
        Pair temp(*this);
        second--;
        return temp;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    Pair a(10, 5.5);
    Pair b(10, 4.2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    if (a > b)
        cout << "a > b" << endl;
    else if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a == b" << endl;

    --a;
    cout << "После --a: " << a << endl;

    a--;
    cout << "После a--: " << a << endl;

    return 0;
}