#include "sorted_array_priority_queue.hpp"
#include <iostream>

using namespace std;

// Konstruktor
SortedArrayPriorityQueue::SortedArrayPriorityQueue(int initialCapacity) {
    // Inicjalizacja z początkową pojemnością
    capacity = initialCapacity;
    array = new Element[capacity];
    size = 0;
}

// Destruktor
SortedArrayPriorityQueue::~SortedArrayPriorityQueue() {
    // Zwalnianie pamięci
    delete[] array;
}

// Dodaje element o podanej wartości i priorytecie
void SortedArrayPriorityQueue::insert(int element, int priority) {
        
       int i = size - 1;
    while (i >= 0 && array[i].priority < priority) {
        array[i + 1] = array[i];
        i--;
    }

    // Wstawianie nowy elementu
    array[i + 1] = Element(element, priority, 0);
    size++;
}

// Usuwa i zwraca element o najwyższym priorytecie
Element SortedArrayPriorityQueue::extractMax() {

    
    // Element o najwyższym priorytecie jest na początku
    Element maxElement = array[0];

    for (int i = 1; i < size; i++) {
        array[i-1] = array[i];
    }

    // Zmniejszamy rozmiar
    size--;

    return maxElement;
}

// Wyświetla zawartość kolejki
void SortedArrayPriorityQueue::display() {
    cout << "Zawartość kolejki (wartość, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].value << ", " << array[i].priority << ") ";
    }
    cout << endl;
}
