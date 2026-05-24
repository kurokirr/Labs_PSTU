#include <iostream>
#include <clocale>
using namespace std;

void printArray(int arr[], int size, const char* message = "") {
    if (message[0] != '\0') cout << message;
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "]" << endl;
}

void printOutputArray(int arr[], int size, int filledCount, const char* message = "") {
    if (message[0] != '\0') cout << message;
    cout << "[";
    for (int i = 0; i < size; i++) {
        if (i < filledCount) cout << arr[i];
        else cout << "\033[90m-\033[0m";
        if (i < size - 1) cout << " ";
    }
    cout << "]" << endl;
}

int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < minVal) minVal = arr[i];
    return minVal;
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int size) {
    cout << "Исходный массив: ";
    printArray(arr, size);

    if (size <= 1) return;

    int minVal = findMin(arr, size);
    int maxVal = findMax(arr, size);
    int range = maxVal - minVal + 1;

    cout << "\nШаг 1: Находим min=" << minVal << ", max=" << maxVal << ", range=" << range << endl;

    int* count = new int[range]();

    cout << "\nШаг 2: Подсчитываем количество каждого элемента" << endl;
    for (int i = 0; i < size; i++) {
        count[arr[i] - minVal]++;
        cout << "  arr[" << i << "]=" << arr[i] << " -> count[" << arr[i] - minVal << "]=" << count[arr[i] - minVal] << endl;
    }

    cout << "\n  Массив count: [";
    for (int i = 0; i < range; i++) {
        cout << count[i];
        if (i < range - 1) cout << " ";
    }
    cout << "]" << endl;

    cout << "\nШаг 3: Преобразуем в префиксные суммы" << endl;
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
        cout << "  count[" << i << "] = " << count[i] << endl;
    }

    cout << "\nШаг 4: Строим отсортированный массив (пустые позиции обозначены -)" << endl;
    int* output = new int[size]();

    for (int i = size - 1; i >= 0; i--) {
        int val = arr[i];
        int pos = count[val - minVal] - 1;
        output[pos] = val;
        count[val - minVal]--;

        cout << "  Ставим " << val << " на позицию " << pos << endl;
        cout << "  Текущий output: ";
        printOutputArray(output, size, pos + 1, "");
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];

    delete[] count;
    delete[] output;

    cout << "\nРезультат сортировки подсчетом: ";
    printArray(arr, size);
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 4, 2, 2, 8, 3, 3, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, size);

    return 0;
}