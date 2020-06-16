#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

#include <vector>

class Library {
	std::vector<Book*> books;
public:
	// Constructor
	Library(std::vector<Book*> books) : books(books) {};
	
	// Getter
	std::vector<Book*> getBooks() const { return books; }
	
	// Setter
	void setBooks(std::vector<Book*> books) { this->books = books; }

	// Other
	std::vector<std::string> getAllTitles(const std::string);
	double resultBooksSize(std::string);
	std::vector<Book*> getAllSearchedBooks(std::string);
	void addBooks(Book*);
};

#endif // !LIBRARY_H
