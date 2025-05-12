#include <iostream>
#include <cstdlib>
#include <ctime>
#include "max_heap_priority_queue.hpp"
#include "sorted_array_priority_queue.hpp"

using namespace std;

// losowa liczba
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// test wydajnosci - deklaracja
void testPerformance() {
    cout << "Test wydajnosci" << endl;
}

// menu
void mainMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Test wydajnosci" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testPerformance();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "Bledna opcja. Sprobuj ponownie." << endl;
        }
    }
}

int main() {
    // inicjalizacja generatora
    srand(time(nullptr));

    cout << "=== KOLEJKI PRIORYTETOWE MAX ===" << endl;
    cout << "1. Kopiec binarny" << endl;
    cout << "2. Tablica posortowana" << endl;

    // uruchomienie menu
    mainMenu();

    return 0;
}