#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

// Структура вузла. Вибрано тип int для інформаційного поля.
struct Node {
    int data;
    Node* next;
};

// Створює кільцевий список із n елементів, запитуючи значення у користувача.
Node* createCircularList(int n);

// Виводить усі елементи списку в консоль.
void printCircularList(Node* head);

// Збільшує значення кожного елемента на delta.
// Параметри передаються явно, нелокальні змінні не використовуються.
void incrementListValues(Node* head, int delta);

// Звільняє динамічну пам'ять, виділену під список.
void deleteCircularList(Node*& head);

#endif