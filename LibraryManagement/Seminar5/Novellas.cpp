#include "Novellas.h"

Novellas::Novellas()
{
	publishingHouse = NULL;
}

Novellas::Novellas(const char * author, const char * title, const char * editura):Volume(author, title)
{
	this->publishingHouse = new char[strlen(editura) + 1];
	strcpy_s(this->publishingHouse, strlen(editura) + 1, editura);
}

Novellas::Novellas(const Novellas &novellas):Volume(novellas)
{
	this->publishingHouse = new char[strlen(novellas.publishingHouse) + 1];
	strcpy_s(this->publishingHouse, strlen( novellas.publishingHouse) + 1, novellas.publishingHouse);
}

Novellas::~Novellas()
{
	if (publishingHouse)
		delete[] publishingHouse;
	publishingHouse = NULL;
}

bool Novellas::operator==(const Novellas& novellas)
{
	return Volume::operator==(novellas) and strcmp(publishingHouse, novellas.publishingHouse) == 0;
}

bool Novellas::equals(Volume* volume)
{
	return Volume::equals(volume) and (strcmp(publishingHouse,((Novellas*) volume)->publishingHouse) == 0);
}

char* Novellas::getPublishingHouse()
{
	return publishingHouse;
}

void Novellas::setPublishingHouse(const char* publishingHouse)
{
	if (this->publishingHouse) 
		delete[] publishingHouse;
	this->publishingHouse = new char[strlen(publishingHouse) + 1];
	strcpy_s(this->publishingHouse, strlen(publishingHouse) + 1, publishingHouse);
}

string Novellas::toString()
{
	string text = Volume::toString();
	string t(publishingHouse);
	text += " " + t;
	return text;
}