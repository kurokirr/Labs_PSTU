#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	int n;
	cout << "Размер массива: ";
	cin >> n;
	cin.ignore();
	string* arr = new string[n];
	for (int i = 0; i < n; i++) {
		cout << "Строка " << i + 1 << ": ";
		getline(cin, arr[i]);
	}
	cout << "Исходный массив :" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

	string* newArr = new string[n];
	int newIndex = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i][0] != 'а' && arr[i][0] != 'А') {
			newArr[newIndex] = arr[i];
			newIndex++;
		}
	}
	cout << "\nМассив после удаления строк, начинающихся на 'а':" << endl;
	if (n == 0) {
		cout << "Массив пуст" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << newArr[i] << endl;
		}
	}

	delete[] arr;
	delete[] newArr;

	return 0;
}
