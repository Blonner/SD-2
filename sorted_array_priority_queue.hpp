#pragma once
#ifndef SORTED_ARRAY_PRIORITY_QUEUE_HPP
#define SORTED_ARRAY_PRIORITY_QUEUE_HPP

#include "element.hpp"
#include <iostream>

class SortedArrayPriorityQueue {
private:
    Element* array;     // tablica elementow
    int capacity;       // max rozmiar
    int size;           // aktualny rozmiar
    int insertCounter;  // licznik dla FIFO

    // powiekszenie tablicy
    void resize();

    // znajdowanie elementu
    int findIndex(int value);

public:
    // inicjalizacja
    SortedArrayPriorityQueue(int initialCapacity = 10);

    // czyszczenie pamieci
    ~SortedArrayPriorityQueue();

    // dodanie elementu
    void insert(int element, int priority);

    // pobranie i usuniecie max
    Element extractMax();

    // podglad max
    Element findMax();

    // zmiana priorytetu
    bool modifyKey(int element, int newPriority);

    // pobranie rozmiaru
    int returnSize() { return size; }

    // wypisanie elementow
    void display();

    // sprawdzenie czy pusta
    bool isEmpty() { return size == 0; }
};

#endif // SORTED_ARRAY_PRIORITY_QUEUE_HPP