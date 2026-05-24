#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void push_front(struct Node** head, struct Node** tail, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }
    else {
        *tail = newNode;
    }
    *head = newNode;
    cout << "Добавлено: " << value << endl;
}

void push_back(struct Node** head, struct Node** tail, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = *tail;
    newNode->next = nullptr;

    if (*tail != nullptr) {
        (*tail)->next = newNode;
    }
    else {
        *head = newNode;
    }
    *tail = newNode;
    cout << "Добавлено: " << value << endl;
}

void insert_after(struct Node** head, struct Node** tail, int afterValue, int newValue) {
    if (*head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }

    struct Node* current = *head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Элемент " << afterValue << " не найден!" << endl;
        return;
    }

    struct Node* newNode = new Node;
    newNode->data = newValue;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    else {
        *tail = newNode;
    }
    current->next = newNode;

    cout << "Вставлено: " << newValue << " после " << afterValue << endl;
}

void delete_by_value(struct Node** head, struct Node** tail, int value) {
    if (*head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }

    struct Node* current = *head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Элемент " << value << " не найден!" << endl;
        return;
    }

    if (current->prev == nullptr && current->next == nullptr) {
        *head = nullptr;
        *tail = nullptr;
    }
    else if (current->prev == nullptr) {
        *head = current->next;
        current->next->prev = nullptr;
    }
    else if (current->next == nullptr) {
        *tail = current->prev;
        current->prev->next = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Удалено: " << value << endl;
}

void find_element(struct Node* head, int value) {
    struct Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Найдено: " << value << " на позиции " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }

    cout << "Не найдено: " << value << endl;
}

void print_list(struct Node* head) {
    if (head == nullptr) {
        cout << "Список: пуст" << endl;
        return;
    }

    struct Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void clear_list(struct Node** head, struct Node** tail) {
    struct Node* current = *head;
    struct Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    *head = nullptr;
    *tail = nullptr;
    cout << "Список очищен" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    struct Node* head = nullptr;
    struct Node* tail = nullptr;

    // Добавление элементов
    push_back(&head, &tail, 10);
    push_back(&head, &tail, 20);
    push_back(&head, &tail, 30);
    push_front(&head, &tail, 5);

    cout << "Список: ";
    print_list(head);

    // Вставка после найденного
    insert_after(&head, &tail, 20, 25);
    cout << "После вставки 25 после 20: ";
    print_list(head);

    // Удаление элемента
    delete_by_value(&head, &tail, 20);
    cout << "После удаления 20: ";
    print_list(head);

    // Очистка списка
    clear_list(&head, &tail);
    cout << "После очистки: ";
    print_list(head);

    return 0;
}