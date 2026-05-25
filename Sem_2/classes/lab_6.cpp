#include <iostream>
#include <locale>
using namespace std;

// Класс-итератор (прокси-класс для последовательного доступа)
class Iterator {
private:
    int* ptr;  // указатель на текущий элемент
public:
    Iterator(int* p = nullptr) : ptr(p) {}

    // переход к предыдущему элементу (--iter)
    Iterator& operator--() {
        if (ptr) ptr--;
        return *this;
    }

    // постфиксный --
    Iterator operator--(int) {
        Iterator temp = *this;
        if (ptr) ptr--;
        return temp;
    }

    // разыменование
    int& operator*() {
        return *ptr;
    }

    // сравнение
    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }

    bool operator==(const Iterator& other) const {
        return ptr == other.ptr;
    }
};

// Класс-контейнер СПИСОК
class List {
private:
    int* data;      // динамический массив
    int size;       // размер списка
    int capacity;   // вместимость

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
    // Конструкторы
    List() : size(0), capacity(10) {
        data = new int[capacity];
    }

    List(int s) : size(s), capacity(s * 2) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    List(int s, int defaultValue) : size(s), capacity(s * 2) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = defaultValue;
        }
    }

    // Конструктор копирования
    List(const List& other) : size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~List() {
        delete[] data;
    }

    // Операция присваивания
    List& operator=(const List& other) {
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

    // Операция доступа по индексу []
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    // Операция + вектор (сложение элементов списков a[i]+b[i])
    List operator+(const List& other) const {
        int minSize = (size < other.size) ? size : other.size;
        List result(minSize);
        for (int i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Операция + число (добавляет константу ко всем элементам)
    List operator+(int constant) const {
        List result(*this);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + constant;
        }
        return result;
    }

    // Дружественная функция для + число (число + список)
    friend List operator+(int constant, const List& list) {
        return list + constant;
    }

    // Добавление элемента в конец
    void add(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Получение размера
    int getSize() const {
        return size;
    }

    // Методы для работы с итератором
    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }

    // Операция ввода
    friend istream& operator>>(istream& is, List& list) {
        int n;
        cout << "Введите количество элементов: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            int val;
            cout << "Элемент " << i << ": ";
            is >> val;
            list.add(val);
        }
        return is;
    }

    // Операция вывода
    friend ostream& operator<<(ostream& os, const List& list) {
        os << "[";
        for (int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i < list.size - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

// Тестирующая программа
int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== Тестирование класса СПИСОК ===" << endl << endl;

    // Создание списков
    List list1;
    List list2;

    // Операция ввода
    cout << "Ввод первого списка:" << endl;
    cin >> list1;

    cout << "\nВвод второго списка:" << endl;
    cin >> list2;

    cout << "\n=== Демонстрация операций ===" << endl;

    // Операция вывода
    cout << "Первый список: " << list1 << endl;
    cout << "Второй список: " << list2 << endl;

    // Операция [] - доступа по индексу
    cout << "\n1. Операция [] - доступ по индексу:" << endl;
    if (list1.getSize() > 0) {
        cout << "list1[0] = " << list1[0] << endl;
        list1[0] = 100;
        cout << "После list1[0] = 100: " << list1 << endl;
    }

    // Операция + вектор (сложение списков)
    cout << "\n2. Операция + вектор (сложение списков):" << endl;
    List listSum = list1 + list2;
    cout << list1 << " + " << list2 << " = " << listSum << endl;

    // Операция + число (добавление константы)
    cout << "\n3. Операция + число (добавление константы):" << endl;
    List listPlusConst = list1 + 5;
    cout << list1 << " + 5 = " << listPlusConst << endl;

    // число + список
    List constPlusList = 10 + list1;
    cout << "10 + " << list1 << " = " << constPlusList << endl;

    // Операция присваивания
    cout << "\n4. Операция присваивания:" << endl;
    List listCopy;
    listCopy = list1;
    cout << "Копия первого списка: " << listCopy << endl;

    // Конструктор копирования
    List list3(list1);
    cout << "Список из конструктора копирования: " << list3 << endl;

    // Демонстрация работы итератора (-- переход к предыдущему)
    cout << "\n5. Демонстрация работы итератора (обход с конца к началу):" << endl;
    if (list1.getSize() > 0) {
        cout << "Итератор (от последнего к первому): ";
        Iterator it = list1.end();
        --it;  // переход на последний элемент
        while (true) {
            cout << *it << " ";
            if (it == list1.begin()) break;
            --it;  // переход к предыдущему элементу
        }
        cout << endl;
    }

    // Дополнительная демонстрация итератора
    cout << "\n6. Дополнительная демонстрация --it (постфиксный и префиксный):" << endl;
    if (list1.getSize() >= 2) {
        Iterator it = list1.end();
        --it;  // на последний
        cout << "Последний элемент: " << *it << endl;
        it--;  // постфиксный --
        cout << "Предпоследний элемент: " << *it << endl;
    }

    cout << "\n=== Тестирование завершено ===" << endl;

    return 0;
}