#pragma once
#include "Repository.h"
#include "ValidationVolume.h"

class RepositoryInMemory : public Repository
{
protected:
	vector<Volume*> items;
public:
	RepositoryInMemory(ValidationVolume*);
	~RepositoryInMemory();

	void add(Volume*);
	int update(Volume*, Volume*);
	int remove(Volume*);

	vector<Volume*> getAll();
	int size();

	int find(Volume*);
};