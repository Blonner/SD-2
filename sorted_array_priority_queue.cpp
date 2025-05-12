#include "sorted_array_priority_queue.hpp"
#include <iostream>

using namespace std;

// Konstruktor
SortedArrayPriorityQueue::SortedArrayPriorityQueue(int initialCapacity) {
    // Inicjalizacja z pojemnoscia
    capacity = initialCapacity;
    array = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// Destruktor
SortedArrayPriorityQueue::~SortedArrayPriorityQueue() {
    // Zwolnienie pamieci
    delete[] array;
}

// Zwiekszenie pojemnosci
void SortedArrayPriorityQueue::resize() {
    // Podwojenie pojemnosci
    int newCapacity = capacity * 2;
    Element* newArray = new Element[newCapacity];

    // Kopiowanie elementow
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    // Aktualizacja wskaznikow
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// Szukanie indeksu elementu
int SortedArrayPriorityQueue::findIndex(int value) {
    // Liniowe przeszukiwanie
    for (int i = 0; i < size; i++) {
        if (array[i].value == value) {
            return i;
        }
    }
    return -1; // Nie znaleziono
}

// Dodawanie elementu
void SortedArrayPriorityQueue::insert(int element, int priority) {
    // Sprawdzenie pojemnosci
    if (size == capacity) {
        resize();
    }

    // Zwiekszenie licznika
    insertCounter++;

    // Znalezienie pozycji
    int i = size - 1;
    while (i >= 0 && (array[i].priority < priority ||
        (array[i].priority == priority && array[i].insertTime > insertCounter))) {
        array[i + 1] = array[i];
        i--;
    }

    // Wstawienie elementu
    array[i + 1] = Element(element, priority, insertCounter);
    size++;
}

// Usuwanie maksimum
Element SortedArrayPriorityQueue::extractMax() {
    if (size <= 0) {
        // Kolejka pusta
        cerr << "Blad: Kolejka jest pusta" << endl;
        return Element();
    }

    // Maksimum na poczatku
    Element maxElement = array[0];

    // Przesuniecie elementow
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Zmniejszenie rozmiaru
    size--;

    return maxElement;
}

// Podglad maksimum
Element SortedArrayPriorityQueue::findMax() {
    if (size <= 0) {
        // Kolejka pusta
        cerr << "Blad: Kolejka jest pusta" << endl;
        return Element();
    }

    // Maksimum na poczatku
    return array[0];
}

// Zmiana priorytetu
bool SortedArrayPriorityQueue::modifyKey(int element, int newPriority) {
    // Szukanie elementu
    int i = findIndex(element);

    if (i == -1) {
        // Element nie znaleziony
        return false;
    }

    // Zapisanie elementu z nowym priorytetem
    Element updatedElement = array[i];
    updatedElement.priority = newPriority;

    // Usuniecie z obecnej pozycji
    for (int j = i; j < size - 1; j++) {
        array[j] = array[j + 1];
    }
    size--;

    // Wstawienie z nowym priorytetem
    int j = size - 1;
    while (j >= 0 && (array[j].priority < newPriority ||
        (array[j].priority == newPriority && array[j].insertTime > updatedElement.insertTime))) {
        array[j + 1] = array[j];
        j--;
    }

    // Wstawienie zaktualizowanego elementu
    array[j + 1] = updatedElement;
    size++;

    return true;
}

// Wyswietlanie zawartosci
void SortedArrayPriorityQueue::display() {
    cout << "Zawartosc kolejki (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].value << ", " << array[i].priority << ") ";
    }
    cout << endl;
}