#pragma once
#ifndef SORTED_ARRAY_PRIORITY_QUEUE_HPP
#define SORTED_ARRAY_PRIORITY_QUEUE_HPP

#include "element.hpp"

class SortedArrayPriorityQueue {
private:
    Element* array;     // dynamiczna tablica przechowująca elementy
    int capacity;       // pojemność tablicy
    int size;           // aktualna liczba elementów

public:
    // Konstruktor
    SortedArrayPriorityQueue(int initialCapacity = 10);

    // Destruktor
    ~SortedArrayPriorityQueue();

    // Dodaje element o podanej wartości i priorytecie
    void insert(int element, int priority);

    // Usuwa i zwraca element o najwyższym priorytecie
    Element extractMax();

    // Zwraca rozmiar kolejki
    int returnSize() { return size; }

    // Wyświetla zawartość kolejki
    void display();
};

#endif // SORTED_ARRAY_PRIORITY_QUEUE_HPP
