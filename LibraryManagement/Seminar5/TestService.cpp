#include "TestService.h"
#include "Repository.h"
#include "RepositoryInMemory.h"
#include "Novellas.h"
#include "Poems.h"
#include "ValidationNovellas.h"
#include "ValidationPoems.h"
#include <cassert>

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::runTests()
{
	ValidationVolume* validationNovellas = new ValidationNovellas();
	ValidationVolume* validationPoems = new ValidationPoems();
	Repository* repository1 = new RepositoryInMemory(validationNovellas);
	Repository* repository2 = new RepositoryInMemory(validationPoems);
	Service service(*repository1, *repository2);

	assert(repository1->size() == 0);


	char* author = new char[10];
	strcpy_s(author, 10, "Goga");

	char* title = new char[20];
	strcpy_s(title, 20, "Amurg");

	service.addPoems(author, title, 25);

	delete[] author;
	delete[]title;

	author = new char[10];
	strcpy_s(author, 10, "Eminescu");

	title = new char[25];
	strcpy_s(title, 25, "Luceafarul");
    service.addPoems(author, title, 12);

	delete[] author;
	delete[]title;

	author = new char[10];
	strcpy_s(author, 10, "Sadoveanu");

	title = new char[20];
	strcpy_s(title, 20, "Baltagul");

	char*publishingHouse = new char[15];
	strcpy_s(publishingHouse, 15, "Nemira");
	service.addNovellas(author, title, publishingHouse);

	delete[] author;
	delete[]title;
	delete[]publishingHouse;

	assert(service.getAll().size() == 3);

	assert(service.getAllNovellas().size() == 1);
	
	assert(service.getAllPoems().size() == 2);

	author = new char[10];
	strcpy_s(author, 10, "Sadoveanu");

	title = new char[20];
	strcpy_s(title, 20, "Baltagul");

	publishingHouse = new char[15];
	strcpy_s(publishingHouse, 15, "Nemira");

	service.removeNovellas(author, title, publishingHouse);
	assert(service.getAllNovellas().size() == 0);
	delete[] author;
	delete[]title;
	delete[]publishingHouse;

	assert(service.findByTitle("Am").size() == 1);
	assert(service.getAll().size() == 2);
}
