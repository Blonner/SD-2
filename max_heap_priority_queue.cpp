#include "max_heap_priority_queue.hpp"
#include <iostream>

using namespace std;

// konstruktor
MaxHeapPriorityQueue::MaxHeapPriorityQueue(int initialCapacity) {
    // init wartosci
    capacity = initialCapacity;
    heap = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// destruktor
MaxHeapPriorityQueue::~MaxHeapPriorityQueue() {
    // zwolnienie pamieci
    delete[] heap;
}

// naprawa kopca w gore
void MaxHeapPriorityQueue::heapifyUp(int i) {
    // TODO: implementacja
    // przesuwanie elementu w gore
}

// naprawa kopca w dol
void MaxHeapPriorityQueue::heapifyDown(int i) {
    // TODO: implementacja
    // przesuwanie elementu w dol
}

// zwiekszenie pojemnosci
void MaxHeapPriorityQueue::resize() {
    // podwojenie pojemnosci
    int newCapacity = capacity * 2;
    Element* newHeap = new Element[newCapacity];

    // kopiowanie elementow
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }

    // aktualizacja wskaznikow
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

// szukanie indeksu elementu
int MaxHeapPriorityQueue::findIndex(int value) {
    // liniowe przeszukiwanie
    for (int i = 0; i < size; i++) {
        if (heap[i].value == value) {
            return i;
        }
    }
    return -1; // nie znaleziono
}

// dodawanie elementu
void MaxHeapPriorityQueue::insert(int element, int priority) {
    // sprawdzenie pojemnosci
    if (size == capacity) {
        resize();
    }

    // dodanie na koniec
    insertCounter++;
    heap[size] = Element(element, priority, insertCounter);
    
    // TODO: naprawa kopca
    size++;
}

// usuwanie max elementu
Element MaxHeapPriorityQueue::extractMax() {
    if (size <= 0) {
        // kolejka pusta
        cerr << "Blad: Kolejka pusta" << endl;
        return Element();
    }

    // TODO: implementacja usuwania max
    return Element();
}

// podglad max elementu
Element MaxHeapPriorityQueue::findMax() {
    if (size <= 0) {
        // kolejka pusta
        cerr << "Blad: Kolejka pusta" << endl;
        return Element();
    }

    // max element na poczatku
    return heap[0];
}

// zmiana priorytetu
bool MaxHeapPriorityQueue::modifyKey(int element, int newPriority) {
    // TODO: implementacja zmiany priorytetu
    return false;
}

// wyswietlanie
void MaxHeapPriorityQueue::display() {
    cout << "Zawartosc kolejki (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << heap[i].value << ", " << heap[i].priority << ") ";
    }
    cout << endl;
}