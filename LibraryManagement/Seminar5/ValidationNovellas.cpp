#include "ValidationNovellas.h"

ValidationNovellas::ValidationNovellas():ValidationVolume()
{
}

ValidationNovellas::~ValidationNovellas()
{
}

int ValidationNovellas::validate(Volume *volume)
{
	Novellas* novallas = (Novellas*)volume;
	ValidationVolume::validate(novallas);
	if (novallas->getPublishingHouse() == "") 
	{
		errors++; 
		message += "Editura trebuie sa nu fie vida! ";
	}

	for (int i = 0; i < strlen(novallas->getPublishingHouse()); i++)
		if (!isalpha(novallas->getPublishingHouse()[i]))
		{ 
			errors++; message += "Editura trebuie sa contina doar litere! "; 
			break;
		}
	return errors;
}