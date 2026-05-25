#include <iostream>
#include <string>
#include <clocale>
using namespace std;

class Abiturient {
private:
    string fio;
    string speciality;
    int score;

public:
    Abiturient() {
        fio = "Неизвестно";
        speciality = "Не выбрана";
        score = 0;
    }

    Abiturient(string f, string s, int sc) {
        fio = f;
        speciality = s;
        score = sc;
    }

    Abiturient(const Abiturient& other) {
        fio = other.fio;
        speciality = other.speciality;
        score = other.score;
    }

    ~Abiturient() {
        cout << "Объект удален: " << fio << endl;
    }

    string getFio() {
        return fio;
    }

    string getSpeciality() {
        return speciality;
    }

    int getScore() {
        return score;
    }

    void setFio(string f) {
        fio = f;
    }

    void setSpeciality(string s) {
        speciality = s;
    }

    void setScore(int sc) {
        score = sc;
    }

    void Show() {
        cout << "ФИО: " << fio << endl;
        cout << "Специальность: " << speciality << endl;
        cout << "Балл ЕГЭ: " << score << endl;
    }
};

void PrintAbiturient(Abiturient a) {
    a.Show();
}

Abiturient CreateCopy(Abiturient a) {
    return a;
}

int main() {
    setlocale(LC_ALL, "RUS");

    Abiturient a1;
    a1.Show();

    cout << endl;

    Abiturient a2("Иванов Иван Иванович", "Программная инженерия", 270);
    a2.Show();
    cout << endl;

    Abiturient a3 = a2;
    a3.Show();
    cout << endl;

    PrintAbiturient(a2);
    cout << endl;

    Abiturient a4 = CreateCopy(a2);
    a4.Show();

    return 0;
}