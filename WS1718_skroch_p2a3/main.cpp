/* 
 * File:   main.cpp
 * Author: max
 *
 * Created on 24. Oktober 2017, 15:10
 */

#include <cstdlib>
#include "tracer.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
const int a = 5;

int main(int argc, char** argv) {

    int b = 7;

    Tracer<int> trace{a}; //Konstruktoraufruf
    Tracer<int> trace2{b}; //Konstruktoraufruf
    cout << "Counter: " << trace.counter << endl; //Counterausgabe
    cout << trace.getValue() << endl; //getValue-Aufruf
    cout << trace2.getValue() << endl; //getValue-Aufruf
    trace.operator=(trace2); //Kopierkonstruktoraufruf  
    cout << trace.getValue() << endl; //getValue-Aufruf
    cout << trace2.getValue() << endl; //getValue-Aufruf
    cout << "Counter: " << trace.counter << endl; //Counterausgabe
    trace.~Tracer(); //Destruktoraufruf kommt von selbst, warum?
    trace.~Tracer(); //Destruktoraufruf kommt von selbst, warum?
    cout << "Counter: " << trace.counter << endl; //Counterausgabe

    return 0;
}

