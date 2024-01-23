#include "ValidationVolume.h"
#include "Volume.h"
#include <string>

using namespace std;

ValidationVolume::ValidationVolume()
{
	errors = 0;
}

ValidationVolume::~ValidationVolume()
{
}

int ValidationVolume::validate(Volume* volume)
{
	errors = 0;
	for(int i=0;i<strlen(volume->getAuthor());i++)
		if (!isalpha(volume->getAuthor()[i]) and volume->getAuthor()[i]!=' ') { errors++; message += "Autorul trebuie sa contina numai litere sau spatiu! "; break; }
	
	for (int i = 0; i < strlen(volume->getTitle()); i++)
		if (!isalpha(volume->getTitle()[i]) and volume->getTitle()[i] != ' ') { errors++; message += "Titlul trebuie sa contina numai litere sau spatiu! "; break; }
	return errors;
}

string ValidationVolume::toString()
{
  return message; 
}