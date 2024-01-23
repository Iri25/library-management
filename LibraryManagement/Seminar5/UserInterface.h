#pragma once
#include "Service.h"

class UserInterface
{
private:
	Service service;

	void addVolume();
	void removeVolume();
	void getAllVolume();
	void findVolume();
	void borrowVolume();
	void returnVolume();

	void getAllNovellas();
	void getAllPoems();
	void getAllAway();
	void getAllAvailable();

	void readNovellas(char*&, char*&, char*&);
	void readPoems(char*&, char*&, int&);

	void sortByAuthor();
public:
	UserInterface();
	UserInterface(Service&);
	~UserInterface();

	void showMenu();
}; 