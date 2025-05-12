#pragma once
#ifndef MAX_HEAP_PRIORITY_QUEUE_HPP
#define MAX_HEAP_PRIORITY_QUEUE_HPP

#include "element.hpp"
#include <iostream>

class MaxHeapPriorityQueue {
private:
    Element* heap;      // tablica kopca
    int capacity;       // max rozmiar
    int size;           // aktualny rozmiar
    int insertCounter;  // licznik dla FIFO

    // indeks rodzica
    int parent(int i) { return (i - 1) / 2; }

    // indeks lewego dziecka
    int leftChild(int i) { return 2 * i + 1; }

    // indeks prawego dziecka
    int rightChild(int i) { return 2 * i + 2; }

    // przywracanie wlasnosci kopca w gore
    void heapifyUp(int i);

    // przywracanie wlasnosci kopca w dol
    void heapifyDown(int i);

    // powiekszenie tablicy
    void resize();

    // znajdowanie elementu
    int findIndex(int value);

public:
    // inicjalizacja
    MaxHeapPriorityQueue(int initialCapacity = 10);

    // czyszczenie pamieci
    ~MaxHeapPriorityQueue();

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

#endif // MAX_HEAP_PRIORITY_QUEUE_HPP