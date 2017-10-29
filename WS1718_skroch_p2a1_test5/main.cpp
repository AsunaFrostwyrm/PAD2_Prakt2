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
        int ieingabe;
        double deingabe;
        string seingabe;
        myVector<int> mv1;
        myVector<double> mv2;
        myVector<string> mv3;
        myVector<myVector<double>> mv4;
        
        for(int i = 0; i < 3; ++i){
            cout << "int-Wert " << i+1 << " eingeben!" << endl;
            cin >> ieingabe;
            if(!cin){
                error("Fehler beim Einlesen");
            }
            mv1.push_back(ieingabe);
        }
        for(int i = 0; i < 3; ++i){
            cout << "double-Wert " << i+1 << " eingeben!" << endl;
            cin >> deingabe;
            if(!cin){
                error("Fehler beim Einlesen");
            }
            mv2.push_back(deingabe);
        }
        for(int i = 0; i < 3; ++i){
            cout << "string " << i+1 << " eingeben!" << endl;
            cin >> seingabe;
            if(!cin){
                error("Fehler beim Einlesen");
            }
            mv3.push_back(seingabe);
        }
        cout << "mv2 wird in mv4 gepusht!" << endl;
        mv4.push_back(mv2);
        for(int i = 0; i < 3; ++i){
            cout << "double-Werte in myVector<myVector<double>> eingeben!" << endl;
            cin >> deingabe;
            if(!cin){
                error("Fehler beim Einlesen");
            }
            mv4[0].push_back(deingabe);
        }
        for(int i = 0; i < mv1.size(); ++i){
            cout << "int-Wert " << i+1 << ": " << mv1.at(i) << endl;
        }
        for(int i = 0; i < mv2.size(); ++i){
            cout << "double-Wert " << i+1 << ": " << mv2.at(i) << endl;
        }
        for(int i = 0; i < mv3.size(); ++i){
            cout << "string " << i+1 << ": " << mv3.at(i) << endl;
        }
        for(int i = 0; i < mv4[0].size(); ++i){
            cout << "myVector<myVector<double>>-Wert " << i+1 << ": " << mv4[0][i] << endl;
        }
        
        return 0;
    } catch (exception &e) {
        cerr << e.what();
        return -2;
    }
}

