
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "EBook.h"
#include "HardCopyBook.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{   
    vector<Book*> newBooks;

    ifstream f("knjige.txt");
    string line;

    while (getline(f, line)) {
        int checkForCommas = count(line.begin(), line.end(), ';');
        string author, title, fileName, size, pageCount;
        int counter = 0;
        for (auto it = line.begin(); it != line.end(); ++it) {
            if (*it != ';' && counter == 0) author.push_back(*it);
            else if (*it != ';' && counter == 1) title.push_back(*it);
            else if (checkForCommas < 3 && *it != ';' && counter == 2) pageCount.push_back(*it);
            else if (checkForCommas > 2 && *it != ';' && counter == 2) fileName.push_back(*it);
            else if (checkForCommas > 2 && *it != ';' && counter == 3) size.push_back(*it);
            else counter++;
        }
        int year = 0;
        if (checkForCommas > 2) {
            size.erase(remove(size.begin(), size.end(), 'M'), size.end());
            double parseSize = atof(size.c_str());
            EBook ebook(author, title, year, fileName, parseSize);
            newBooks.push_back(&ebook);
        }
        else {
            int parsePageCount = atoi(pageCount.c_str());
            HardCopyBook oldBook(author, title, year, parsePageCount);
            newBooks.push_back(&oldBook);
        }
    }

    Library library(newBooks);

    /*vector<string> authorTitles = library.getAllTitles("Aldous Huxley ");

    cout << authorTitles.size() << endl;*/

    /*for (auto it = library.getBooks().begin(); it != library.getBooks().end(); ++it) {
        cout << *it << endl;
    }*/
}
