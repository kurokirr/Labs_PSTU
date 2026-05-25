#include <iostream>
#include <locale>
using namespace std;

// ============ КЛАСС-КОНТЕЙНЕР СПИСОК ДЛЯ int ============
class ListInt {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity = capacity * 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ListInt() : size(0), capacity(10) {
        data = new int[capacity];
    }

    ListInt(int s) : size(s), capacity(s * 2) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ListInt(int s, int defaultValue) : size(s), capacity(s * 2) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    ListInt(const ListInt& other) : size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ListInt() {
        delete[] data;
    }

    ListInt& operator=(const ListInt& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }

    ListInt operator+(const ListInt& other) const {
        int minSize = (size < other.size) ? size : other.size;
        ListInt result(minSize);
        for (int i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    ListInt operator+(int constant) const {
        ListInt result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + constant;
        }
        return result;
    }

    friend ListInt operator+(int constant, const ListInt& list) {
        return list + constant;
    }

    void add(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    int getSize() const {
        return size;
    }

    friend istream& operator>>(istream& is, ListInt& list) {
        int n;
        cout << "Размер: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cout << "data[" << i << "] = ";
            is >> val;
            list.add(val);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const ListInt& list) {
        os << "[ ";
        for (int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i < list.size - 1) os << " ";
        }
        os << " ]";
        return os;
    }
};

// ============ КЛАСС-КОНТЕЙНЕР СПИСОК ДЛЯ float ============
class ListFloat {
private:
    float* data;
    int size;
    int capacity;

