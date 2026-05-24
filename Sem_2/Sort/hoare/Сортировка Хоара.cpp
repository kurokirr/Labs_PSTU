#include <iostream>
#include <clocale>
using namespace std;

int partitionHoare(int arr[], int low, int high, int size, int& step)
{
    int pivotIndex = low + (high - low) / 2;
    int pivot = arr[pivotIndex];
    int i = low - 1;
    int j = high + 1;

    cout << "\nРазбиение подмассива с " << low << " по " << high << endl;
    cout << "Шаг " << step++ << ": pivot = " << pivot << " (индекс " << pivotIndex << ", средний элемент)" << endl;
    cout << "Текущий массив: ";
    for (int k = 0; k < size; k++) cout << arr[k] << " ";
    cout << endl;

    while (true)
    {
        cout << "\n  Двигаем i вправо пока arr[i] < " << pivot << endl;
        do
        {
            i++;
            if (i <= high)
            {
                cout << "    arr[" << i << "] = " << arr[i] << " < " << pivot << "? ";
                if (arr[i] < pivot) {
                    cout << "Да, продолжаем" << endl;
                }
                else
                {
                    cout << "Нет, останавливаемся на i=" << i << endl;
                }
            }
        } while (i <= high && arr[i] < pivot);

        cout << "\n  Двигаем j влево пока arr[j] > " << pivot << endl;
        do
        {
            j--;
            if (j >= low)
            {
                cout << "    arr[" << j << "] = " << arr[j] << " > " << pivot << "? ";
                if (arr[j] > pivot)
                {
                    cout << "Да, продолжаем" << endl;
                }
                else
                {
                    cout << "Нет, останавливаемся на j=" << j << endl;
                }
            }
        } while (j >= low && arr[j] > pivot);

        if (i >= j) {
            cout << "\n  i=" << i << " >= j=" << j << ", разбиение закончено" << endl;
            cout << "  Возвращаем разделитель j=" << j << endl;
            return j;
        }

        cout << "\n  Меняем местами arr[" << i << "]=" << arr[i] << " и arr[" << j << "]=" << arr[j] << endl;
        swap(arr[i], arr[j]);
        cout << "  После обмена: ";
        for (int k = 0; k < size; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

void quickSortHoare(int arr[], int low, int high, int size, int& step)
{
    if (low < high)
    {
        int pI = partitionHoare(arr, low, high, size, step);
        quickSortHoare(arr, low, pI, size, step);
        quickSortHoare(arr, pI + 1, high, size, step);
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arrHoare = new int[size];

    cout << "Введите " << size << " элементов: ";
    for (int i = 0; i < size; i++) {
        cin >> arrHoare[i];
    }

    cout << "\n\n";
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) cout << arrHoare[i] << " ";
    cout << endl;

    int step = 1;
    quickSortHoare(arrHoare, 0, size - 1, size, step);

    cout << "Результат сортировки Хоара: ";
    for (int i = 0; i < size; i++) cout << arrHoare[i] << " ";
    cout << endl;

    delete[] arrHoare;
    return 0;
}