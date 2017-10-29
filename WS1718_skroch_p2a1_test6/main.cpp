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

void error(string s) {
    throw runtime_error{s};
}

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        myVector<double> mv1;
        mv1.push_back(1.5);
        mv1.push_back(2.5);
        mv1.push_back(3.5);
        mv1.push_back(4.5);
        mv1.push_back(5.5);
        for (int i = 0; i < mv1.size(); ++i) {
            cout << "mv1[" << i << "] = " << mv1[i] << endl;
        }
        cout << "mv1[0] + mv1[1] = " << mv1[0] + mv1[1] << endl;
        mv1.push_back(mv1[0] + mv1[1]);
        cout << "mv1[3] - mv1[2] = " << mv1[3] - mv1[2] << endl;
        mv1.push_back(mv1[3] - mv1[2]);
        cout << "mv1[4] * mv1[5] = " << mv1[4] * mv1[5] << endl;
        mv1.push_back(mv1[4] * mv1[5]);
        cout << "mv1[6] / mv1[7] = " << mv1[6] / mv1[7] << endl;
        mv1.push_back(mv1[6] / mv1[7]);
        for (int i = 0; i < mv1.size(); ++i) {
            cout << "mv1[" << i << "] = " << mv1[i] << endl;
        }
        return 0;
    } catch (exception &e) {
        cerr << e.what();
        return -2;
    }
}