    void resize() {
        capacity = capacity * 2;
        float* newData = new float[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ListFloat() : size(0), capacity(10) {
        data = new float[capacity];
    }

    ListFloat(int s) : size(s), capacity(s * 2) {
        data = new float[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ListFloat(int s, float defaultValue) : size(s), capacity(s * 2) {
        data = new float[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    ListFloat(const ListFloat& other) : size(other.size), capacity(other.capacity) {
        data = new float[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ListFloat() {
        delete[] data;
    }

    ListFloat& operator=(const ListFloat& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new float[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    float& operator[](int index) {
        return data[index];
    }

    const float& operator[](int index) const {
        return data[index];
    }

    ListFloat operator+(const ListFloat& other) const {
        int minSize = (size < other.size) ? size : other.size;
        ListFloat result(minSize);
        for (int i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    ListFloat operator+(float constant) const {
        ListFloat result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + constant;
        }
        return result;
    }

    friend ListFloat operator+(float constant, const ListFloat& list) {
        return list + constant;
    }

    void add(float value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    int getSize() const {
        return size;
    }

    friend istream& operator>>(istream& is, ListFloat& list) {
        int n;
        cout << "Размер: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            float val;
            cout << "data[" << i << "] = ";
            is >> val;
            list.add(val);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const ListFloat& list) {
        os << "[ ";
        for (int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i < list.size - 1) os << " ";
        }
        os << " ]";
        return os;
    }
};

// ============ КЛАСС-КОНТЕЙНЕР СПИСОК ДЛЯ double ============
class ListDouble {
private:
    double* data;
    int size;
    int capacity;

    void resize() {
        capacity = capacity * 2;
        double* newData = new double[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ListDouble() : size(0), capacity(10) {
        data = new double[capacity];
    }

    ListDouble(int s) : size(s), capacity(s * 2) {
        data = new double[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ListDouble(int s, double defaultValue) : size(s), capacity(s * 2) {
        data = new double[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    ListDouble(const ListDouble& other) : size(other.size), capacity(other.capacity) {
        data = new double[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ListDouble() {
        delete[] data;
    }

    ListDouble& operator=(const ListDouble& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new double[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    double& operator[](int index) {
        return data[index];
    }

    const double& operator[](int index) const {
        return data[index];
    }

    ListDouble operator+(const ListDouble& other) const {
        int minSize = (size < other.size) ? size : other.size;
        ListDouble result(minSize);
        for (int i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    ListDouble operator+(double constant) const {
        ListDouble result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + constant;
        }
        return result;
    }

    friend ListDouble operator+(double constant, const ListDouble& list) {
        return list + constant;
    }

    void add(double value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    int getSize() const {
        return size;
    }

    friend istream& operator>>(istream& is, ListDouble& list) {
        int n;
        cout << "Размер: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            double val;
            cout << "data[" << i << "] = ";
            is >> val;
            list.add(val);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const ListDouble& list) {
        os << "[ ";
        for (int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i < list.size - 1) os << " ";
        }
        os << " ]";
        return os;
    }
};

// ============ КЛАСС-КОНТЕЙНЕР СПИСОК ДЛЯ PAIR ============
class Pair {
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(int f) : first(f), second(0.0) {}

    int getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator+(int constant) const {
        return Pair(first + constant, second + constant);
    }

    Pair operator+(double constant) const {
        return Pair(first + constant, second + constant);
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        cout << "Введите первое число (int): ";
        is >> p.first;
        cout << "Введите второе число (double): ";
        is >> p.second;
        return is;
    }
};

class ListPair {
private:
    Pair* data;
    int size;
    int capacity;

    void resize() {
        capacity = capacity * 2;
        Pair* newData = new Pair[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ListPair() : size(0), capacity(10) {
        data = new Pair[capacity];
    }

    ListPair(int s) : size(s), capacity(s * 2) {
        data = new Pair[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = Pair();
        }
    }

    ListPair(int s, Pair defaultValue) : size(s), capacity(s * 2) {
        data = new Pair[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    ListPair(const ListPair& other) : size(other.size), capacity(other.capacity) {
        data = new Pair[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ListPair() {
        delete[] data;
    }

    ListPair& operator=(const ListPair& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new Pair[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Pair& operator[](int index) {
        return data[index];
    }

    const Pair& operator[](int index) const {
        return data[index];
    }

    ListPair operator+(const ListPair& other) const {
        int minSize = (size < other.size) ? size : other.size;
        ListPair result(minSize);
        for (int i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    ListPair operator+(int constant) const {
        ListPair result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + constant;
        }
        return result;
    }

    void add(Pair value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    int getSize() const {
        return size;
    }

    friend istream& operator>>(istream& is, ListPair& list) {
        int n;
        cout << "Размер: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            Pair val;
            cout << "data[" << i << "] = ";
            is >> val;
            list.add(val);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const ListPair& list) {
        os << "[ ";
        for (int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i < list.size - 1) os << " ";
        }
        os << " ]";
        return os;
    }
};

ListPair operator+(int constant, const ListPair& list) {
    ListPair result;
    for (int i = 0; i < list.getSize(); i++) {
        result.add(Pair(constant, constant) + list[i]);
    }
    return result;
}

// ============ ТЕСТИРУЮЩАЯ ПРОГРАММА ============
int main() {
    setlocale(LC_ALL, "RU");

    // ===== ТЕСТ ДЛЯ int =====
    cout << "========== ТЕСТ ДЛЯ ТИПА int ==========\n" << endl;

    ListInt a, b;
    a.add(1); a.add(2); a.add(3);
    b.add(5); b.add(6); b.add(7);

    cout << "Список a: " << a << endl;
    cout << "Список b: " << b << endl;

    cout << "\nОператор []: a[0] = " << a[0] << ", a[1] = " << a[1] << endl;
    a[1] = 20;
    cout << "a после изменения: " << a << endl;

    cout << "\na + b = " << (a + b) << endl;
    cout << "a + 10 = " << (a + 10) << endl;
    cout << "5 + a = " << (5 + a) << endl;

    ListInt f;
    f = a;
    cout << "\nf = a: " << f << endl;

    // ===== ТЕСТ ДЛЯ float =====
    cout << "\n========== ТЕСТ ДЛЯ ТИПА float ==========\n" << endl;

    ListFloat c, d;
    c.add(1.5f); c.add(2.5f); c.add(3.5f);
    d.add(0.5f); d.add(1.5f); d.add(2.5f);

    cout << "Список c: " << c << endl;
    cout << "Список d: " << d << endl;
    cout << "c + d = " << (c + d) << endl;
    cout << "c + 2.5 = " << (c + 2.5f) << endl;

    // ===== ТЕСТ ДЛЯ double =====
    cout << "\n========== ТЕСТ ДЛЯ ТИПА double ==========\n" << endl;

    ListDouble e, g;
    e.add(1.1); e.add(2.2); e.add(3.3);
    g.add(0.1); g.add(0.2); g.add(0.3);

    cout << "Список e: " << e << endl;
    cout << "Список g: " << g << endl;
    cout << "e + g = " << (e + g) << endl;
    cout << "e + 1.5 = " << (e + 1.5) << endl;

    // ===== ТЕСТ ДЛЯ ПОЛЬЗОВАТЕЛЬСКОГО КЛАССА Pair =====
    cout << "\n========== ТЕСТ ДЛЯ КЛАССА Pair ==========\n" << endl;

    ListPair list1, list2;

    list1.add(Pair(1, 1.5));
    list1.add(Pair(2, 2.5));
    list1.add(Pair(3, 3.5));

    list2.add(Pair(5, 0.5));
    list2.add(Pair(6, 1.5));
    list2.add(Pair(7, 2.5));

    cout << "Список list1: " << list1 << endl;
    cout << "Список list2: " << list2 << endl;

    cout << "\nОператор []: list1[0] = " << list1[0] << endl;
    list1[1] = Pair(20, 20.5);
    cout << "list1 после изменения: " << list1 << endl;

    cout << "\nlist1 + list2 = " << (list1 + list2) << endl;
    cout << "list1 + 10 = " << (list1 + 10) << endl;
    cout << "5 + list1 = " << (5 + list1) << endl;

    ListPair list3;
    list3 = list1;
    cout << "\nlist3 = list1: " << list3 << endl;

    cout << "\nВвод нового списка Pair:" << endl;
    ListPair list4;
    cin >> list4;
    cout << "Вы ввели: " << list4 << endl;

    return 0;
}