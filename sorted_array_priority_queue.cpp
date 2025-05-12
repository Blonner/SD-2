#include "sorted_array_priority_queue.hpp"
#include <iostream>

using namespace std;

// inicjalizacja
SortedArrayPriorityQueue::SortedArrayPriorityQueue(int initialCapacity) {
    capacity = initialCapacity;
    array = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// czyszczenie pamieci
SortedArrayPriorityQueue::~SortedArrayPriorityQueue() {
    delete[] array;
}

// powiekszenie tablicy
void SortedArrayPriorityQueue::resize() {
    // nowy rozmiar x2
    int newCapacity = capacity * 2;
    Element* newArray = new Element[newCapacity];

    // kopiowanie danych
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    // zwolnienie starej pamieci
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// znajdowanie elementu
int SortedArrayPriorityQueue::findIndex(int value) {
    // przeszukanie liniowe
    for (int i = 0; i < size; i++) {
        if (array[i].value == value) {
            return i;
        }
    }
    return -1; // brak elementu
}

// dodanie elementu
void SortedArrayPriorityQueue::insert(int element, int priority) {
    // sprawdzenie miejsca
    if (size == capacity) {
        resize();
    }

    // zwiekszenie licznika
    insertCounter++;

    // znalezienie pozycji
    int i = size - 1;
    while (i >= 0 && (array[i].priority < priority ||
        (array[i].priority == priority && array[i].insertTime > insertCounter))) {
        array[i + 1] = array[i];
        i--;
    }

    // wstawienie elementu
    array[i + 1] = Element(element, priority, insertCounter);
    size++;
}

// pobranie i usuniecie max
Element SortedArrayPriorityQueue::extractMax() {
    if (size <= 0) {
        // brak elementow
        cerr << "Blad: Pusta kolejka" << endl;
        return Element();
    }

    // zapisanie max elementu
    Element maxElement = array[0];

    // przesuniecie elementow
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    // zmniejszenie rozmiaru
    size--;

    return maxElement;
}

// podglad max
Element SortedArrayPriorityQueue::findMax() {
    if (size <= 0) {
        // brak elementow
        cerr << "Blad: Pusta kolejka" << endl;
        return Element();
    }

    // max na poczatku
    return array[0];
}

// zmiana priorytetu
bool SortedArrayPriorityQueue::modifyKey(int element, int newPriority) {
    // szukanie elementu
    int i = findIndex(element);

    if (i == -1) {
        // nie znaleziono
        return false;
    }

    // zapisanie elementu
    Element updatedElement = array[i];
    updatedElement.priority = newPriority;

    // usuniecie z obecnej pozycji
    for (int j = i; j < size - 1; j++) {
        array[j] = array[j + 1];
    }
    size--;

    // wstawienie z nowym priorytetem
    int j = size - 1;
    while (j >= 0 && (array[j].priority < newPriority ||
        (array[j].priority == newPriority && array[j].insertTime > updatedElement.insertTime))) {
        array[j + 1] = array[j];
        j--;
    }

    // wstawienie zaktualizowanego elementu
    array[j + 1] = updatedElement;
    size++;

    return true;
}

// wypisanie elementow
void SortedArrayPriorityQueue::display() {
    cout << "Kolejka (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].value << ", " << array[i].priority << ") ";
    }
    cout << endl;
}