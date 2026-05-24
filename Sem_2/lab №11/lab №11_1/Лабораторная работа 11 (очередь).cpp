#include <iostream>
#include <clocale>

using namespace std;

// Структура узла очереди
struct Node {
    int data;
    Node* next;

    // Конструктор
    Node(int value) : data(value), next(nullptr) {}
};

// Структура очереди
struct Queue {
    Node* front;  // указатель на начало очереди
    Node* rear;   // указатель на конец очереди
    int size;     // размер очереди

    // Конструктор
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Деструктор
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Добавление элемента в очередь
    void push(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Удаление элемента из очереди
    void pop() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    // Получение первого элемента
    int frontElement() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return -1;
        }
        return front->data;
    }

    // Проверка на пустоту
    bool isEmpty() {
        return front == nullptr;
    }

    // Получение размера очереди
    int getSize() {
        return size;
    }

    // Вывод всех элементов очереди
    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста" << endl;
            return;
        }

        Node* current = front;
        cout << "Очередь: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    setlocale(LC_ALL, "RU");

    cout << "=== Тестирование очереди ===" << endl;

    // Создаем очередь
    Queue q;

    cout << "\n1. Проверка пустой очереди:" << endl;
    cout << "Очередь пуста? " << (q.isEmpty() ? "Да" : "Нет") << endl;
    cout << "Размер очереди: " << q.getSize() << endl;

    cout << "\n2. Добавляем элементы в очередь:" << endl;
    q.push(10);
    cout << "Добавлено: 10" << endl;
    q.push(20);
    cout << "Добавлено: 20" << endl;
    q.push(30);
    cout << "Добавлено: 30" << endl;
    q.push(40);
    cout << "Добавлено: 40" << endl;
    q.push(50);
    cout << "Добавлено: 50" << endl;

    q.display();
    cout << "Размер очереди: " << q.getSize() << endl;
    cout << "Первый элемент: " << q.frontElement() << endl;

    cout << "\n3. Удаляем элементы из очереди:" << endl;
    q.pop();
    cout << "Удален первый элемент" << endl;
    q.display();
    cout << "Первый элемент теперь: " << q.frontElement() << endl;
    cout << "Размер очереди: " << q.getSize() << endl;

    q.pop();
    cout << "Удален первый элемент" << endl;
    q.display();

    cout << "\n4. Добавляем еще элементы:" << endl;
    q.push(60);
    cout << "Добавлено: 60" << endl;
    q.push(70);
    cout << "Добавлено: 70" << endl;
    q.display();
    cout << "Размер очереди: " << q.getSize() << endl;

    cout << "\n5. Удаляем все элементы:" << endl;
    while (!q.isEmpty()) {
        cout << "Удаляем: " << q.frontElement() << endl;
        q.pop();
    }

    cout << "\n6. Проверка после удаления всех элементов:" << endl;
    q.display();
    cout << "Очередь пуста? " << (q.isEmpty() ? "Да" : "Нет") << endl;
    cout << "Размер очереди: " << q.getSize() << endl;

    cout << "\n7. Тест на удаление из пустой очереди:" << endl;
    q.pop(); // Попытка удалить из пустой очереди

    cout << "\n8. Тест на получение элемента из пустой очереди:" << endl;
    int front = q.frontElement(); // Попытка получить элемент из пустой очереди

    cout << "\n=== Тестирование завершено ===" << endl;

    return 0;
}