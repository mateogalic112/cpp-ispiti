
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>

#include "Point.h"
#include "E.h"
#include "WorkingFile.h"

using namespace std;

struct Coord {
    char lat, lon;
    double x, y;
    friend istream& operator>> (istream&, Coord&);
};

istream& operator>> (istream& is, Coord& c) {
    is >> c.lat >> c.x >> c.lon >> c.y;
    return is;
}

void printVector(vector<Coord>& v) {
    int v_size = v.size();
    for (int i = 0; i < v_size; i++) {
        cout << v.at(i).lat << v.at(i).x << ", " << v.at(i).lon << v.at(i).y << endl;
    }
}

bool isNorth(Coord c) {
    return c.lon == 'N';
}

bool notValid(Coord c) {
    return c.x < 0 || c.y < 0;
}


void cityFunction(string fileName) {
    fstream f(fileName); 
    if (!f.is_open()) throw E();

    vector<Coord> v;
    istream_iterator<Coord> is(f), ends;
    copy(is, ends, back_inserter(v));

    v.erase(remove_if(v.begin(), v.end(), notValid), v.end());

    int cnt = count_if(v.begin(), v.end(), isNorth);
    cout << "Sjevernih gradovima ima: " << cnt << endl;

    printVector(v);

}

int main()
{   
    /* Prvi Zadatak */
    Point<int> p1(2,3);
    Point<int> p2(3,4);

    cout << "udaljenost tocaka " << p1 << "i" << p2 << " je " << p1 - p2 << endl;
    /*Prvi Zadatak*/

    /*Drugi Zadatak*/
    cityFunction("cities.txt");
    /*Drugi Zadatak*/

    /*Treci Zadatak*/
    WorkingFile file("fruits.txt");
    file.openFile(false);
    file.writeFile("Higuain");
    file.closeFile(false);
}
