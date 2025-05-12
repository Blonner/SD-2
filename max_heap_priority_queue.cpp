#include "max_heap_priority_queue.hpp"
#include <iostream>

using namespace std;

// inicjalizacja
MaxHeapPriorityQueue::MaxHeapPriorityQueue(int initialCapacity) {
    capacity = initialCapacity;
    heap = new Element[capacity];
    size = 0;
    insertCounter = 0;
}

// czyszczenie pamieci
MaxHeapPriorityQueue::~MaxHeapPriorityQueue() {
    delete[] heap;
}

// przywracanie wlasnosci kopca w gore
void MaxHeapPriorityQueue::heapifyUp(int i) {
    while (i > 0) {
        int p = parent(i);

        // warunek stopu - priorytet mniejszy
        if (heap[i].priority < heap[p].priority) {
            break;
        }

        // warunek stopu - rowne priorytety, FIFO
        if (heap[i].priority == heap[p].priority && heap[i].insertTime > heap[p].insertTime) {
            break;
        }

        // zamiana elementow
        swap(heap[i], heap[p]);
        i = p;
    }
}

// przywracanie wlasnosci kopca w dol
void MaxHeapPriorityQueue::heapifyDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    int r = rightChild(i);

    // sprawdzenie lewego dziecka
    if (l < size && (heap[l].priority > heap[maxIndex].priority ||
        (heap[l].priority == heap[maxIndex].priority &&
            heap[l].insertTime < heap[maxIndex].insertTime))) {
        maxIndex = l;
    }

    // sprawdzenie prawego dziecka
    if (r < size && (heap[r].priority > heap[maxIndex].priority ||
        (heap[r].priority == heap[maxIndex].priority &&
            heap[r].insertTime < heap[maxIndex].insertTime))) {
        maxIndex = r;
    }

    // zamiana jesli potrzebna
    if (i != maxIndex) {
        swap(heap[i], heap[maxIndex]);
        heapifyDown(maxIndex);
    }
}

// powiekszenie tablicy
void MaxHeapPriorityQueue::resize() {
    // nowy rozmiar x2
    int newCapacity = capacity * 2;
    Element* newHeap = new Element[newCapacity];

    // kopiowanie danych
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }

    // zwolnienie starej pamieci
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

// znajdowanie elementu
int MaxHeapPriorityQueue::findIndex(int value) {
    // przeszukanie liniowe
    for (int i = 0; i < size; i++) {
        if (heap[i].value == value) {
            return i;
        }
    }
    return -1; // brak elementu
}

// dodanie elementu
void MaxHeapPriorityQueue::insert(int element, int priority) {
    // sprawdzenie miejsca
    if (size == capacity) {
        resize();
    }

    // dodanie na koniec
    insertCounter++;
    heap[size] = Element(element, priority, insertCounter);

    // naprawa kopca
    heapifyUp(size);
    size++;
}

// pobranie i usuniecie max
Element MaxHeapPriorityQueue::extractMax() {
    if (size <= 0) {
        // brak elementow
        cerr << "Blad: Pusta kolejka" << endl;
        return Element();
    }

    // zapisanie max elementu
    Element maxElement = heap[0];

    // przeniesienie ostatniego na poczatek
    heap[0] = heap[size - 1];
    size--;

    // naprawa kopca
    heapifyDown(0);

    return maxElement;
}

// podglad max
Element MaxHeapPriorityQueue::findMax() {
    if (size <= 0) {
        // brak elementow
        cerr << "Blad: Pusta kolejka" << endl;
        return Element();
    }

    // max na poczatku
    return heap[0];
}

// zmiana priorytetu
bool MaxHeapPriorityQueue::modifyKey(int element, int newPriority) {
    // szukanie elementu
    int i = findIndex(element);

    if (i == -1) {
        // nie znaleziono
        return false;
    }

    // zapisanie starego priorytetu
    int oldPriority = heap[i].priority;

    // aktualizacja
    heap[i].priority = newPriority;

    // naprawa kopca
    if (newPriority > oldPriority) {
        heapifyUp(i);
    }
    else if (newPriority < oldPriority) {
        heapifyDown(i);
    }

    return true;
}

// wypisanie elementow
void MaxHeapPriorityQueue::display() {
    cout << "Kolejka (wartosc, priorytet):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << heap[i].value << ", " << heap[i].priority << ") ";
    }
    cout << endl;
}