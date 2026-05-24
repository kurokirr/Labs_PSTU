#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

// Функция для проверки, есть ли в строке одинаковые слова
bool hasDuplicateWords(const string& line) {
    istringstream iss(line);
    vector<string> words;
    string word;

    // Разбиваем строку на слова
    while (iss >> word) {
        // Приводим слово к нижнему регистру для корректного сравнения
        for (char& c : word) {
            c = tolower(c);
        }
        words.push_back(word);
    }

    // Проверяем на дубликаты
    set<string> uniqueWords(words.begin(), words.end());
    return words.size() != uniqueWords.size();
}

// Функция для подсчета гласных букв в строке
int countVowels(const string& line) {
    string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    int count = 0;

    for (char c : line) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {
    system("chcp 1251"); 
    system("cls");

    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Ошибка создания файла F1.txt" << endl;
        return 1;
    }

    // Записываем 12 строк с различным содержанием
    f1 << "Это первая строка файла" << endl;
    f1 << "Здесь все слова уникальны и повторений нет" << endl;
    f1 << "Строка с повторяющимся словом строка" << endl;
    f1 << "Программирование на C++ очень интересно" << endl;
    f1 << "Солнце светит ярко сегодня солнце" << endl;
    f1 << "Мама мыла раму мыла" << endl;
    f1 << "Раз два три четыре пять" << endl;
    f1 << "Повторение мать учения мать" << endl;
    f1 << "Hello world from C++ program" << endl;
    f1 << "Эта строка содержит содержит дубликат" << endl;
    f1 << "Уникальные слова в этой строке" << endl;
    f1 << "Последняя строка для проверки" << endl;

    f1.close();
    cout << "Файл F1.txt успешно создан с 12 строками" << endl;

    // 2) Копируем из F1 в F2 строки без повторяющихся слов
    ifstream inputFile("F1.txt");
    ofstream f2("F2.txt");

    if (!inputFile.is_open() || !f2.is_open()) {
        cerr << "Ошибка открытия файлов" << endl;
        return 1;
    }

    string line;
    int copiedLines = 0;

    cout << "\nСтроки без повторяющихся слов, скопированные в F2.txt:" << endl;
    while (getline(inputFile, line)) {
        if (!hasDuplicateWords(line)) {
            f2 << line << endl;
            copiedLines++;
            cout << copiedLines << ": " << line << endl;
        }
    }

    inputFile.close();
    f2.close();

    cout << "\nВсего скопировано строк в F2.txt: " << copiedLines << endl;

    // 3) Определяем количество гласных букв в первой строке файла F2
    ifstream f2Read("F2.txt");
    if (!f2Read.is_open()) {
        cerr << "Ошибка открытия файла F2.txt для чтения" << endl;
        return 1;
    }

    string firstLine;
    if (getline(f2Read, firstLine)) {
        int vowelCount = countVowels(firstLine);
        cout << "\nПервая строка файла F2.txt: \"" << firstLine << "\"" << endl;
        cout << "Количество гласных букв в первой строке: " << vowelCount << endl;
    }
    else {
        cout << "\nФайл F2.txt пуст" << endl;
    }

    f2Read.close();

    // Дополнительно выводим содержимое созданных файлов
    cout << "\n--- Содержимое файла F1.txt ---" << endl;
    ifstream showF1("F1.txt");
    while (getline(showF1, line)) {
        cout << line << endl;
    }
    showF1.close();

    cout << "\n--- Содержимое файла F2.txt ---" << endl;
    ifstream showF2("F2.txt");
    while (getline(showF2, line)) {
        cout << line << endl;
    }
    showF2.close();

    return 0;
}