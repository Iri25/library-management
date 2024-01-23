#pragma once
#include "Service.h"

class TestService
{
private:
	Service service;
public:
	TestService();
	~TestService();

	void runTests();
};