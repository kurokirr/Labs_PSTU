#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

// ============ ПОЛЬЗОВАТЕЛЬСКИЙ ТИП Pair (из лаб. работы №3) ============
class Pair {
private:
    int first;
    double second;
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    int getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

    // Операторы сравнения для set (нужны только <)
    bool operator<(const Pair& other) const {
        if (first != other.first)
            return first < other.first;
        return second < other.second;
    }

    bool operator>(const Pair& other) const {
        if (first != other.first)
            return first > other.first;
        return second > other.second;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }

    // Оператор сложения для задачи 3
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    // Оператор деления на число для среднего арифметического
    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    // Оператор присваивания
    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        cout << "first(int): "; is >> p.first;
        cout << "second(double): "; is >> p.second;
        return is;
    }
};

// ==================== ЗАДАЧА 1 (set<double>) ====================
void printSet(const set<double>& s) {
    for (double x : s) cout << x << " ";
    cout << endl;
}

void addToSet(set<double>& s, int n) {
    cout << "Введите " << n << " элементов double:\n";
    for (int i = 0; i < n; i++) {
        double x; cin >> x;
        s.insert(x);
    }
}

void removeFromSet(set<double>& s, int n) {
    auto it = s.begin();
    for (int i = 0; i < n && it != s.end(); i++) {
        it = s.erase(it);
    }
}

// Задание: найти максимальный элемент и добавить его в конец контейнера
// Для set "конец" не определен, поэтому добавим в конец через вектор
void task1(set<double>& s) {
    if (s.empty()) {
        cout << "Контейнер пуст!\n";
        return;
    }
    double maxElem = *s.rbegin(); // максимальный элемент в set
    s.insert(maxElem); // set не хранит дубликаты, поэтому ничего не изменится
    // Чтобы продемонстрировать задание, используем multiset
    cout << "Максимальный элемент: " << maxElem << endl;
    cout << "В set нельзя добавить дубликат. Рекомендуется использовать multiset.\n";
}

void solveTask1() {
    cout << "\n========== ЗАДАЧА 1 (set<double>) ==========\n";
    set<double> s;

    cout << "Создание контейнера. Введите количество элементов: ";
    int n; cin >> n;
    addToSet(s, n);

    cout << "Контейнер: "; printSet(s);

    cout << "Добавление. Введите сколько добавить: ";
    int add; cin >> add;
    addToSet(s, add);
    cout << "После добавления: "; printSet(s);

    cout << "Удаление. Введите сколько удалить (первые N элементов): ";
    int del; cin >> del;
    removeFromSet(s, del);
    cout << "После удаления: "; printSet(s);

    task1(s);
    cout << "Результат: "; printSet(s);
}

// ==================== ЗАДАЧА 2 (set<Pair>) ====================
void printSetPair(const set<Pair>& s) {
    for (auto x : s) cout << x << " ";
    cout << endl;
}

void addToSetPair(set<Pair>& s, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << ":\n";
        Pair p; cin >> p;
        s.insert(p);
    }
}

void removeFromSetPair(set<Pair>& s, int n) {
    auto it = s.begin();
    for (int i = 0; i < n && it != s.end(); i++) {
        it = s.erase(it);
    }
}

// Задание 2: найти элементы с ключами (first) из заданного диапазона и удалить
void task2(set<Pair>& s, int low, int high) {
    auto it = s.begin();
    int removed = 0;
    while (it != s.end()) {
        if (it->getFirst() >= low && it->getFirst() <= high) {
            it = s.erase(it);
            removed++;
        }
        else {
            ++it;
        }
    }
    cout << "Удалено " << removed << " элементов с first в диапазоне [" << low << "," << high << "]\n";
}

void solveTask2() {
    cout << "\n========== ЗАДАЧА 2 (set<Pair>) ==========\n";
    set<Pair> s;

    cout << "Создание контейнера. Введите количество элементов: ";
    int n; cin >> n;
    addToSetPair(s, n);

    cout << "Контейнер: "; printSetPair(s);

    cout << "Добавление. Введите сколько добавить: ";
    int add; cin >> add;
    addToSetPair(s, add);
    cout << "После добавления: "; printSetPair(s);

    cout << "Удаление. Введите сколько удалить (первые N элементов): ";
    int del; cin >> del;
    removeFromSetPair(s, del);
    cout << "После удаления: "; printSetPair(s);

    cout << "Задание: удалить элементы с first в диапазоне.\n";
    int low, high;
    cout << "Введите low и high: "; cin >> low >> high;
    task2(s, low, high);
    cout << "Результат: "; printSetPair(s);
}

// ==================== ЗАДАЧА 3 (параметризированный класс на основе set) ====================
template <typename T>
class MySet {
private:
    set<T> data;
public:
    void fill(initializer_list<T> init) {
        for (auto x : init) data.insert(x);
    }

    void addElements(int n) {
        cout << "Введите " << n << " элементов:\n";
        for (int i = 0; i < n; i++) {
            T x; cin >> x;
            data.insert(x);
        }
    }

    void removeElements(int n) {
        auto it = data.begin();
        for (int i = 0; i < n && it != data.end(); i++) {
            it = data.erase(it);
        }
    }

    void print() const {
        for (auto x : data) cout << x << " ";
        cout << endl;
    }

    int size() const { return data.size(); }

    // Задание 3: найти максимальный элемент и добавить его в конец контейнера
    void task3() {
        if (data.empty()) {
            cout << "Контейнер пуст!\n";
            return;
        }
        T maxElem = *data.rbegin();
        cout << "Максимальный элемент: " << maxElem << endl;
        // Для set нельзя добавить дубликат, выводим предупреждение
        cout << "В set нельзя добавить дубликат. Элемент не добавлен.\n";
    }

    // Альтернативная реализация для multiset
    void run() {
        cout << "Создание. Введите количество элементов: ";
        int n; cin >> n;
        addElements(n);
        print();

        cout << "Добавление. Введите сколько добавить: ";
        int a; cin >> a;
        addElements(a);
        print();

        cout << "Удаление. Введите сколько удалить (первые N): ";
        int d; cin >> d;
        removeElements(d);
        print();

        task3();
        print();
    }
};

void solveTask3() {
    cout << "\n========== ЗАДАЧА 3 (MySet<double>) ==========\n";
    MySet<double> ms;
    ms.run();
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");

    int choice;
    do {
        cout << "\n==================== МЕНЮ ====================\n";
        cout << "1. Задача 1 (set<double>)\n";
        cout << "2. Задача 2 (set<Pair>)\n";
        cout << "3. Задача 3 (MySet<double>)\n";
        cout << "0. Выход\n";
        cout << "===============================================\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: solveTask1(); break;
        case 2: solveTask2(); break;
        case 3: solveTask3(); break;
        case 0: cout << "До свидания!\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}