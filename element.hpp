#pragma once
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// Struktura elementu z priorytetem
struct Element {
    int value;      // Wartosc elementu
    int priority;   // Priorytet elementu
    int insertTime; // Czas wstawienia (dla rozwiazywania konfliktow)

    Element() : value(0), priority(0), insertTime(0) {}

    Element(int val, int prio, int time) : value(val), priority(prio), insertTime(time) {}
};

#endif // ELEMENT_HPP