#include <iostream>
#include <cstdlib>
#include <ctime>
#include "max_heap_priority_queue.hpp"
#include "sorted_array_priority_queue.hpp"

using namespace std;

// losowa liczba z zakresu
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// menu glowne
void mainMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. Test podstawowy" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Test podstawowy - nie zaimplementowany" << endl;
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
    cout << "=== KOLEJKI PRIORYTETOWE MAX ===" << endl;
    cout << "1. Kopiec binarny" << endl;
    cout << "2. Tablica posortowana" << endl;

    mainMenu();

    return 0;
}