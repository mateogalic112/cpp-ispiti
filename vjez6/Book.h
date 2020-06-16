#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
protected:
	std::string author;
	std::string title;
	int year;
public:
	// Constructor
	Book(std::string author, std::string title, int year)
		: author(author), title(title), year(year) {};

	// Getteri	
	std::string getAuthor() const { return author; }
	std::string getTitle() const { return title; }
	int getYear() const { return year; }

	// Setteri
	void setAuthor(std::string author) { this->author = author; }
	void setTitle(std::string title) { this->title = title; }
	void setYear(int year) { this->year = year; }

	// Virtualne Funckije - Obavezan ovverride u izvedenim klasama
	virtual double getBookSizeInMB() = 0;

	// Virtualni Destructor - Brisemo izvedene objekte preko pointera na baznu klasu
	virtual ~Book() {};
};

// Poziv destruktora van tijela bazne klase
#endif // !
