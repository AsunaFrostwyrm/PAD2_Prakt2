/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tracer.hpp
 * Author: max
 *
 * Created on 24. Oktober 2017, 15:10
 */

#ifndef TRACER_HPP
#define TRACER_HPP

#include <iostream>

template <class T>
class Tracer {


public:

    static int counter;

    Tracer(T value) {
        this->value = value;
        counter++;
        std::cout << "Ich bin ein Konstruktor!" << std::endl;
    }
    Tracer(const Tracer& x);
    Tracer& operator=(const Tracer&);
    T getValue() {
        return value;
    }
    ~Tracer();

private:
    T value;

};

template <class T>
Tracer<T>::Tracer(const Tracer& x){
    std::cout << "Ich bin ein Kopierkonstruktor!" << std::endl;
    value = x.value;
    
}

template <class T>
Tracer<T>& Tracer<T>::operator=( const Tracer<T>& r){ //Operatorueberladung
    value = r.value;
    std::cout << "Ich bin ein Zuweisungsoperator!" << std::endl;
    return *this;
}

template <typename T>
int Tracer<T>::counter = 0;

template <class T>
Tracer<T>::~Tracer(){
    std::cout << "Ich bin ein Destruktor!" << std::endl;
    counter--;
}


#endif /* TRACER_HPP */

