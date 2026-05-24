#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <string>
#include <cstring>
#include <cctype> 
using namespace std;

int main() {

    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "Russian");
    string str;

    cout << "Введите строку: ";
    getline(cin, str);

    char words[100][50];
    int wordCount = 0;

    int i = 0;

    while (i < str.length()) 
    {
        while (i < str.length() && str[i] == ' ')
        {
            i++;
        }
        if (i >= str.length() || str[i] == '.')
            break;

        int j = 0;

        while (i < str.length() && str[i] != ' ' && str[i] != '.') {
            words[wordCount][j++] = str[i++];
        }

        words[wordCount][j] = '\0';
        wordCount++;
    }

    // Сортировка слов, начинающихся с буквы
    for (int a = 0; a < wordCount - 1; a++) {
        for (int b = a + 1; b < wordCount; b++) {

            if (isalpha((unsigned char)words[a][0]) && isalpha((unsigned char)words[b][0])) {

                if (strcmp(words[a], words[b]) > 0) {
                    char temp[50];
                    strcpy(temp, words[a]);
                    strcpy(words[a], words[b]);
                    strcpy(words[b], temp);
                }
            }
        }
    }

    // Вывод результата
    cout << "\nРезультат:\n";
    for (int k = 0; k < wordCount; k++) {
        cout << words[k] << " ";
    }
    cout << "." << endl;

    return 0;
}