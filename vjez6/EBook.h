#pragma once
#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
	std::string fileName;
	double size;
public:
	// Constructor
	EBook(std::string author, std::string title, int year,
		std::string fileName, double size) : Book(author, title, year),
		fileName(fileName), size(size) {};
	
	// Getteri
	std::string getFileName() const { return fileName; }
	double getSize() const { return size; }

	// Setteri
	void setFileName(std::string fileName) { this->fileName = fileName; }
	void setSize(double size) { this->size = size; }

	// Override Virtualne funkcije
	double getBookSizeInMB() { return size; };
};



#endif // !EBOOK_H
