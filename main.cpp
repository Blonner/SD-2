#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "max_heap_priority_queue.hpp"
#include "sorted_array_priority_queue.hpp"

using namespace std;

// Generowanie losowej liczby
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Testowanie wydajnosci operacji
void testPerformance() {
    // Rozmiary struktur do testowania
    const int sizes[] = { 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 };
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Liczba powtorzen dla kazdego rozmiaru
    const int repetitions = 15;

    // Zakres priorytetow
    const int minPriority = 1;
    const int maxPriority = 1000000;

    // Tablice na wyniki czasow
    long long heapInsertTimes[numSizes] = { 0 };
    long long heapExtractMaxTimes[numSizes] = { 0 };
    long long heapFindMaxTimes[numSizes] = { 0 };
    long long heapModifyKeyTimes[numSizes] = { 0 };
    long long heapReturnSizeTimes[numSizes] = { 0 };

    long long arrayInsertTimes[numSizes] = { 0 };
    long long arrayExtractMaxTimes[numSizes] = { 0 };
    long long arrayFindMaxTimes[numSizes] = { 0 };
    long long arrayModifyKeyTimes[numSizes] = { 0 };
    long long arrayReturnSizeTimes[numSizes] = { 0 };

    // Pomiar calkowitego czasu
    auto fullTimeStart = chrono::high_resolution_clock::now();

    // Dla kazdego rozmiaru
    for (int s = 0; s < numSizes; s++) {
        int size = sizes[s];
        cout << "Testowanie dla rozmiaru: " << size << endl;

        // Powtarzamy testy
        for (int rep = 0; rep < repetitions; rep++) {
            // Inicjalizacja generatora
            srand(time(nullptr) + rep);

            // Tworzenie kolejek
            MaxHeapPriorityQueue heapQueue;
            SortedArrayPriorityQueue arrayQueue;

            // Przygotowanie danych
            int* elements = new int[size];
            int* priorities = new int[size];

            for (int i = 0; i < size; i++) {
                elements[i] = i + 1;  // Unikalne wartosci
                priorities[i] = randomInt(minPriority, maxPriority);
            }

            // Test insert dla kopca
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < size; i++) {
                heapQueue.insert(elements[i], priorities[i]);
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<long long, nano> duration =
                chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapInsertTimes[s] += duration.count() / repetitions;

            // Test insert dla tablicy
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < size; i++) {
                arrayQueue.insert(elements[i], priorities[i]);
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            arrayInsertTimes[s] += duration.count() / repetitions;

            // Test find-max dla kopca
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                heapQueue.findMax();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapFindMaxTimes[s] += duration.count() / repetitions;

            // Test find-max dla tablicy
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                arrayQueue.findMax();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            arrayFindMaxTimes[s] += duration.count() / repetitions;

            // Test modify-key dla kopca
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                int element = elements[randomInt(0, size - 1)];
                int newPriority = randomInt(minPriority, maxPriority);
                heapQueue.modifyKey(element, newPriority);
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapModifyKeyTimes[s] += duration.count() / repetitions;

            // Test modify-key dla tablicy
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                int element = elements[randomInt(0, size - 1)];
                int newPriority = randomInt(minPriority, maxPriority);
                arrayQueue.modifyKey(element, newPriority);
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            arrayModifyKeyTimes[s] += duration.count() / repetitions;

            // Test extract-max dla kopca
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < size; i++) {
                heapQueue.extractMax();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapExtractMaxTimes[s] += duration.count() / repetitions;

            // Test extract-max dla tablicy
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < size; i++) {
                arrayQueue.extractMax();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            arrayExtractMaxTimes[s] += duration.count() / repetitions;

            // Test return-size dla kopca
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                heapQueue.returnSize();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            heapReturnSizeTimes[s] += duration.count() / repetitions;

            // Test return-size dla tablicy
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < 1000; i++) {
                arrayQueue.returnSize();
            }
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
            arrayReturnSizeTimes[s] += duration.count() / repetitions;

            // Zwolnienie pamieci
            delete[] elements;
            delete[] priorities;
        }
    }

    // Wyswietlanie wynikow
    cout << "\n=== WYNIKI POMIAROW CZASU (ns) ===\n" << endl;

    // Naglowek tabeli
    cout << setw(10) << "Rozmiar" << " | ";
    cout << setw(15) << "Kopiec Insert" << " | ";
    cout << setw(15) << "Tablica Insert" << " | ";
    cout << setw(15) << "Kopiec Extract" << " | ";
    cout << setw(15) << "Tablica Extract" << " | ";
    cout << setw(15) << "Kopiec FindMax" << " | ";
    cout << setw(15) << "Tablica FindMax" << " | ";
    cout << setw(15) << "Kopiec Modify" << " | ";
    cout << setw(15) << "Tablica Modify" << " | ";
    cout << setw(15) << "Kopiec Size" << " | ";
    cout << setw(15) << "Tablica Size" << endl;

    // Dane
    for (int s = 0; s < numSizes; s++) {
        cout << setw(10) << sizes[s] << " | ";
        cout << setw(15) << heapInsertTimes[s] << " | ";
        cout << setw(15) << arrayInsertTimes[s] << " | ";
        cout << setw(15) << heapExtractMaxTimes[s] << " | ";
        cout << setw(15) << arrayExtractMaxTimes[s] << " | ";
        cout << setw(15) << heapFindMaxTimes[s] << " | ";
        cout << setw(15) << arrayFindMaxTimes[s] << " | ";
        cout << setw(15) << heapModifyKeyTimes[s] << " | ";
        cout << setw(15) << arrayModifyKeyTimes[s] << " | ";
        cout << setw(15) << heapReturnSizeTimes[s] << " | ";
        cout << setw(15) << arrayReturnSizeTimes[s] << endl;
    }

    // Zapisywanie do pliku CSV
    cout << "\nZapisywanie wynikow do pliku 'wyniki_pomiarow.csv'..." << endl;

    ofstream csvFile("wyniki_pomiarow.csv");
    if (!csvFile.is_open()) {
        cerr << "Blad: Nie mozna otworzyc pliku do zapisu!" << endl;
        return;
    }

    // Naglowek pliku CSV
    csvFile << "Rozmiar" << "\t"
        << "Kopiec Insert" << "\t"
        << "Tablica Insert" << "\t"
        << "Kopiec Extract" << "\t"
        << "Tablica Extract" << "\t"
        << "Kopiec FindMax" << "\t"
        << "Tablica FindMax" << "\t"
        << "Kopiec Modify" << "\t"
        << "Tablica Modify" << "\t"
        << "Kopiec Size" << "\t"
        << "Tablica Size" << endl;

    // Dane do pliku CSV
    for (int s = 0; s < numSizes; s++) {
        csvFile << sizes[s] << "\t"
            << heapInsertTimes[s] << "\t"
            << arrayInsertTimes[s] << "\t"
            << heapExtractMaxTimes[s] << "\t"
            << arrayExtractMaxTimes[s] << "\t"
            << heapFindMaxTimes[s] << "\t"
            << arrayFindMaxTimes[s] << "\t"
            << heapModifyKeyTimes[s] << "\t"
            << arrayModifyKeyTimes[s] << "\t"
            << heapReturnSizeTimes[s] << "\t"
            << arrayReturnSizeTimes[s] << endl;
    }

    csvFile.close();
    cout << "Wyniki zostaly zapisane do pliku 'wyniki_pomiarow.csv'" << endl;

    // Calkowity czas wykonania
    auto fullTimeEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> fullTimeDuration =
        std::chrono::duration_cast<std::chrono::duration<double>>(fullTimeEnd - fullTimeStart);
    double minutes = fullTimeDuration.count() / 60.0;
    std::cout << "\nCalkowity czas wykonania testow: " << minutes << " minut" << std::endl;
}

// Menu glowne
void mainMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. Test wydajnosci" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testPerformance();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
        }
    }
}

int main() {
    // Ustawienie kodowania
    ios_base::sync_with_stdio(false);

    cout << "=== IMPLEMENTACJE KOLEJKI PRIORYTETOWEJ MAX ===" << endl;
    cout << "1. Implementacja oparta na kopcu binarnym" << endl;
    cout << "2. Implementacja oparta na tablicy posortowanej" << endl;

    mainMenu();

    return 0;
}