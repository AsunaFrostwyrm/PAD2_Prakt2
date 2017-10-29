/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myvector.hpp
 * Author: max
 *
 * Created on 19. Oktober 2017, 11:50
 */

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstdlib>
#include <stdexcept>

template<class T>
class myVector {
public:
    myVector(); //Standardkonstruktor
    explicit myVector(int n, T t = T())
    : sz{n}, space{n}, elem{new T[n]}{}; //Expliziter Konstruktor
    myVector(const myVector&); //Kopierkonstruktor
    myVector& operator=(const myVector&); //Zuweisungsoperator
    ~myVector(); //Destruktor
    int size() const; //Groesse von myvector
    int capacity() const; //Tatsaechlich allokierte Groesse von myvector
    T& operator[](int); //Zugriffsoperator
    T& at(int); //Zugriffsoperator mit Indexueberpruefung
    const T& operator[](int) const; //Zugriffsoperator zum lesen
    const T& at(int) const; //Zugriffsoperator zum lesen mit Ueberpruefung
    void reserve(int); //Speicher reservieren
    void resize(int); //Größe des "Arrays" neu anpassen
    void push_back(const T&); //Elemente einfügen
private:
    T* elem; //Elementzeiger
    int space; //Size + weitere Plaetze
    int sz; //Size
};

template<class T>
myVector<T>::myVector() { //Standardkonstruktor
    elem = NULL; //Initalisierung mit NULLPTR
    sz = 0; //Initalisierung
    space = 0; //Initalisierung
}

template<class T>
myVector<T>::myVector(const myVector& x) { //Kopierkonstruktor
    sz = x.sz;
    space = x.space;
    for (int i = 0; i < sz; ++i) {
        elem[i] = x.elem[i];
    }
}

template<class T>
myVector<T>& myVector<T>::operator =(const myVector& a) { //Zuweisungsoperator
    if (this == &a) return *this; //Gleicher myVector?
    if (a.sz <= space) {
        for (int i = 0; i < a.sz; ++i) {
            elem[i] = a.elem[i];
        }
        sz = a.sz;
        return *this;
    }
    T * p{new T[a.sz]};
    for (int i{}; i < a.sz; ++i) {
        p[i] = a.elem[i];
    }
    elem = p;
    space = a.sz;
    sz = a.sz;
    return *this;
}

template<class T>
myVector<T>::~myVector() {//Destruktor
    delete[] elem;
}

template<class T>
int myVector<T>::size() const { //Rueckgabe der Groesse des myVectors
    return sz;
}

template<class T>
int myVector<T>::capacity() const { //Tatsaechlich allokierte Groesse des myVectors
    return space;
}

template<class T>
T& myVector<T>::operator[](int n) { //Zugriffsoperator
    return elem[n];
}

template<class T>
T& myVector<T>::at(int n) { //Zugriffsoperator mit Indexueberpruefung
    if (n < 0 || n >= sz) {
        throw std::out_of_range{"bad index[]\n"};
    }
    return elem[n];
}

template<class T>
const T& myVector<T>::operator[](int n) const {//Zugriffsoperator zum lesen
    return elem[n];
}

template<class T>
const T& myVector<T>::at(int n) const { //Zugriffsoperator zum lesen mit Indexueberpruefung
    if (n < 0 || n >= sz) {
        throw std::out_of_range{"bad index[]\n"};
    }
    return elem[n];
}

template<class T>
void myVector<T>::reserve(int newspace) { 
    if (newspace <= space) return; /*Wenn angeforderter Speicher kleiner 
                                   als aktueller ist, abbrechen*/

    T *p{new T[newspace]}; //neuen Speicher anfordern(new)
    for (int i{0}; i < sz; ++i) { //Elemente in neues Datenfeld kopieren
        p[i] = elem[i];
    }
    delete[] elem; //Alten Speicher freigeben
    elem = p; //Zeiger neu zuweisen
    space = newspace; //Neue groesse des Arrays setzen
}

template<class T>
void myVector<T>::resize(int newsize) {

    reserve(newsize);
    for (int i = sz; i < newsize; ++i) {
        elem[i] = T{};
    }
}

template<class T>
void myVector<T>::push_back(const T& d) {
    if (space == 0) {
        reserve(8);
    } else {
        if (sz == space) {
            reserve(space * 2);
        }
    }
    elem[sz] = d;
    ++sz;
}

#endif /* MYVECTOR_HPP */

