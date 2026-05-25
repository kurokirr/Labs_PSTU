#include <iostream>
#include <clocale>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введите элементы отсортированного массива: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Введите искомый элемент: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
    {
        cout << "Элемент найден, индекс: " << result << endl;
    }
    else
    {
        cout << "Элемент не найден" << endl;
    }

    delete[] arr;

    return 0;
}