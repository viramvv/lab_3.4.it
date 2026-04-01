#include <iostream>
#include "CircularList.h"

int main() {
    // Встановлення кодування для коректного відображення кирилиці (Windows)
    setlocale(LC_ALL, "Ukrainian");

    int count, increment;

    std::cout << "Скільки елементів створити? ";
    std::cin >> count;

    // 1. Формування списку
    Node* myList = createCircularList(count);

    // 2. Друк початкового стану
    std::cout << "\nПочатковий стан списку:" << std::endl;
    printCircularList(myList);

    // 3. Виконання дії (Варіант 14)
    std::cout << "\nНа скільки збільшити кожен елемент? ";
    std::cin >> increment;
    incrementListValues(myList, increment);

    // 4. Друк результату
    std::cout << "\nРезультат після оновлення:" << std::endl;
    printCircularList(myList);

    // Очищення пам'яті перед завершенням
    deleteCircularList(myList);

    return 0;
}