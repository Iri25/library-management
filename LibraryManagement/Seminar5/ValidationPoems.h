#pragma once
#include "Poems.h"
#include "ValidationVolume.h"


class ValidationPoems: public ValidationVolume
{
	
public:
	ValidationPoems();
	~ValidationPoems();

	int validate(Volume*);
};