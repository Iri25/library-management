#pragma once
#include <exception>
using namespace std;

class ValidationException : public exception 
{
private:
	char* msg;
public:
	ValidationException()
	{
		if (msg) delete[] msg;
	}
	ValidationException(const char* m) 
	{ 
		msg = new char[strlen(m)] + 1;
		strcpy_s(msg, strlen(m) + 1, m);
	}

	virtual const char* what() const throw()
	{
		return msg;
	}
};