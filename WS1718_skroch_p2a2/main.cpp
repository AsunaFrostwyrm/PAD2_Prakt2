/* 
 * File:   main.cpp
 * Author: max
 *
 * Created on 23. Oktober 2017, 16:32
 */

#include <cstdlib>
#include <stdexcept>
#include "myarray.hpp"
#include <iostream>
#include <string>

using namespace std;

void error(string s) {
    throw runtime_error{s};
}

struct Parkhaus {
    int nummer{0};
    char dauer{'n'};
    string kennzeichen{""};
};

int main(int argc, char** argv) {
    try {
        int counter{1};
        int dauercounter{0};
        int freispeicher{0};
        string stringeingabe{""};
        int inteingabe{0};
        myArray<Parkhaus, 10> phaus;

        do {
            cout << "Parkplatzmenü: " << endl;
            cout << "\n(1) Parkplatz belegen";
            cout << "\n(2) Dauerparkplatz belegen";
            cout << "\n(3) Alle belegten Parkplätze ausgeben";
            cout << "\n(4) Einen Parkplatz freigeben";
            cout << "\n(5) Alle Parkplätze freigeben";
            cout << "\n(6) Beenden\n";
            cin >> inteingabe;
            if (!cin) {
                error("Fehler beim Einlesen!");
            }
            switch (inteingabe) {
                case 1:
                    cout << "Geben Sie das Kennzeichen des zu parkenden Fahrzeugs ein!" << endl;
                    cout << "Hinweis: Es ist darauf zu achten das Kennzeichen in der Form XXX-XXX-XXX einzugeben!" << endl;
                    cin >> stringeingabe;
                    if (!cin)
                        error("Fehler beim Einlesen!");
                    for (int i{0}; i < phaus.size(); ++i) {
                        if (phaus[i].kennzeichen == "") {
                            phaus[i].kennzeichen = stringeingabe;
                            phaus[i].nummer = counter++;
                            break;
                        } else {
                            if (phaus[i].kennzeichen != "" && i == phaus.size() - 1) {
                                cout << "Es gibt keine freien Parkplätze mehr!" << endl;
                            }
                        }
                    }
                    break;
                case 2:
                    if (dauercounter >= 3) {
                        cout << "Es können maximal 3 Parkplätze als Dauerparkplätze festgelegt werden!" << endl;
                    } else {
                        cout << "Geben Sie das Kennzeichen des auf einem Dauerparkplatz einzutragenden Fahrzeugs ein!" << endl;
                        cin >> stringeingabe;
                        if (!cin)
                            error("Fehler beim Einlesen!");
                        for (int i{0}; i < phaus.size(); ++i) {
                            if (phaus[i].kennzeichen == "") {
                                phaus[i].kennzeichen = stringeingabe;
                                phaus[i].nummer = counter++;
                                phaus[i].dauer = 'd';
                                dauercounter++;
                                break;
                            } else {
                                if (phaus[i].kennzeichen != "" && i == phaus.size() - 1) {
                                    cout << "Es gibt keine freien Parkplätze mehr!" << endl;
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    for (int i{0}; i < phaus.size(); ++i) {
                        if (phaus[i].kennzeichen != "") {
                            cout << "Parkplatz Nummer: " << phaus[i].nummer << endl;
                            cout << "Kennzeichen: " << phaus[i].kennzeichen << endl;
                            cout << "Dauerparker? (d = Dauerparker/ n = Normalparker) --> " << phaus[i].dauer << " <--" << endl;
                        }

                    }
                    break;
                case 4:
                    cout << "Geben Sie die Nummer des Parkplatzes an, welchen Sie freigeben möchten!" << endl;
                    cin >> inteingabe;
                    if (!cin)
                        error("Fehler beim Einlesen!");
                    for (int i{0}; i < phaus.size(); ++i) {
                        if (phaus[i].nummer == inteingabe) {
                            phaus[i].nummer = 0;
                            phaus[i].kennzeichen = "";
                            if (phaus[i].dauer == 'd') {
                                phaus[i].dauer = 'n';
                                dauercounter--;
                            }
                            cout << "Der Parkplatz wurde erfolgreich freigegeben!" << endl;
                        }
                    }
                    break;
                case 5:
                    cout << "Es werden nun alle belegten Parkplätze wieder freigegeben!" << endl;
                    for (int i{0}; i < phaus.size(); ++i) {
                        phaus[i].nummer = 0;
                        phaus[i].kennzeichen = "";
                        phaus[i].dauer = 'n';
                        dauercounter = 0;
                        counter = 0;
                    }
                    break;
                case 6:
                    break;
            }
        } while (inteingabe != 6);

        return 0;
    } catch (exception &e) {
        cerr << e.what();
        return -2;
    }
}

