#include "Service.h"
#include "Novellas.h"
#include "Poems.h"
#include <algorithm>

template<typename Base, typename T>
inline bool instanceof(const T*) 
{
	return is_base_of<Base, T>::value;
}

Service::Service()
{
}

Service::Service(Repository &repositoryNovellas, Repository &repositoryPoems)
{
	this->repositoryNovellas =&repositoryNovellas;
	this->repositoryPoems =&repositoryPoems;
}

Service::~Service()
{
}

void Service::addNovellas(char* author, char* title, char* publishingHouse)
{ 
	try
	{
		Volume* volume = new Novellas(author, title, publishingHouse);
		repositoryNovellas->add(volume);
	}
	catch (ValidationException ex)
	{
		throw ex;
	}
}

int Service::removeNovellas(char* author, char* title, char* publishingHouse)
{
	return repositoryNovellas->remove(new Novellas(author, title, publishingHouse));
}

vector<Volume*> Service::getAllNovellas()
{

	return repositoryNovellas->getAll();
}

int Service::findNovellas(char* author, char* title, char* publishingHouse)
{
	return repositoryNovellas->find(new Novellas(author, title, publishingHouse));
}

//returneaza 0 la succes, -1 daca nu exista nuvela, -2 daca nu e disponibila
int Service::borrowNovellas(char* author, char* title, char* publishingHouse)
{
	Novellas* novellas = new Novellas(author, title, publishingHouse);
	vector<Volume*> all = repositoryNovellas->getAll();
	for (Volume* volume : all)
	{
		if (volume->equals(novellas))
		{
			if (volume->isAvailable())
			{
				volume->setAvailable(false);
				return 0;
			}
			else 
				return -2;
		}
	}
	return -1;
}

int Service::returnNovellas(char* author, char* title, char* publishingHouse)
{
	Novellas* novellas = new Novellas(author, title, publishingHouse);
	vector<Volume*> all = repositoryNovellas->getAll();
	for (Volume* volume : all)
	{
		if (volume->equals(novellas))
		{
			volume->setAvailable(true);
			return 0;
		}
	}
	return -1;
}

void Service::addPoems(char* author, char* titlu, int numberPoems)
{
	Volume* volume = new Poems(author, titlu, numberPoems);
	try
	{
		repositoryPoems->add(volume);
	}
	catch (ValidationException ex) 
	{
		throw ex;
	}
}

int Service::removePoems(char* author, char* tiltle, int numberPoems)
{
	return repositoryPoems->remove(new Poems(author, tiltle, numberPoems));
}

vector<Volume*> Service::getAllPoems()
{
	return repositoryPoems->getAll();
}

int Service::findPoems(char* author, char* title, int numberPoems)
{
	return repositoryPoems->find(new Poems(author, title, numberPoems));
}

int Service::borrowPoems(char* author, char* title, int numberPoems)
{
	Poems* poems = new Poems(author, title, numberPoems);
	vector<Volume*> all = repositoryPoems->getAll();
	for (Volume* volume : all)
	{
		if (volume->equals(poems))
		{
			if (volume->isAvailable())
			{
				volume->setAvailable(false);
				return 0;
			}
			else
				return -2;
		}
	}
	return -1;
}

int Service::returnPoems(char* author, char* title, int numberPoems)
{
	Poems * poems = new Poems(author, title, numberPoems);
	vector<Volume*> all = repositoryPoems->getAll();
	for (Volume* volume : all)
	{
		if (volume->equals(poems))
		{
			volume->setAvailable(true);
			return 0;
		}
	}
	return -1;
}

vector<Volume*> Service::getAll()
{
	vector<Volume*> novellas(repositoryNovellas->getAll());
	vector<Volume*> poems = repositoryPoems->getAll();

	novellas.insert(novellas.end(), poems.begin(), poems.end());
	return novellas;
}

vector<Volume*> Service::allAway()
{
	vector<Volume*>result;
	for (Volume* volume : repositoryNovellas->getAll())
		if (volume->getAvailable() == false)
			result.push_back(volume);
	for (Volume* volume : repositoryPoems->getAll())
		if (volume->getAvailable() == false)
			result.push_back(volume);
	return result;
}

vector<Volume*> Service::allAvailable()
{
	vector<Volume*>result;
	for (Volume* volume : repositoryNovellas->getAll())
		if (volume->isAvailable())
			result.push_back(volume);
	for (Volume* volume : repositoryPoems->getAll())
		if (volume->isAvailable())
			result.push_back(volume);
	return result;
}

bool compareByAuthor(Volume* a, Volume* b) 
{
	return (strcmp(a->getAuthor(), b->getAuthor()) < 0);
}

vector<Volume*> Service::sortByAuthor()
{
	vector<Volume*> allNovellas = repositoryNovellas->getAll();
	std::sort(allNovellas.begin(), allNovellas.end(), compareByAuthor);

	vector<Volume*> allPoems = repositoryPoems->getAll();
	std::sort(allPoems.begin(), allPoems.end(), compareByAuthor);

	vector<Volume*> all(allNovellas.size()+allPoems.size());

	std::merge(allPoems.begin(), allPoems.end(), allNovellas.begin(), allNovellas.end(), all.begin(),compareByAuthor);
	return all;
}

vector<Volume*> Service::findByTitle(const char * title)
{
	vector<Volume*> allNovellas = repositoryNovellas->getAll();
	vector<Volume*> result;
	for (Volume* current : allNovellas)
	{
		if (strstr(current->getTitle(), title))
			result.push_back(current);
	}

	vector<Volume*> allPoems = repositoryPoems->getAll();
	for (Volume* current : allPoems)
	{
		if (strstr(current->getTitle(), title))
			result.push_back(current);
	}
	return result;
}