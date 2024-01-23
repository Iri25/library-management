#pragma once
#include "Volume.h"

class Poems : public Volume

{protected:
	int numberPoems;
public:
	Poems();
	Poems(const char*, const char*, int);
	Poems(const Poems&);
	~Poems();

	bool operator==(const Poems&);
	bool equals(Volume*);

	int getNumberPoems();
	void setNumberPoems(int);

	string toString();
};