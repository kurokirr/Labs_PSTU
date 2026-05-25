#include <iostream>
#include <locale>
using namespace std;

// 1. Абстрактный класс PERSON
class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() {}

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }

    // Чисто виртуальный метод
    virtual double calculateSalary() const = 0;

    virtual void print(ostream& os) const {
        os << "Имя: " << name << ", Возраст: " << age;
    }
};

ostream& operator<<(ostream& os, const Person& p) {
    p.print(os);
    return os;
}

// 2. Производный класс EMPLOYEE
class Employee : public Person {
private:
    string position;
    double salary;
    double bonusPercent;
public:
    Employee(string n = "", int a = 0, string p = "", double s = 0, double bp = 0)
        : Person(n, a), position(p), salary(s), bonusPercent(bp) {
    }

    void setPosition(string p) { position = p; }
    void setSalary(double s) { salary = s; }
    void setBonusPercent(double bp) { bonusPercent = bp; }

    string getPosition() const { return position; }
    double getSalary() const { return salary; }
    double getBonusPercent() const { return bonusPercent; }

    double calculateSalary() const override {
        return salary + salary * bonusPercent / 100.0;
    }

    void print(ostream& os) const override {
        os << "Сотрудник: " << name << ", Возраст: " << age
            << ", Должность: " << position << ", Оклад: " << salary
            << ", Премия(%): " << bonusPercent
            << ", Итого: " << calculateSalary();
    }
};

// 3. Класс Вектор (на динамическом массиве)
class Vector {
private:
    Person** arr;
    int capacity;
    int count;

    void resize() {
        capacity = capacity * 2;
        Person** newArr = new Person * [capacity];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    Vector() : capacity(10), count(0) {
        arr = new Person * [capacity];
    }

    ~Vector() {
        delete[] arr;
    }

    void add(Person* p) {
        if (count >= capacity) {
            resize();
        }
        arr[count++] = p;
    }

    Person* get(int index) const {
        if (index >= 0 && index < count) {
            return arr[index];
        }
        return nullptr;
    }

    int size() const {
        return count;
    }

    // 4. Перегрузка операции вывода для класса Вектор
    friend ostream& operator<<(ostream& os, const Vector& v) {
        for (int i = 0; i < v.count; i++) {
            os << *(v.arr[i]) << endl;
        }
        return os;
    }
};

// 5. Основная функция
int main() {
    setlocale(LC_ALL, "RU");

    Vector vec;

    // Создание объектов
    Employee* emp1 = new Employee("Иванов Иван", 30, "Программист", 50000, 20);
    Employee* emp2 = new Employee("Петрова Мария", 25, "Менеджер", 60000, 15);
    Employee* emp3 = new Employee("Сидоров Петр", 35, "Директор", 100000, 30);

    // Добавление в вектор
    vec.add(emp1);
    vec.add(emp2);
    vec.add(emp3);

    // Демонстрация полиморфизма
    cout << "Содержимое вектора:" << endl;
    cout << vec << endl;

    // Изменение полей
    emp1->setName("Иванов Иван Петрович");
    emp1->setBonusPercent(25);

    cout << "После изменений:" << endl;
    cout << vec << endl;

    // Обращение по индексу
    cout << "Первый элемент:" << endl;
    cout << *(vec.get(0)) << endl;

    // Очистка памяти
    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}