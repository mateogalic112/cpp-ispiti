

#include <iostream>
#include <vector>

#include "Trojke.h"
#include "Repka.h"

using namespace std;

int main()
{
    /* Prvi Zadatak */
    Repka repka;
    vector<Repka> repke = repka.napuniVector("repke.txt");

    repka.sortirajVector(repke);
    repka.printajVector(repke);
    /* Prvi Zadatak */

    /* Drugi Zadatak */
    Trojke<int> trojke;
    vector<int> a = { 1,2,3 };
    vector<int> b = { 3,1,2 };
    vector<int> d = { 7,5,3 };
    vector<int> c  = { 1,2,3,4 };
    trojke.dodajTrojku(a);
    trojke.dodajTrojku(d);
    trojke.dodajTrojku(b);
    trojke.dodajTrojku(a);
    trojke.dodajTrojku(b);
    trojke.dodajTrojku(c);
    trojke.dodajTrojku(d);
    cout << trojke.brojTrojki() << endl;
    trojke.brisiTrojku(0);
    //trojke.printTrojke();
    trojke.sortiraj(2);
    trojke.printTrojke();
    /* Drugi Zadatak */
}

