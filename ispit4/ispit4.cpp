
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>

#include "Lik.h"
#include "Krug.h"
#include "Kvadrat.h"
#include "DequeClass.h"

/*Prvi Zadatak*/
template<typename T, int N>
class array {
    T* field;
public:
    array(T n) : field(new T[N]) {
        for (int i = 0; i < N; ++i) {
            field[i] = n;
        }
    }
    T& operator[](const int);
    friend std::ostream& operator<< (std::ostream&, const char);
    //friend void std::copy();
};

template<typename T, int N> T& array<T, N>::operator[] (const int index) {
    return field[index];
}

template<typename T, int N> std::ostream& operator<< (std::ostream& os, const char t) {
    for (int i = 0; i < N; ++i) {
        os << array<T, N>::field[i] << t;
    }
    os << std::endl;
}
/*Prvi Zadatak*/

/*Treci Zadatak*/
double calcArea(std::vector<Lik*> v) {
    int v_size = v.size();
    double area = 0;
    for (int i = 0; i < v_size; ++i) {
        area += v.at(i)->area();
    }
    return area;
}
/*Treci Zadatak*/

/*Cetvrti Zadatak*/
void printVector(const std::vector<int>& v) {
    int v_size = v.size();
    for (int i = 0; i < v_size; ++i) {
        std::cout << v.at(i) << "\t";
    }
    std::cout << std::endl;
}

bool isTwoDigit(int i) {
    int brojac = 0;
    while (i > 0) {
        brojac++;
        i /= 10;
    }
    return brojac == 2;
}
/*Cetvrti Zadatak*/

int main()
{   

    /*Prvi Zadatak*/
    array<double, 4> a(2);
    std::ostream_iterator <double> os(std::cout, ",");
    //std::copy(a.begin(), a.end(), os);
    /*Prvi Zadatak*/

    /*Drugi Zadatak*/
    DequeClass<int> d(5);
    d.dodajNaKraj(10);
    d.dodajNaKraj(20);
    //std::cout << d.getDeq().at(1) << std::endl;
    d.skiniSaPocetka();
    std::cout << d.getDeq().at(0) << std::endl;
    /*Drugi Zadatak*/

    /*Treci Zadatak*/
    std::vector<Lik*> likovi;
    Krug kr(10);
    Kvadrat kv(10);

    likovi.push_back(&kr);
    likovi.push_back(&kv);

    std::cout << calcArea(likovi) << std::endl;
    /*Treci Zadatak*/

    /*Cetvrti Zadatak*/
    std::ifstream file("brojevi.txt");
    std::vector<int> v;
    while (!file.eof()) {
        std::string input;
        file >> input;
        if (input.find('-') == std::string::npos && input.find('.') == std::string::npos) {
            try {
                int i = std::stoi(input);
                v.push_back(i);
            }
            catch (...) {
                std::cout << "Convert not successfull!" << std::endl;
            }
        }
    }
    printVector(v);

    int twoDigitNums = std::count_if(v.begin(), v.end(), isTwoDigit);
    std::cout << twoDigitNums << std::endl;

    auto it = std::find_if(v.begin(), v.end(), isTwoDigit);
    if (it != v.end()) std::cout << (*it) << std::endl;
    /*Cetvrti Zadatak*/
}

