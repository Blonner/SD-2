#pragma once
#ifndef MAX_HEAP_PRIORITY_QUEUE_HPP
#define MAX_HEAP_PRIORITY_QUEUE_HPP

#include "element.hpp"
#include <iostream>

class MaxHeapPriorityQueue {
private:
    Element* heap;      // tablica kopca
    int capacity;       // pojemnosc
    int size;           // liczba elementow
    int insertCounter;  // licznik wstawien

    // indeks rodzica
    int parent(int i) { return (i - 1) / 2; }

    // indeks lewego dziecka
    int leftChild(int i) { return 2 * i + 1; }

    // indeks prawego dziecka
    int rightChild(int i) { return 2 * i + 2; }

    // naprawa kopca w gore
    void heapifyUp(int i);

    // naprawa kopca w dol
    void heapifyDown(int i);

    // zwiekszenie pojemnosci
    void resize();

    // szukanie indeksu elementu
    int findIndex(int value);

public:
    // konstruktor
    MaxHeapPriorityQueue(int initialCapacity = 10);

    // destruktor
    ~MaxHeapPriorityQueue();

    // dodawanie elementu
    void insert(int element, int priority);

    // usuwanie max elementu
    Element extractMax();

    // podglad max elementu
    Element findMax();

    // zmiana priorytetu
    bool modifyKey(int element, int newPriority);

    // rozmiar kolejki
    int returnSize() { return size; }

    // wyswietlanie
    void display();

    // czy pusta
    bool isEmpty() { return size == 0; }
};

#endif // MAX_HEAP_PRIORITY_QUEUE_HPP