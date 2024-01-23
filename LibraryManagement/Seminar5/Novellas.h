#pragma once
#include "Volume.h"

class Novellas : public Volume
{
protected:
	char* publishingHouse;
public:
	Novellas();
	Novellas(const char*, const char*, const char*);
	Novellas(const Novellas&);
	~Novellas();

	bool operator==(const Novellas&);
	bool equals(Volume*);

	char* getPublishingHouse();

	void setPublishingHouse(const char*);

	string toString();
};