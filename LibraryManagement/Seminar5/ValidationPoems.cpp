#include "ValidationPoems.h"

ValidationPoems::ValidationPoems():ValidationVolume()
{
}

ValidationPoems::~ValidationPoems()
{
}

int ValidationPoems::validate(Volume* volume)
{
	Poems* poems = (Poems*)volume;
	ValidationVolume::validate(poems);
	if (poems->getNumberPoems() <= 0)
	{
		errors++; 
		message += "Numarul de poezii trebuie sa fie pozitiv!";
	}
	return errors;
}