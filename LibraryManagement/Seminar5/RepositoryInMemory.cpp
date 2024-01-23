#include "RepositoryInMemory.h"
#include <algorithm>
#include <iterator>

RepositoryInMemory::RepositoryInMemory(ValidationVolume *validator)
{
	this->validation = validator;
}

RepositoryInMemory::~RepositoryInMemory()
{
	for (Volume* volume : items)
		delete volume;
}

void RepositoryInMemory::add(Volume* volume)
{  
	if(validation->validate(volume)==0)
	{
		items.push_back(volume);
	}
	else
		throw ValidationException(validation->toString().c_str());
}

int RepositoryInMemory::update(Volume* oldVolume, Volume* newVolume)
{
	if (validation->validate(newVolume)) 
	{
		std::replace(items.begin(), items.end(), oldVolume, newVolume);
		return 0;
	}
	throw ValidationException(validation->toString().c_str());
}

int RepositoryInMemory::remove(Volume* volume)
{
	for (int i = 0;i<items.size();i++)
	{
		if (items[i]->equals(volume))
			delete items[i];
		items[i] = items[items.size() - 1];
		items.pop_back();
	}
	return 0;
}

vector<Volume*> RepositoryInMemory::getAll()
{
	return items;
}

int RepositoryInMemory::size()
{
	return items.size();
}

int RepositoryInMemory::find(Volume* volume)
{
	for (Volume* crt : items) {
		if (crt->equals(volume)) 
			return 0;
	}
	return -1;
}