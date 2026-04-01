#include "CircularList.h"
#include <iostream>

Node* createCircularList(int n) {
    if (n <= 0) return nullptr;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        // Виділяємо пам'ять під новий вузол
        Node* newNode = new Node;
        std::cout << "Введіть значення [" << i + 1 << "]: ";
        std::cin >> newNode->data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Замикаємо на себе (перший елемент)
            tail = head;
        } else {
            tail->next = newNode; // Попередній вказує на новий
            newNode->next = head; // Новий вказує на початок (кільце)
            tail = newNode;       // Зміщуємо покажчик хвоста
        }
    }
    return head;
}

void printCircularList(Node* head) {
    if (!head) {
        std::cout << "Список порожній." << std::endl;
        return;
    }

    Node* current = head;
    // Використовуємо do-while, бо умова завершення (current == head) 
    // істинна вже на старті. Нам треба спочатку зайти в цикл.
    do {
        std::cout << "[" << current->data << "] -> ";
        current = current->next;
    } while (current != head);
    
    std::cout << "(повернення до head: " << head->data << ")" << std::endl;
}

void incrementListValues(Node* head, int delta) {
    if (!head) return;

    Node* current = head;
    do {
        // Безпосередня модифікація інформаційного поля
        current->data += delta;
        current = current->next;
    } while (current != head);
}

void deleteCircularList(Node*& head) {
    if (!head) return;

    Node* current = head;
    Node* nextNode;

    // Спершу розриваємо кільце, щоб не ходити по колу вічно
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = nullptr; // Тепер це лінійний список

    // Видаляємо вузли стандартним ітераційним способом
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}