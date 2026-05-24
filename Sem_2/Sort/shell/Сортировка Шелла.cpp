#include <iostream>
#include <clocale>
using namespace std;

void shellSort(int arr[], int size, int& step)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        cout << "Шаг " << step++ << ": Интервал = " << gap << endl;

        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;

            cout << "\n  Вставляем элемент arr[" << i << "] = " << temp << endl;
            cout << "  Сравниваем с элементами на расстоянии " << gap << endl;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                cout << "    arr[" << j - gap << "] = " << arr[j - gap] << " > " << temp << "? Да" << endl;
                cout << "    Сдвигаем arr[" << j << "] = " << arr[j - gap] << " (копируем из arr[" << j - gap << "])" << endl;
                arr[j] = arr[j - gap];
                cout << "    Текущий массив: ";
                for (int k = 0; k < size; k++) cout << arr[k] << " ";
                cout << endl;
            }

            if (j >= gap)
            {
                cout << "    arr[" << j - gap << "] = " << arr[j - gap] << " > " << temp << "? Нет" << endl;
            }

            if (j != i)
            {
                cout << "  Вставляем " << temp << " на позицию arr[" << j << "]" << endl;
                arr[j] = temp;
                cout << "  Текущий массив: ";
                for (int k = 0; k < size; k++) cout << arr[k] << " ";
                cout << endl;
            }
            else
            {
                cout << "  Элемент уже на своем месте, ничего не меняем" << endl;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arrShell = new int[size];

    cout << "Введите " << size << " элементов: ";
    for (int i = 0; i < size; i++) {
        cin >> arrShell[i];
    }

    cout << "\n\n";
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) cout << arrShell[i] << " ";
    cout << endl;

    int step = 1;
    shellSort(arrShell, size, step);

    cout << "Результат сортировки Шелла: ";
    for (int i = 0; i < size; i++) cout << arrShell[i] << " ";
    cout << endl;

    delete[] arrShell;
    return 0;
}