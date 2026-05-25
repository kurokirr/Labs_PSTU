#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
using namespace std;

// ===== Класс Pair =====
class Pair {
public:
    int first;
    double second;

    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    // Сравнение
    bool operator<(const Pair& other) const {
        return first < other.first;
    }

    bool operator>(const Pair& other) const {
        return first > other.first;
    }

    // Префикс --
    Pair& operator--() {
        first--;
        return *this;
    }

    // Постфикс --
    Pair operator--(int) {
        Pair temp = *this;
        second--;
        return temp;
    }

    // Ввод / вывод
    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        is >> p.first >> p.second;
        return is;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

// ===== Создание файла =====
void createFile(const char* fname) {
    ofstream f(fname);
    int n;
    cout << "Количество записей: ";
    cin >> n;

    Pair p;
    for (int i = 0; i < n; i++) {
        cout << "Введите пару (int double): ";
        cin >> p;
        f << p.first << " " << p.second << endl;
    }
    f.close();
}

// ===== Просмотр =====
void printFile(const char* fname) {
    ifstream f(fname);
    Pair p;
    cout << "\nСодержимое файла:\n";
    while (f >> p) {
        cout << p << endl;
    }
    f.close();
}

// ===== Удаление =====
void deleteValue(const char* fname, Pair key) {
    ifstream f(fname);
    ofstream temp("temp.txt");

    Pair p;
    while (f >> p) {
        if (!(p == key))
            temp << p.first << " " << p.second << endl;
    }

    f.close();
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
}

// ===== Уменьшение =====
void decreaseValue(const char* fname, Pair key, int L) {
    ifstream f(fname);
    ofstream temp("temp.txt");

    Pair p;
    while (f >> p) {
        if (p == key) {
            for (int i = 0; i < L; i++)
                --p; // префикс (-- уменьшает first)
        }
        temp << p.first << " " << p.second << endl;
    }

    f.close();
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
}

// ===== Добавление =====
void addAfter(const char* fname, Pair key, int K) {
    ifstream f(fname);
    ofstream temp("temp.txt");

    Pair p;
    while (f >> p) {
        temp << p.first << " " << p.second << endl;

        if (p == key) {
            for (int i = 0; i < K; i++) {
                Pair newp;
                cout << "Введите новую пару: ";
                cin >> newp;
                temp << newp.first << " " << newp.second << endl;
            }
        }
    }

    f.close();
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
}

// ===== Меню =====
int main() {
    setlocale(LC_ALL, "RU");
    const char* fname = "file.txt";
    int choice;

    do {
        cout << "\n1. Создать файл";
        cout << "\n2. Просмотр";
        cout << "\n3. Удалить значение";
        cout << "\n4. Уменьшить значение";
        cout << "\n5. Добавить после значения";
        cout << "\n0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        Pair key;
        int L, K;

        switch (choice) {
        case 1:
            createFile(fname);
            break;

        case 2:
            printFile(fname);
            break;

        case 3:
            cout << "Введите значение для удаления: ";
            cin >> key;
            deleteValue(fname, key);
            break;

        case 4:
            cout << "Введите значение: ";
            cin >> key;
            cout << "Введите L: ";
            cin >> L;
            decreaseValue(fname, key, L);
            break;

        case 5:
            cout << "Введите значение: ";
            cin >> key;
            cout << "Введите K: ";
            cin >> K;
            addAfter(fname, key, K);
            break;
        }

    } while (choice != 0);

    return 0;
}