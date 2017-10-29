/* 
 * File:   main.cpp
 * Author: max
 *
 * Created on 19. Oktober 2017, 11:48
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "myvector.hpp"

using namespace std;

void error(string s) {throw runtime_error{s};}

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        int eingabe;
        myVector<int> mv1;
        mv1.push_back(5);
        cout << "Size: " << mv1.size() << endl;
        cout << "Capacity: " << mv1.capacity() << endl;
        cout << "Index in welchen die Zahl 10 gespeichert werden soll:" << endl;
        cin >> eingabe;
        if(!cin)
            error("Fehler beim Einlesen");
        mv1[eingabe] = 10;
        return 0;
    } catch (exception &e) {
        cerr << e.what();
        return -2;
    }
}

