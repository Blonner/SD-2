#pragma once
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// element z priorytetem
struct Element {
    int value;      // wartosc
    int priority;   // priorytet
    int insertTime; // czas wstawienia - FIFO

    Element() : value(0), priority(0), insertTime(0) {}

    Element(int val, int prio, int time) : value(val), priority(prio), insertTime(time) {}
};

#endif // ELEMENT_HPP