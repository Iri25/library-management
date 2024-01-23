#include "Poems.h"

Poems::Poems()
{
	numberPoems = 0;
}

Poems::Poems(const char* author, const char * title, int numberPoems):Volume(author, title)
{
	this->numberPoems = numberPoems;
}

Poems::Poems(const Poems &poems):Volume(poems)
{
	numberPoems = poems.numberPoems;
}

Poems::~Poems()
{
}

bool Poems::operator==(const Poems& poems)
{
	return Volume::operator==(poems) and (numberPoems == poems.numberPoems);
}

bool Poems::equals(Volume* volume)
{
	return Volume::equals(volume) and (numberPoems == ((Poems*)volume)->numberPoems);
}
int Poems::getNumberPoems()
{
	return numberPoems;
}

void Poems::setNumberPoems(int numberPoems)
{
	this->numberPoems = numberPoems;
}

string Poems::toString()
{
	string text = this->Volume::toString();
	text = text +" "+ std::to_string(numberPoems);
	return text;
}