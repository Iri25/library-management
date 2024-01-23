#pragma once
#include "Repository.h"

class Service
{
protected:
	Repository* repositoryNovellas;
	Repository* repositoryPoems;
public:
	Service();
	Service(Repository&, Repository&);
	~Service();
	
	void addNovellas(char*, char*, char*);
	int removeNovellas(char*, char*, char*);
	vector<Volume*> getAllNovellas();
	int findNovellas(char*, char*, char*);
	int borrowNovellas(char*, char*, char*);
	int returnNovellas(char*, char*, char*);

	void addPoems(char*, char*, int);
	int removePoems(char*, char*, int);
	vector<Volume*> getAllPoems();
	int findPoems(char*, char*, int);
	int borrowPoems(char*, char*, int);
	int returnPoems(char*, char*, int);

	vector<Volume*> getAll();
	vector<Volume*> allAway();
	vector<Volume*> allAvailable();
	
	vector<Volume*> sortByAuthor();
	vector<Volume*> findByTitle(const char*);
};