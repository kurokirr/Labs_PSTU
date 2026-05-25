#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <windows.h>
using namespace std;

// 1. Абстрактный класс PERSON
class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() {}

    // Селекторы и модификаторы
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }

    // Операция присваивания
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Чисто виртуальные методы для ввода и вывода
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual void inputFromCmd(const string& cmd) = 0;
};

// 2. Производный класс ABITURIENT
class Abiturient : public Person {
private:
    int score;
    string specialty;
public:
    Abiturient(string n = "", int a = 0, int s = 0, string sp = "")
        : Person(n, a), score(s), specialty(sp) {
    }

    // Деструктор
    ~Abiturient() {}

    // Селекторы и модификаторы
    void setScore(int s) { score = s; }
    void setSpecialty(string sp) { specialty = sp; }
    int getScore() const { return score; }
    string getSpecialty() const { return specialty; }

    // Операция присваивания
    Abiturient& operator=(const Abiturient& other) {
        if (this != &other) {
            Person::operator=(other);
            score = other.score;
            specialty = other.specialty;
        }
        return *this;
    }

    // Реализация виртуальных методов
    void input() override {
        cout << "Введите имя: "; cin >> name;
        cout << "Введите возраст: "; cin >> age;
        cout << "Введите количество баллов: "; cin >> score;
        cout << "Введите специальность: "; cin >> specialty;
    }

    void output() const override {
        cout << "Имя: " << name << ", Возраст: " << age
            << ", Баллы: " << score << ", Специальность: " << specialty;
    }

    void inputFromCmd(const string& cmd) override {
        // Формат: имя|возраст|баллы|специальность
        size_t pos1 = 0, pos2;
        pos2 = cmd.find('|', pos1);
        name = cmd.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
        pos2 = cmd.find('|', pos1);
        age = stoi(cmd.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = cmd.find('|', pos1);
        score = stoi(cmd.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        specialty = cmd.substr(pos1);
    }
};

// 4. Класс-группа ДЕРЕВО (на основе вектора)
class Tree {
protected:
    vector<Abiturient*> group;
public:
    Tree() {}

    // Конструктор копирования
    Tree(const Tree& other) {
        for (auto* p : other.group) {
            group.push_back(new Abiturient(*p));
        }
    }

    // Деструктор
    virtual ~Tree() {
        for (auto* p : group) {
            delete p;
        }
        group.clear();
    }

    // Операция присваивания
    Tree& operator=(const Tree& other) {
        if (this != &other) {
            for (auto* p : group) delete p;
            group.clear();
            for (auto* p : other.group) {
                group.push_back(new Abiturient(*p));
            }
        }
        return *this;
    }

    // Метод для добавления элемента
    void add(Abiturient* a) {
        group.push_back(a);
        cout << "Абитуриент добавлен. Всего: " << group.size() << endl;
    }

    // Метод для удаления элемента (по индексу)
    void remove(int index) {
        if (index >= 0 && index < (int)group.size()) {
            delete group[index];
            group.erase(group.begin() + index);
            cout << "Абитуриент удален. Осталось: " << group.size() << endl;
        }
        else {
            cout << "Ошибка: неверный индекс!" << endl;
        }
    }

    // Перегрузка операции для получения размера группы
    int operator~() const {
        return group.size();
    }

    // Метод для просмотра группы
    void view() const {
        if (group.empty()) {
            cout << "Группа пуста." << endl;
            return;
        }
        cout << "\n=== Список абитуриентов ===" << endl;
        for (size_t i = 0; i < group.size(); i++) {
            cout << i + 1 << ". ";
            group[i]->output();
            cout << endl;
        }
        cout << "Всего: " << group.size() << endl;
    }

    // Вывод среднего возраста
    void showAverageAge() const {
        if (group.empty()) {
            cout << "Группа пуста, средний возраст = 0" << endl;
            return;
        }
        int sum = 0;
        for (auto* p : group) {
            sum += p->getAge();
        }
        cout << "Средний возраст: " << (double)sum / group.size() << endl;
    }

    // Доступ по индексу
    Abiturient* get(int index) {
        if (index >= 0 && index < (int)group.size()) {
            return group[index];
        }
        return nullptr;
    }
};

// 5. Класс Диалог – наследник группы
class Dialog : public Tree {
public:
    void processCommand(const string& cmd) {
        if (cmd.empty()) return;

        char command = cmd[0];

        switch (command) {
        case 'm': // Создать группу (m количество)
        {
            int n = stoi(cmd.substr(2));
            for (auto* p : group) delete p;
            group.clear();
            for (int i = 0; i < n; i++) {
                cout << "\n=== Ввод данных абитуриента " << i + 1 << " ===" << endl;
                Abiturient* a = new Abiturient();
                a->input();
                group.push_back(a);
            }
            cout << "Создана группа из " << n << " абитуриентов." << endl;
        }
        break;

        case '+': // Добавить элемент
        {
            Abiturient* a = new Abiturient();
            a->input();
            add(a);
        }
        break;

        case '-': // Удалить элемент
        {
            view();
            int index;
            cout << "Введите номер для удаления: ";
            cin >> index;
            remove(index - 1);
        }
        break;

        case 's': // Вывести информацию
            view();
            break;

        case 'z': // Вывести средний возраст
            showAverageAge();
            break;

        default:
            cout << "Неизвестная команда!" << endl;
            break;
        }
    }

    void run() {
        string cmd;
        cout << "\n=== ДОБРО ПОЖАЛОВАТЬ ===" << endl;
        cout << "Доступные команды:" << endl;
        cout << "  m N  - создать группу из N элементов" << endl;
        cout << "  +    - добавить абитуриента" << endl;
        cout << "  -    - удалить абитуриента" << endl;
        cout << "  s    - вывести информацию о группе" << endl;
        cout << "  z    - вывести средний возраст" << endl;
        cout << "  exit - выход" << endl;
        cout << "========================" << endl;

        while (true) {
            cout << "\nВведите команду: ";
            getline(cin, cmd);
            if (cmd == "exit") {
                cout << "До свидания!" << endl;
                break;
            }
            processCommand(cmd);
        }
    }
};

// 7. Тестирующая программа
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");

    Dialog d;
    d.run();

    return 0;
}