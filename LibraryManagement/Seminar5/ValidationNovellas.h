#pragma once
#include "Novellas.h"
#include "ValidationVolume.h"

class ValidationNovellas:public ValidationVolume
{
public:
	ValidationNovellas();
	~ValidationNovellas();

	int validate(Volume*);
};