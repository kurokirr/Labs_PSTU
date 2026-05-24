#include <iostream>
#include <deque>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <clocale>

using namespace std;

// Тип Pair из лабораторной работы №3
struct Pair {
    int first;
    double second;

    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    // Перегрузка операторов для сравнения
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

    // Арифметические операторы
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }

    // Оператор ввода
    friend istream& operator>>(istream& is, Pair& p) {
        cout << "Введите first (int): ";
        is >> p.first;
        cout << "Введите second (double): ";
        is >> p.second;
        return is;
    }
};

// Предикат для replace_if (замена элементов с first > 4)
struct GreaterThanFour {
    bool operator()(const Pair& p) const {
        return p.first > 4;
    }
};

// Предикат для remove_if (удаление элементов с second < 3.0)
struct LessThanThree {
    bool operator()(const Pair& p) const {
        return p.second < 3.0;
    }
};

// Предикат для поиска по ключевому полю (first)
struct FindByFirst {
    int key;
    FindByFirst(int k) : key(k) {}
    bool operator()(const Pair& p) const {
        return p.first == key;
    }
};

// Предикат для поиска элемента с заданным диапазоном ключей
struct FindByRange {
    int minKey, maxKey;
    FindByRange(int minK, int maxK) : minKey(minK), maxKey(maxK) {}
    bool operator()(const Pair& p) const {
        return p.first >= minKey && p.first <= maxKey;
    }
};

// Функция для for_each (добавление среднего арифметического)
class AddAverage {
private:
    Pair average;
public:
    AddAverage(const Pair& avg) : average(avg) {}
    void operator()(Pair& p) const {
        p = Pair(p.first + average.first, p.second + average.second);
    }
};

// Функция для вывода элемента
void printPair(const Pair& p) {
    cout << p << " ";
}

// Контейнер - двунаправленная очередь (deque)
void task1() {
    cout << "\n=== ЗАДАЧА 1: Двунаправленная очередь (deque) ===\n";

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    deque<Pair> dq;
    cout << "\nВведите элементы:\n";
    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        dq.push_back(p);
    }

    cout << "\nИсходный контейнер: ";
    for_each(dq.begin(), dq.end(), printPair);
    cout << endl;

    // 3. Замена элементов (replace_if - заменить Pair с first > 4)
    cout << "\n--- 3. ЗАМЕНА ЭЛЕМЕНТОВ ---\n";
    replace_if(dq.begin(), dq.end(), GreaterThanFour(), Pair(0, 0));
    cout << "После replace_if (first>4 -> (0,0)): ";
    for_each(dq.begin(), dq.end(), printPair);
    cout << endl;

    // 4. Удаление элементов (remove_if)
    cout << "\n--- 4. УДАЛЕНИЕ ЭЛЕМЕНТОВ ---\n";
    auto newEnd = remove_if(dq.begin(), dq.end(), LessThanThree());
    dq.erase(newEnd, dq.end());
    cout << "После remove_if (second<3.0): ";
    for_each(dq.begin(), dq.end(), printPair);
    cout << endl;

    // 5. Сортировка
    cout << "\n--- 5. СОРТИРОВКА ---\n";
    sort(dq.begin(), dq.end(), [](const Pair& a, const Pair& b) {
        return a.first < b.first;
        });
    cout << "Сортировка по first (возрастание): ";
    for_each(dq.begin(), dq.end(), printPair);
    cout << endl;

    sort(dq.begin(), dq.end(), [](const Pair& a, const Pair& b) {
        return a.first > b.first;
        });
    cout << "Сортировка по first (убывание): ";
    for_each(dq.begin(), dq.end(), printPair);
    cout << endl;

    // 6. Поиск элемента
    cout << "\n--- 6. ПОИСК ЭЛЕМЕНТА ---\n";
    int searchKey;
    cout << "Введите ключ (first) для поиска: ";
    cin >> searchKey;

    auto it = find_if(dq.begin(), dq.end(), FindByFirst(searchKey));
    int count = count_if(dq.begin(), dq.end(), FindByFirst(searchKey));

    if (it != dq.end()) {
        cout << "Найдено " << count << " элемента(ов) с ключом " << searchKey << ": ";
        for (auto i = dq.begin(); i != dq.end(); ++i) {
            if (i->first == searchKey)
                cout << *i << " ";
        }
        cout << endl;
    }
    else {
        cout << "Элемент с ключом " << searchKey << " не найден\n";
    }

    // 7. Задание варианта: найти максимальный элемент и добавить его в конец
    cout << "\n--- 7. ЗАДАНИЕ ВАРИАНТА ---\n";
    auto maxIt = max_element(dq.begin(), dq.end(),
        [](const Pair& a, const Pair& b) { return a.first < b.first; });

    if (maxIt != dq.end()) {
        Pair maxElem = *maxIt;
        cout << "Максимальный элемент: " << maxElem << endl;
        dq.push_back(maxElem);
        cout << "Контейнер после добавления максимума в конец: ";
        for_each(dq.begin(), dq.end(), printPair);
        cout << endl;
    }
}

