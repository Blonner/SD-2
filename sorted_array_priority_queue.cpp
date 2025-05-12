#include "sorted_array_priority_queue.hpp"
#include <iostream>

using namespace std;

// konstruktor
SortedArrayPriorityQueue::SortedArrayPriorityQueue(int initialCapacity) {
    // init wartosci
    capacity = initialCapacity;
    array = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// destruktor
SortedArrayPriorityQueue::~SortedArrayPriorityQueue() {
    // zwolnienie pamieci
    delete[] array;
}

// zwiekszenie pojemnosci
void SortedArrayPriorityQueue::resize() {
    // podwojenie pojemnosci
    int newCapacity = capacity * 2;
    Element* newArray = new Element[newCapacity];

    // kopiowanie elementow
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    // aktualizacja wskaznikow
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// szukanie indeksu elementu
int SortedArrayPriorityQueue::findIndex(int value) {
    // liniowe przeszukiwanie
    for (int i = 0; i < size; i++) {
        if (array[i].value == value) {
            return i;
        }
    }
    return -1; // nie znaleziono
}

// dodawanie elementu
void SortedArrayPriorityQueue::insert(int element, int priority) {
    // TODO: implementacja wstawiania
}

// usuwanie max elementu
Element SortedArrayPriorityQueue::extractMax() {
    // TODO: implementacja usuwania max
    return Element();
}

// podglad max elementu
Element SortedArrayPriorityQueue::findMax() {
    if (size <= 0) {
        // kolejka pusta
        cerr << "Blad: Kolejka pusta" << endl;
        return Element();
    }

    // max element na poczatku
    return array[0];
}

// zmiana priorytetu
bool SortedArrayPriorityQueue::modifyKey(int element, int newPriority) {
    // TODO: implementacja zmiany priorytetu
    return false;
}

// wyswietlanie
void SortedArrayPriorityQueue::display() {
    cout << "Zawartosc kolejki (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].value << ", " << array[i].priority << ") ";
    }
    cout << endl;
}