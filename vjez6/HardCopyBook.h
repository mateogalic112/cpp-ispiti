#pragma once
#ifndef HARDCOPYBOOK_H
#define HARDCOPYBOOK_H

#include "Book.h"

class HardCopyBook : public Book{
	int pageCount;
public:
	//Constructor
	HardCopyBook(std::string author, std::string title, int year, int pageCount)
		: Book(author, title, year), pageCount(pageCount) {};

	// Getter
	int getPageCount() const { return pageCount; }

	//Setter
	void setPageCount(int pageCount) { this->pageCount = pageCount; }

	// Override Virtualne funkcije
	double getBookSizeInMB() { return 0; };
};

#endif // !HARDCOPYBOOK_H
