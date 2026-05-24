#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int max_size = 100; // Максимальный размер массива
    int arr[max_size];
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Введите K (от 1 до " << n << "): ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Ошибочный ввод числа k" << endl;
        return 1;
    }

    // Распечатываем массив, начиная с K-ого элемента и до K-1
    cout << "Массив начиная с " << k << "-го элемента: ";
    for (int i = k - 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < k - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int firstElement = arr[0];
    int lastElement = arr[n - 1];

    // Добавляем элементы в конец
    arr[n] = firstElement;     // Добавляем первый элемент
    arr[n + 1] = lastElement;  // Добавляем последний элемент
    n += 2;                    // Увеличиваем размер массива

    cout << "Массив после добавления первого и последнего элементов: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Удаляем четные элементы
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)  // Если элемент четный
        {
            // Сдвигаем все элементы влево
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;    // Уменьшаем размер массива
            i--;    // Проверяем тот же индекс снова
        }
    }

    // Распечатываем полученный массив, начиная с K-ого элемента и до K-1
    // Проверяем, что k не больше нового размера массива
    if (k > n)
    {
        k = n;  // Корректируем k, если нужно
        cout << "K было скорректировано до " << k << endl;
    }

    cout << "Массив без четных чисел, начиная с " << k << "-го элемента: ";
    for (int i = k - 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < k - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}