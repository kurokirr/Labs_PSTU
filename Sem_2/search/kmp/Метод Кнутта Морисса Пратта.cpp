#include <iostream>
#include <string>
#include <clocale>
using namespace std;

void pref_func(const string& pattern, int* d)
{
    d[0] = 0;
    int j = 0, i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[j])
        {
            d[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0)
        {
            d[i] = 0;
            i++;
        }
        else
        {
            j = d[j - 1];
        }
    }
}

int KMP_Search(const string& text, const string& pattern)
{
    int* d = new int[pattern.length()];
    pref_func(pattern, d);

    int i = 0, j = 0;
    while (i < text.length())
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == pattern.length())
        {
            cout << "Подстрока найдена, номер первого элемента: " << i - pattern.length() + 1 << endl;
            delete[] d;
            return i - pattern.length();
        }
        else if (i < text.length() && pattern[j] != text[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = d[j - 1];
            }
        }
    }
    cout << "Подстрока не найдена" << endl;
    delete[] d;
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

    cout << "\nМетод Кнута-Морриса-Пратта: " << endl;
    KMP_Search(str, podstr);

    return 0;
}