#include "sorted_array_priority_queue.hpp"
#include <iostream>

using namespace std;

// Konstruktor
SortedArrayPriorityQueue::SortedArrayPriorityQueue(int initialCapacity) {
    // Inicjalizacja z początkową pojemnością
    capacity = initialCapacity;
    array = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// Destruktor
SortedArrayPriorityQueue::~SortedArrayPriorityQueue() {
    // Zwalnianie pamięci
    delete[] array;
}

// Powiększa pojemność tablicy
void SortedArrayPriorityQueue::resize() {
    int newCapacity = capacity + 5; 
    Element* newArray = new Element[newCapacity];

    // Kopiujemy elementy
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    // Zwalniamy starą pamięć i aktualizujemy wskaźniki
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// Dodaje element o podanej wartości i priorytecie
void SortedArrayPriorityQueue::insert(int element, int priority) {
    // Sprawdzamy, czy potrzebujemy więcej miejsca
    if (size == capacity) {
        resize();
    }

    // Zwiększamy licznik wstawień
    insertCounter++;


    int i = size - 1;
    while (i >= 0 && array[i].priority < priority) {
        array[i + 1] = array[i];
        i--;
    }

    // Wstawiamy nowy element
    array[i + 1] = Element(element, priority, insertCounter);
    size++;
}

// Usuwa i zwraca element o najwyższym priorytecie
Element SortedArrayPriorityQueue::extractMax() {
    if (size <= 0) {
        // Kolejka jest pusta
        cerr << "Błąd: Kolejka jest pusta" << endl;
        return Element();
    }

    // Element o najwyższym priorytecie jest na początku
    Element maxElement = array[0];

    // Przesuwamy wszystkie elementy o jedną pozycję w lewo
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Zmniejszamy rozmiar
    size--;

    return maxElement;
}

// Zwraca element o najwyższym priorytecie bez usuwania
Element SortedArrayPriorityQueue::findMax() {
    return array[0];
}

// Wyświetla zawartość kolejki
void SortedArrayPriorityQueue::display() {
    cout << "Zawartość kolejki (wartość, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].value << ", " << array[i].priority << ") ";
    }
    cout << endl;
}
