#pragma once
#ifndef FILEINTERFACE_H
#define FILEINTERFACE_H

class FileInterface {
public:
	virtual void openFile(bool) = 0;
	virtual void closeFile(bool) = 0;
	virtual void readFile() = 0;
	virtual void writeFile(std::string) = 0;
};

#endif // !FILEINTERFACE_H
