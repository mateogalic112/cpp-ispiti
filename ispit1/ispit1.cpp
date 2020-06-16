
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

#include "Dict.h"

/* Prvi Zadatak */ 
vector<string> filterVector(vector<string>& v, string podstring) {
    vector<string> n;

    int i, v_size = v.size();
    for (i = 0; i < v_size; ++i) {
        size_t found = v.at(i).find(podstring);
        if (found != string::npos) {
            string s = v.at(i);
            reverse(s.begin() + found, s.begin() + podstring.size() + found);
            n.push_back(s);
        }
    }
    return n;
}
/* Prvi Zadatak */

/* Drugi Zadatak */
template<typename T, int N> class array {
    T* sh;
public:
    array(int value) : sh(new T[N]) {
        fill(sh.begin(), sh.end(), value);
    }
};
/* Drugi Zadatak */

int main()
{   
    /* Prvi Zadatak */
    vector<string> v = { "mateo", "galic", "matador" };
    vector<string> n = filterVector(v, "at");
    for (int i = 0; i < n.size(); i++) {
        cout << n.at(i) << endl;
    }
    /* Prvi Zadatak */

    /* Drugi Zadatak */
    array<short, 10> a(5);
    cout << a.size();
    /* Drugi Zadatak */

    /* Treci Zadatak */
    Dict d;
    d.read("rjecnik.txt");
    string s = d.translate("dog");
    std::cout << s;
    /* Treci zadatak */
}

