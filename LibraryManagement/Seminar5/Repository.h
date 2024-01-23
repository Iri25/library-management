#pragma once
#include "Volume.h"
#include "ValidationException.h"
#include "ValidationVolume.h"
#include <vector>
using namespace std;

class Repository
{
protected:
	ValidationVolume* validation;
public:
	virtual void add(Volume*) = 0;
	virtual int remove(Volume*) = 0;
	virtual int find(Volume*) = 0;
	virtual int size() = 0;
	virtual int update(Volume*, Volume*)=0;
	virtual vector<Volume*> getAll() = 0;
};