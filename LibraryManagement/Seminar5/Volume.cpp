#include "Volume.h"
#include <cstddef>

Volume::Volume()
{
	available = true;
}

Volume::Volume(const char* author, const char* title)
{
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->available = true;
}

Volume::Volume(const Volume & volume)
{
	author = new char[strlen(volume.author) + 1];
	strcpy_s(author, strlen(volume.author) + 1, volume.author);
	title = new char[strlen(volume.title) + 1];
	strcpy_s(title, strlen(volume.title) + 1, volume.title);
	available = volume.available;
}

Volume::~Volume()
{
	if (title) 
		delete[] title;
	title = NULL;
	if (author)
		delete[] author;
	author = NULL;
}

bool Volume::operator==(const Volume& volume)
{
	return strcmp(author, volume.author) == 0 and strcmp(title, volume.title) == 0;
}

bool Volume::equals(Volume* volume)
{
	return strcmp(author, volume->author) == 0 and strcmp(title, volume->title) == 0;
}

char* Volume::getAuthor()
{
	return author;
}

char* Volume::getTitle()
{
	return title;
}

bool Volume::getAvailable()
{
	return available;
}

void Volume::setAuthor(const char *author)
{
	if (author) 
		delete[] author;
	strcpy_s(this->author, strlen(author) + 1, author);
}

void Volume::setTitle(const char* title)
{
	if (title)
		delete[] title;
	strcpy_s(this->title, strlen(title) + 1, title);
}

void Volume::setAvailable(bool available)
{
	this->available = available;
}

bool Volume::isAvailable()
{
	return (available == true);
}

string Volume::toString()
{
	char* text = new char[strlen(author) + strlen(title) + 20];
	int dim = strlen(author) + strlen(title) + 20;
	strcpy_s(text, strlen( author) + 1, author);
	strcat_s(text, dim, " ");
	strcat_s(text, dim, title); 
	strcat_s(text, dim, " ");
	if (available) 
		strcat_s(text, dim,"disponibil");
	else 
		strcat_s(text, dim, "imprumutat");

	return string(text);
}