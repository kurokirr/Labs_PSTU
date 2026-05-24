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

void merge(int arr[], int left, int mid, int right, int size) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    cout << "\n    Слияние: левая часть [";
    for (int i = 0; i < n1; i++) cout << leftArr[i] << " ";
    cout << "] правая часть [";
    for (int i = 0; i < n2; i++) cout << rightArr[i] << " ";
    cout << "]" << endl;

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    cout << "    Результат слияния: ";
    printArray(arr, size);

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << "\n  Разделяем: [" << left << ".." << mid << "] и [" << mid + 1 << ".." << right << "]" << endl;

        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
}

void mergeSort(int arr[], int size) {
    cout << "Исходный массив: ";
    printArray(arr, size);
    cout << "\nАлгоритм: рекурсивно делим массив пополам, затем сливаем" << endl;

    mergeSort(arr, 0, size - 1, size);

    cout << "\nРезультат сортировки слиянием: ";
    printArray(arr, size);
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 38, 27, 43, 3, 9, 82, 10, 15, 7, 21 };
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);

    return 0;
}