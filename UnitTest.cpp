#include <gtest/gtest.h>
#include "CircularList.h"

// Тест на перевірку ініціалізації вузла (через створення списку з 1 елемента)
TEST(CircularListTest, TestIncrement) {
    // Створюємо список вручну для тесту, щоб не вводити дані з консолі
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    
    head->next = second;
    second->next = head; // Замикаємо кільце

    // Виконуємо дію варіанту 14 (збільшення на 5)
    incrementListValues(head, 5);

    EXPECT_EQ(head->data, 15);
    EXPECT_EQ(second->data, 25);

    deleteCircularList(head);
}

// Тест на порожній список
TEST(CircularListTest, TestEmptyList) {
    Node* head = nullptr;
    // Функція не має "ламатися" при отриманні nullptr
    incrementListValues(head, 100);
    EXPECT_EQ(head, nullptr);
}

// Тест на циклічність
TEST(CircularListTest, TestCircularity) {
    Node* head = new Node{1, nullptr};
    head->next = head; // Кільце з одного елемента

    incrementListValues(head, 10);
    
    EXPECT_EQ(head->data, 11);
    EXPECT_EQ(head->next, head); // Перевірка, що зв'язок не розірвано

    deleteCircularList(head);
}