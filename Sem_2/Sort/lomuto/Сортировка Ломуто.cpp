#include <iostream>
#include <clocale>
using namespace std;

int partitionLomuto(int arr[], int low, int high, int size, int& step)
{
    int pI = high;
    int pivot = arr[pI];
    cout << "\nРазбиение подмассива с " << low << " по " << high << endl;
    cout << "Шаг " << step++ << ": pivot = " << pivot << " (индекс " << pI << ", последний элемент)" << endl;
    cout << "Текущий массив: ";
    for (int k = 0; k < size; k++) cout << arr[k] << " ";
    cout << endl;

    for (int j = low; j < pI; j++)
    {
        cout << "\n  Сравниваем arr[" << j << "] = " << arr[j] << " с pivot = " << pivot << ": ";
        if (arr[j] > pivot) {
            cout << arr[j] << " > " << pivot << endl;
            cout << "  Меняем arr[" << pI - 1 << "]=" << arr[pI - 1] << " и arr[" << j << "]=" << arr[j] << endl;
            swap(arr[pI - 1], arr[j]);
            cout << "  После обмена: ";
            for (int k = 0; k < size; k++) cout << arr[k] << " ";
            cout << endl;
            cout << "  Меняем pivot arr[" << pI << "]=" << arr[pI] << " с arr[" << pI - 1 << "]=" << arr[pI - 1] << endl;
            swap(arr[pI], arr[pI - 1]);
            pI--;
            j--;
            cout << "  После перемещения pivot: ";
            for (int k = 0; k < size; k++) cout << arr[k] << " ";
            cout << endl;
            cout << " pivot переместился на индекс " << pI << endl;
        }
        else
        {
            cout << arr[j] << " <= " << pivot << endl;
            cout << "  Ничего не меняем, идем дальше" << endl;
        }
    }
    cout << "\n  pivot " << pivot << " встал на позицию " << pI << endl;
    return pI;
}

void quickSortLomuto(int arr[], int low, int high, int size, int& step)
{
    if (low < high)
    {
        int pI = partitionLomuto(arr, low, high, size, step);
        quickSortLomuto(arr, low, pI - 1, size, step);
        quickSortLomuto(arr, pI + 1, high, size, step);
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arrLomuto = new int[size];

    cout << "Введите " << size << " элементов: ";
    for (int i = 0; i < size; i++) {
        cin >> arrLomuto[i];
    }

    cout << "\n\n";
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) cout << arrLomuto[i] << " ";
    cout << endl;

    int step = 1;
    quickSortLomuto(arrLomuto, 0, size - 1, size, step);

    cout << "Результат сортировки Ломуто: ";
    for (int i = 0; i < size; i++) cout << arrLomuto[i] << " ";
    cout << endl;

    delete[] arrLomuto;
    return 0;
}