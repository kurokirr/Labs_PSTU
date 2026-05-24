#include <iostream>
#include <clocale>
#include <cmath>
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

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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

struct Bucket {
    int* elements;
    int size;
    int capacity;

    void init() {
        capacity = 10;
        size = 0;
        elements = new int[capacity];
    }

    void add(int value) {
        if (size >= capacity) {
            capacity *= 2;
            int* newElements = new int[capacity];
            for (int i = 0; i < size; i++)
                newElements[i] = elements[i];
            delete[] elements;
            elements = newElements;
        }
        elements[size++] = value;
    }

    void cleanup() {
        delete[] elements;
    }
};

void bucketSort(int arr[], int size) {
    cout << "Исходный массив: ";
    printArray(arr, size);

    if (size <= 1) return;

    int minVal = findMin(arr, size);
    int maxVal = findMax(arr, size);
    int numBuckets = max(1, (int)sqrt(size));

    cout << "\nПараметры: min=" << minVal << ", max=" << maxVal << ", корзин=" << numBuckets << endl;

    Bucket* buckets = new Bucket[numBuckets];
    for (int i = 0; i < numBuckets; i++)
        buckets[i].init();

    double range = (double)(maxVal - minVal) / numBuckets;

    cout << "\nШаг 1: Распределяем элементы по корзинам" << endl;
    for (int i = 0; i < size; i++) {
        int bucketIndex;
        if (arr[i] == maxVal) {
            bucketIndex = numBuckets - 1;
        }
        else {
            bucketIndex = (int)((arr[i] - minVal) / range);
            if (bucketIndex >= numBuckets) bucketIndex = numBuckets - 1;
        }
        buckets[bucketIndex].add(arr[i]);
        cout << "  " << arr[i] << " -> корзина " << bucketIndex << endl;
    }

    cout << "\nШаг 2: Сортируем каждую корзину" << endl;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].size > 0) {
            cout << "  Корзина " << i << " до сортировки: ";
            printArray(buckets[i].elements, buckets[i].size);
            insertionSort(buckets[i].elements, buckets[i].size);
            cout << "  Корзина " << i << " после сортировки: ";
            printArray(buckets[i].elements, buckets[i].size);
        }
    }

    cout << "\nШаг 3: Собираем элементы из корзин" << endl;
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++)
            arr[index++] = buckets[i].elements[j];
        cout << "  После корзины " << i << ": ";
        printArray(arr, size);
        buckets[i].cleanup();
    }

    delete[] buckets;

    cout << "\nРезультат блочной сортировки: ";
    printArray(arr, size);
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43, 15, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

    return 0;
}