// Адаптер контейнера - стек (stack)
void task2() {
    cout << "\n=== ЗАДАЧА 2: Адаптер контейнера (stack) ===\n";

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    stack<Pair> st;
    cout << "\nВведите элементы:\n";
    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        st.push(p);
    }

    // Для работы со стеком используем временный вектор
    vector<Pair> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end());

    cout << "\nИсходный стек (как вектор): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 3. Замена элементов
    cout << "\n--- 3. ЗАМЕНА ЭЛЕМЕНТОВ ---\n";
    replace_if(temp.begin(), temp.end(), GreaterThanFour(), Pair(0, 0));
    cout << "После replace_if (first>4 -> (0,0)): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 4. Удаление элементов
    cout << "\n--- 4. УДАЛЕНИЕ ЭЛЕМЕНТОВ ---\n";
    auto newEnd = remove_if(temp.begin(), temp.end(), LessThanThree());
    temp.erase(newEnd, temp.end());
    cout << "После remove_if (second<3.0): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 5. Сортировка
    cout << "\n--- 5. СОРТИРОВКА ---\n";
    sort(temp.begin(), temp.end(), [](const Pair& a, const Pair& b) {
        return a.first < b.first;
        });
    cout << "Сортировка по first (возрастание): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    sort(temp.begin(), temp.end(), [](const Pair& a, const Pair& b) {
        return a.first > b.first;
        });
    cout << "Сортировка по first (убывание): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 6. Поиск элемента
    cout << "\n--- 6. ПОИСК ЭЛЕМЕНТА ---\n";
    int searchKey;
    cout << "Введите ключ (first) для поиска: ";
    cin >> searchKey;

    auto it = find_if(temp.begin(), temp.end(), FindByFirst(searchKey));
    if (it != temp.end()) {
        cout << "Найден элемент: " << *it << endl;
    }
    else {
        cout << "Элемент с ключом " << searchKey << " не найден\n";
    }

    // 7. Задание варианта: найти максимальный элемент и добавить в конец
    cout << "\n--- 7. ЗАДАНИЕ ВАРИАНТА ---\n";
    auto maxIt = max_element(temp.begin(), temp.end(),
        [](const Pair& a, const Pair& b) { return a.first < b.first; });

    if (maxIt != temp.end()) {
        cout << "Максимальный элемент: " << *maxIt << endl;
        temp.push_back(*maxIt);

        // Обратно в стек
        while (!st.empty()) st.pop();
        for (const auto& p : temp) st.push(p);

        cout << "Стек после добавления максимума (от дна к вершине): ";
        for (const auto& p : temp) cout << p << " ";
        cout << endl;
    }
}

// Ассоциативный контейнер - множество (set)
void task3() {
    cout << "\n=== ЗАДАЧА 3: Ассоциативный контейнер (set) ===\n";

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    set<Pair> s;
    cout << "\nВведите элементы:\n";
    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        s.insert(p);
    }

    cout << "\nИсходный set (автоматически отсортирован, уникальные ключи): ";
    for_each(s.begin(), s.end(), printPair);
    cout << endl;

    // Для алгоритмов STL с set нужен вектор
    vector<Pair> temp(s.begin(), s.end());

    // 3. Замена элементов
    cout << "\n--- 3. ЗАМЕНА ЭЛЕМЕНТОВ ---\n";
    replace_if(temp.begin(), temp.end(), GreaterThanFour(), Pair(0, 0));
    cout << "После replace_if (first>4 -> (0,0)): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 4. Удаление элементов
    cout << "\n--- 4. УДАЛЕНИЕ ЭЛЕМЕНТОВ ---\n";
    auto newEnd = remove_if(temp.begin(), temp.end(), LessThanThree());
    temp.erase(newEnd, temp.end());
    cout << "После remove_if (second<3.0): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 5. Сортировка (set уже отсортирован, но покажем для вектора)
    cout << "\n--- 5. СОРТИРОВКА ---\n";
    sort(temp.begin(), temp.end(), [](const Pair& a, const Pair& b) {
        return a.first < b.first;
        });
    cout << "Сортировка по first (возрастание): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    sort(temp.begin(), temp.end(), [](const Pair& a, const Pair& b) {
        return a.first > b.first;
        });
    cout << "Сортировка по first (убывание): ";
    for_each(temp.begin(), temp.end(), printPair);
    cout << endl;

    // 6. Поиск элемента
    cout << "\n--- 6. ПОИСК ЭЛЕМЕНТА ---\n";
    int searchKey;
    cout << "Введите ключ (first) для поиска: ";
    cin >> searchKey;

    auto it = find_if(temp.begin(), temp.end(), FindByFirst(searchKey));
    if (it != temp.end()) {
        cout << "Найден элемент: " << *it << endl;
    }
    else {
        cout << "Элемент с ключом " << searchKey << " не найден\n";
    }

    // 7. Задание варианта: найти максимальный элемент и добавить в конец
    cout << "\n--- 7. ЗАДАНИЕ ВАРИАНТА ---\n";
    auto maxIt = max_element(temp.begin(), temp.end(),
        [](const Pair& a, const Pair& b) { return a.first < b.first; });

    if (maxIt != temp.end()) {
        cout << "Максимальный элемент: " << *maxIt << endl;

        // Добавляем в set (если такого элемента еще нет)
        s.insert(*maxIt);

        cout << "Set после добавления максимума: ";
        for_each(s.begin(), s.end(), printPair);
        cout << endl;

        if (s.find(*maxIt) != s.end()) {
            cout << "Примечание: set хранит только уникальные элементы.\n";
            cout << "Если максимальный элемент уже был в set, он не добавился повторно.\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    task1();
    task2();
    task3();


    return 0;
}