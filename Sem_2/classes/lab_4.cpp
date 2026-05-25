#include <iostream>
#include <string>
#include <clocale>
using namespace std;

// Базовый класс
class Person {
protected:
    string name;
    int age;

public:
    Person() {
        name = "Неизвестно";
        age = 0;
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    Person(const Person& p) {
        name = p.name;
        age = p.age;
    }

    ~Person() {}

    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    Person& operator=(const Person& p) {
        name = p.name;
        age = p.age;
        return *this;
    }

    friend ostream& operator<<(ostream& out, Person& p) {
        out << "Имя: " << p.name << ", Возраст: " << p.age;
        return out;
    }

    friend istream& operator>>(istream& in, Person& p) {
        cout << "Введите имя: ";
        in >> p.name;
        cout << "Введите возраст: ";
        in >> p.age;
        return in;
    }
};

// Производный класс
class Employee : public Person {
private:
    string position;
    double salary;

public:
    Employee() : Person() {
        position = "Нет";
        salary = 0;
    }

    Employee(string n, int a, string p, double s)
        : Person(n, a) {
        position = p;
        salary = s;
    }

    Employee(const Employee& e) : Person(e) {
        position = e.position;
        salary = e.salary;
    }

    ~Employee() {}

    void setPosition(string p) {
        position = p;
    }

    void setSalary(double s) {
        salary = s;
    }

    string getPosition() {
        return position;
    }

    double getSalary() {
        return salary;
    }

    double calcSalary(double percent) {
        return salary + salary * percent / 100;
    }

    Employee& operator=(const Employee& e) {
        name = e.name;
        age = e.age;
        position = e.position;
        salary = e.salary;
        return *this;
    }

    friend ostream& operator<<(ostream& out, Employee& e) {
        out << "Имя: " << e.name
            << ", Возраст: " << e.age
            << ", Должность: " << e.position
            << ", Оклад: " << e.salary;
        return out;
    }

    friend istream& operator>>(istream& in, Employee& e) {
        cout << "Введите имя: ";
        in >> e.name;
        cout << "Введите возраст: ";
        in >> e.age;
        cout << "Введите должность: ";
        in >> e.position;
        cout << "Введите оклад: ";
        in >> e.salary;
        return in;
    }
};

// Функция принимает базовый класс
void ShowPerson(Person p) {
    cout << p << endl;
}

// Функция возвращает базовый класс
Person CreatePerson() {
    Person p;
    cin >> p;
    return p;
}

int main() {
    setlocale(LC_ALL, "RUS");

    Person p1;
    cout << "Введите данные человека:" << endl;
    cin >> p1;
    cout << p1 << endl;

    Employee e1;
    cout << "\nВведите данные сотрудника:" << endl;
    cin >> e1;
    cout << e1 << endl;

    double premium;
    cout << "\nВведите процент премии: ";
    cin >> premium;

    cout << "Зарплата с премией: "
        << e1.calcSalary(premium) << endl;

    // Принцип подстановки
    cout << "\nВывод как Person:" << endl;
    ShowPerson(e1);

    
    return 0;
}