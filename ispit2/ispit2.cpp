
#include <iostream>
#include <algorithm>
#include <vector>

#include "Repka.h"
#include "BasePoint.h"
#include "Class1.h"
#include "Class2.h"

/*Treci Zadatak Dio Funkcija*/
void print(int n) {
    cout << n << "\t";
}

void display(vector<int>& v) {
    for_each(v.begin(), v.end(), print);
    cout << endl;
}

int main()
{
    /* Prvi Zadatak */
    Repka repka;
    vector<Repka> repke = repka.napuniVector("repka.txt");

    repka.sortirajVector(repke);
    repka.printajVector(repke);
    /* Prvi Zadatak */

    /* Drugi Zadatak */
    BasePoint* p;
    Class1 c1;
    p = &c1;

    p->init();
    for (int i = 0; i < 10; ++i) {
        p->setVelocity();
        p->move(0.1);
    }
    p->display();
    /* Drugi Zadatak */

    /* Treci Zadatak */
    vector<int> v = { 10, 20, 30, 20 };
    display(v);

    vector<int> vu;
    for (int i = 0; i < v.size(); ++i) {
        if (find(vu.begin(), vu.end(), v.at(i)) == vu.end()) {
            vu.push_back(v.at(i));
        }
    }
    display(vu);

    vector<int> vc(vu.size());
    generate(vc.begin(), vc.end(), rand);

    int vu_size = vu.size();
    for (int i = 0; i < vu_size; ++i) {
        vu.push_back(count(v.begin(), v.end(), vu.at(i)));
    }
    display(vu);
    display(vc);
    /* Treci Zadatak */
}

