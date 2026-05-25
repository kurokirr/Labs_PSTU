#include <iostream>
#include <string>
#include <clocale>
using namespace std;

void ShiftTable(const string& pattern, int shiftTable[]) {
    int patternLen = pattern.length();
    for (int i = 0; i < 256; i++)
    {
        shiftTable[i] = patternLen;
    }

    for (int i = 0; i < patternLen - 1; i++)
    {
        shiftTable[(unsigned char)pattern[i]] = patternLen - 1 - i;
    }
}

int horspoolSearch(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen > textLen) {
        cout << "Подстрока длиннее строки" << endl;
        return -1;
    }

    int shiftTable[256];
    ShiftTable(pattern, shiftTable);

    int pos = 0;
    while (pos <= textLen - patternLen)
    {
        int j = patternLen - 1;
        while (j >= 0 && pattern[j] == text[pos + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "Подстрока найдена, номер первого элемента: " << pos + 1 << endl;
            return pos;
        }
        char badChar = text[pos + patternLen - 1];
        int shift = shiftTable[(unsigned char)badChar];
        pos += shift;
    }
    cout << "Подстрока не найдена" << endl;
    return -1;
}

int main()
{
    string str;
    string podstr;
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");

    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите подстроку: ";
    getline(cin, podstr);

    cout << "\nМетод Бойера-Мура-Хорспула: " << endl;
    horspoolSearch(str, podstr);

    return 0;
}