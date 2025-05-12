#include "max_heap_priority_queue.hpp"
#include <iostream>

using namespace std;

// Konstruktor
MaxHeapPriorityQueue::MaxHeapPriorityQueue(int initialCapacity) {
    // Inicjalizacja z pojemnoscia
    capacity = initialCapacity;
    heap = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// Destruktor
MaxHeapPriorityQueue::~MaxHeapPriorityQueue() {
    // Zwolnienie pamieci
    delete[] heap;
}

// Naprawa kopca w gore
void MaxHeapPriorityQueue::heapifyUp(int i) {
    // Przesuwanie w gore
    while (i > 0) {
        int p = parent(i);

        // Jesli priorytet mniejszy, koniec
        if (heap[i].priority < heap[p].priority) {
            break;
        }

        // Jesli priorytety rowne, sprawdz czas
        if (heap[i].priority == heap[p].priority && heap[i].insertTime > heap[p].insertTime) {
            break;
        }

        // Zamiana elementow
        swap(heap[i], heap[p]);
        i = p;
    }
}

// Naprawa kopca w dol
void MaxHeapPriorityQueue::heapifyDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    int r = rightChild(i);

    // Sprawdz lewe dziecko
    if (l < size && (heap[l].priority > heap[maxIndex].priority ||
        (heap[l].priority == heap[maxIndex].priority &&
            heap[l].insertTime < heap[maxIndex].insertTime))) {
        maxIndex = l;
    }

    // Sprawdz prawe dziecko
    if (r < size && (heap[r].priority > heap[maxIndex].priority ||
        (heap[r].priority == heap[maxIndex].priority &&
            heap[r].insertTime < heap[maxIndex].insertTime))) {
        maxIndex = r;
    }

    // Jesli znaleziono wiekszy, zamien i kontynuuj
    if (i != maxIndex) {
        swap(heap[i], heap[maxIndex]);
        heapifyDown(maxIndex);
    }
}

// Zwiekszenie pojemnosci
void MaxHeapPriorityQueue::resize() {
    // Podwojenie pojemnosci
    int newCapacity = capacity * 2;
    Element* newHeap = new Element[newCapacity];

    // Kopiowanie elementow
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }

    // Aktualizacja wskaznikow
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

// Szukanie indeksu elementu
int MaxHeapPriorityQueue::findIndex(int value) {
    // Liniowe przeszukiwanie
    for (int i = 0; i < size; i++) {
        if (heap[i].value == value) {
            return i;
        }
    }
    return -1; // Nie znaleziono
}

// Dodawanie elementu
void MaxHeapPriorityQueue::insert(int element, int priority) {
    // Sprawdzenie pojemnosci
    if (size == capacity) {
        resize();
    }

    // Dodanie na koniec
    insertCounter++;
    heap[size] = Element(element, priority, insertCounter);

    // Naprawa kopca
    heapifyUp(size);
    size++;
}

// Usuwanie maksimum
Element MaxHeapPriorityQueue::extractMax() {
    if (size <= 0) {
        // Kolejka pusta
        cerr << "Blad: Kolejka jest pusta" << endl;
        return Element();
    }

    // Zapisanie maksimum
    Element maxElement = heap[0];

    // Ostatni na poczatek
    heap[0] = heap[size - 1];
    size--;

    // Naprawa kopca
    heapifyDown(0);

    return maxElement;
}

// Podglad maksimum
Element MaxHeapPriorityQueue::findMax() {
    if (size <= 0) {
        // Kolejka pusta
        cerr << "Blad: Kolejka jest pusta" << endl;
        return Element();
    }

    // Maksimum na poczatku
    return heap[0];
}

// Zmiana priorytetu
bool MaxHeapPriorityQueue::modifyKey(int element, int newPriority) {
    // Szukanie elementu
    int i = findIndex(element);

    if (i == -1) {
        // Element nie znaleziony
        return false;
    }

    // Zapisanie starego priorytetu
    int oldPriority = heap[i].priority;

    // Aktualizacja priorytetu
    heap[i].priority = newPriority;

    // Naprawa kopca
    if (newPriority > oldPriority) {
        heapifyUp(i);
    }
    else if (newPriority < oldPriority) {
        heapifyDown(i);
    }

    return true;
}

// Wyswietlanie zawartosci
void MaxHeapPriorityQueue::display() {
    cout << "Zawartosc kolejki (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << heap[i].value << ", " << heap[i].priority << ") ";
    }
    cout << endl;
}