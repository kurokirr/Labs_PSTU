#include <iostream>
#include <stdexcept>
#include <locale>
using namespace std;

class List {
private:
    int* data;
    int size;

public:
    List(int s = 0) {
        if (s < 0)
            throw invalid_argument("Ошибка: отрицательный размер!");
        size = s;
        data = new int[size];
    }

    List(const List& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~List() {
        delete[] data;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Ошибка: индекс вне диапазона!");
        return data[index];
    }

    List operator+(const List& other) const {
        List temp(size + other.size);

        for (int i = 0; i < size; i++)
            temp.data[i] = data[i];

        for (int i = 0; i < other.size; i++)
            temp.data[size + i] = other.data[i];

        return temp;
    }

    List operator+(int value) const {
        List temp(size + 1);

        temp.data[0] = value;
        for (int i = 0; i < size; i++)
            temp.data[i + 1] = data[i];

        return temp;
    }

    friend ostream& operator<<(ostream& os, const List& l) {
        os << "[ ";
        for (int i = 0; i < l.size; i++)
            os << l.data[i] << " ";
        os << "]";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    try {
        List a(3);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;

        List b(2);
        b[0] = 4;
        b[1] = 5;

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;

        cout << "a + b = " << a + b << endl;
        cout << "a + 10 = " << a + 10 << endl;

        // Проверка исключения
        cout << a[10] << endl;

    }
    catch (const exception& e) {
        cout << "Перехвачено исключение: " << e.what() << endl;
    }

    return 0;
}