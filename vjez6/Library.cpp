
#include "Library.h"

std::vector<std::string> Library::getAllTitles(
	const std::string authorName) {
	std::vector<std::string> titles;

	for (auto it = books.begin(); it != books.end(); ++it) {
		if (authorName == (*it)->getAuthor())
			titles.push_back((*it)->getTitle());
	}

	return titles;
}

double Library::resultBooksSize(std::string authorName) {
	double resultSize = 0;

	for (auto it = books.begin(); it != books.end(); ++it) {
		if (authorName == (*it)->getAuthor())
			resultSize += (*it)->getBookSizeInMB();
	}

	return resultSize;
}

std::vector<Book*> Library::getAllSearchedBooks(std::string titleSubstring) {
	std::vector<Book*> searchedBooks;

	for (auto it = books.begin(); it != books.end(); ++it) {
		if ((*it)->getTitle().find(titleSubstring) != -1)
			searchedBooks.push_back((*it));
	}

	return searchedBooks;
}

void Library::addBooks(Book* book) {
	books.push_back(book);
}