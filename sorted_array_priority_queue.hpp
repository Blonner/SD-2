#pragma once
#ifndef SORTED_ARRAY_PRIORITY_QUEUE_HPP
#define SORTED_ARRAY_PRIORITY_QUEUE_HPP

#include "element.hpp"
#include <iostream>

class SortedArrayPriorityQueue {
private:
    Element* array;     // Tablica elementow
    int capacity;       // Pojemnosc tablicy
    int size;           // Liczba elementow
    int insertCounter;  // Licznik wstawien (FIFO)

    // Zwiekszenie pojemnosci
    void resize();

    // Szukanie indeksu elementu
    int findIndex(int value);

public:
    // Konstruktor
    SortedArrayPriorityQueue(int initialCapacity = 10);

    // Destruktor
    ~SortedArrayPriorityQueue();

    // Dodawanie elementu
    void insert(int element, int priority);

    // Usuwanie maksimum
    Element extractMax();

    // Podglad maksimum
    Element findMax();

    // Zmiana priorytetu
    bool modifyKey(int element, int newPriority);

    // Aktualny rozmiar
    int returnSize() { return size; }

    // Wyswietlanie zawartosci
    void display();

    // Sprawdzenie czy pusta
    bool isEmpty() { return size == 0; }
};

#endif // SORTED_ARRAY_PRIORITY_QUEUE_HPP