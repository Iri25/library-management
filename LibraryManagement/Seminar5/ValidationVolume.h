#pragma once
#include "Volume.h"
#include <exception>
#include <string>

using namespace std;

class ValidationVolume
{
protected:
	int errors;
	string message;
public:
	ValidationVolume();
	~ValidationVolume();

	virtual int validate(Volume* );
	string toString();
};

