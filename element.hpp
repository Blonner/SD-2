#pragma once
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// struktura elementu
struct Element {
    int value;      // wartosc elementu
    int priority;   // priorytet
    int insertTime; // czas dodania - dla FIFO

    // konstruktor domyslny
    Element() : value(0), priority(0), insertTime(0) {}

    // konstruktor z parametrami
    Element(int val, int prio, int time) : value(val), priority(prio), insertTime(time) {}
};

#endif // ELEMENT_HPP