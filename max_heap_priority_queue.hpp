#pragma once
#ifndef MAX_HEAP_PRIORITY_QUEUE_HPP
#define MAX_HEAP_PRIORITY_QUEUE_HPP

#include "element.hpp"
#include <iostream>

class MaxHeapPriorityQueue {
private:
    Element* heap;      // Tablica kopca
    int capacity;       // Pojemnosc tablicy
    int size;           // Liczba elementow
    int insertCounter;  // Licznik wstawien (FIFO)

    // Indeks rodzica
    int parent(int i) { return (i - 1) / 2; }

    // Indeks lewego dziecka
    int leftChild(int i) { return 2 * i + 1; }

    // Indeks prawego dziecka
    int rightChild(int i) { return 2 * i + 2; }

    // Naprawa kopca w gore
    void heapifyUp(int i);

    // Naprawa kopca w dol
    void heapifyDown(int i);

    // Zwiekszenie pojemnosci
    void resize();

    // Szukanie indeksu elementu
    int findIndex(int value);

public:
    // Konstruktor
    MaxHeapPriorityQueue(int initialCapacity = 10);

    // Destruktor
    ~MaxHeapPriorityQueue();

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

#endif // MAX_HEAP_PRIORITY_QUEUE_HPP