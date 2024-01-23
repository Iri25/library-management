#include "UserInterface.h"
#include "Novellas.h"
#include "Poems.h"
#include <iostream>

using namespace std;

UserInterface::UserInterface()
{
}

UserInterface::UserInterface(Service& service)
{
	this->service = service;
}

UserInterface::~UserInterface()
{
}

void UserInterface::addVolume()
{
	cout << ">>>>ADAUGARE VOLUM<<<<" << endl;
	int option=0;
	while (option != 1 && option != 2) 
	{
		cout << "	1. Adauga nuvela" << endl;
		cout << "	2. Adauga poezii" << endl;
		cout << "Introduceti optiunea:";
		cin >> option;

		if (option == 1)
		{
			char *author, *title, *publishingHouse;
			readNovellas(author, title, publishingHouse);
			try 
			{
				service.addNovellas(author, title, publishingHouse);
			}
			catch (ValidationException ex)
			{
				cout << ex.what()<<endl;
			}
			delete[]author;
			delete[] title;
			delete[]publishingHouse;
		}
		if (option == 2) 
		{
			char *author, *title;
			int numberPoems;
			readPoems(author, title, numberPoems);
			try
			{
			  service.addPoems(author, title, numberPoems);
			}
			catch (ValidationException ex)
			{
				cout << ex.what()<<endl;
			}
			delete[]author;
			delete[]title;
		}
	}
	cout << "*********************************************" << endl;
}

void UserInterface::removeVolume()
{
	cout << ">>>>STERGERE VOLUM<<<<" << endl;
	int option = 0, result;
	while (option != 1 && option != 2) 
	{
		cout << "1. Sterge nuvela" << endl;
		cout << "2. Sterge poezii" << endl;
		cout << "Introduceti optiunea:";
		cin >> option;

		if (option == 1)
		{
			char* author, * title, * publishingHouse;
			readNovellas(author, title, publishingHouse);
			result = service.removeNovellas(author, title, publishingHouse);
			if (result == 0) cout << "Volumul de nuvele a fost sters!" << endl;
			else cout << "Volumul nu a fost sters" << endl;
			delete[]author;
			delete[] title;
			delete[]publishingHouse;
		}
		if (option == 2)
		{
			char* author, * title;
			int numberPoems;
			readPoems(author, title, numberPoems);
			result = service.removePoems(author, title, numberPoems);
			if (result == 0) cout << "Volumul de poeziia fost sters!" << endl;
			else cout << "Volumul nu a fost sters" << endl;
			delete[]author;
			delete[]title;
		}
	}
	cout << endl;
}

void UserInterface::getAllVolume()
{
	cout << ">>>>TOATE VOLUMELE<<<<" << endl;
	vector<Volume*> all = service.getAll();
	for (Volume* volume : all)
		cout << volume->toString() << endl;
	cout << endl;
}

void UserInterface::findVolume()
{
	cout << ">>>>>CAUTARE VOLUM<<<<<" << endl;
	int option = 0;
	while (option != 1 && option != 2) 
	{
		cout << "1. Cauta nuvela" << endl;
		cout << "2. Cauta poezii" << endl;
		cout << "Introduceti optiunea:";
		cin >> option;

		if (option == 1)
		{
			char* author, * title, * publishingHouse;
			readNovellas(author, title, publishingHouse);
			int rez = service.findNovellas(author, title, publishingHouse);
			if (rez == 0) cout << "Nuvela exista in biblioteca!" << endl;
			else cout << "Nuvela nu exista in biblioteca!" << endl;
			delete[]author;
			delete[] title;
			delete[]publishingHouse;
		}
		if (option == 2)
		{
			char* autor, * title;
			int numberPoems;
			readPoems(autor, title, numberPoems);
			int rez = service.findPoems(autor, title, numberPoems);
			if (rez == 0) cout << "Volumul de poezii exista in biblioteca!" << endl;
			else cout << "Volumul de poezii nu exista in biblioteca!" << endl;
			delete[]autor;
			delete[]title;
		}
	}
	cout << endl;
}
void UserInterface::borrowVolume()
{
	cout << ">>>>IMPRUMUTA VOLUM<<<<" << endl;
	int option = 0;
	while (option != 1 && option != 2) 
	{
		cout << "1. Imprumuta nuvela" << endl;
		cout << "2. Imprumuta poezii" << endl;
		cout << "Introduceti optiunea:";
		cin >> option;

		if (option == 1)
		{
			char *author, *title, *publishingHouse;
			readNovellas(author, title, publishingHouse);
			int result=service.borrowNovellas(author, title, publishingHouse);
			if (result == 0) cout << "Volum imprumutat cu succes!" << endl;
			if (result == -1) cout << "Volumul nu exista!" << endl;
			if (result == -2) cout << "Volumul nu e disponibil" << endl;
			delete[]author;
			delete[] title;
			delete[]publishingHouse;
		}
		if (option == 2)
		{
			char* author, *title;
			int numberPoems;
			readPoems(author, title, numberPoems);
			int result=service.borrowPoems(author, title, numberPoems);
			if (result == 0) cout << "Volum imprumutat cu succes!" << endl;
			if (result == -1) cout << "Volumul nu exista!" << endl;
			if (result == -2) cout << "Volumul nu e disponibil" << endl;
			delete[]author;
			delete[]title;
		}
	}
	cout << endl;
}

void UserInterface::returnVolume()
{
	cout << ">>>>RETURNARE VOLUM<<<<<" << endl;
	int option = 0;
	while (option != 1 && option != 2) 
	{
		cout << "1. Returneaza nuvela" << endl;
		cout << "2. Returneaza poezii" << endl;
		cout << "Introduceti optiunea:";
		cin >> option;

		if (option == 1)
		{
			char *author, *title, *publishingHouse;
			readNovellas(author, title, publishingHouse);
			int result = service.returnNovellas(author, title, publishingHouse);
			if (result == 0) cout << "Volum returnat cu succes!" << endl;
			else cout << "Volumul nu a putut fi returnat!" << endl;
			delete[]author;
			delete[] title;
			delete[]publishingHouse;
		}
		if (option == 2) 
		{
			char* author, *title;
			int numberPoems;
			readPoems(author, title, numberPoems);
			int result = service.returnPoems(author, title, numberPoems);
			if (result == 0) cout << "Volum returnat cu succes!" << endl;
			else cout << "Volumul nu a putut fi returnat!" << endl;
			delete[]author;
			delete[]title;
		}
	}
	cout << endl;
}

void UserInterface::getAllNovellas()
{
	cout << ">>>>>TOATE NUVELELE<<<<<<<<<" << endl;
	for (Volume* novallas : service.getAllNovellas())
		cout << novallas->toString() << endl;
	cout << endl;
}

void UserInterface::getAllPoems()
{
	for (Volume* poems : service.getAllPoems())
		cout << poems->toString() << endl;
	cout << endl;
}

void UserInterface::getAllAway()
{
	cout << ">>>>TOATE VOLUMELE IMPRUMUTATE<<<<" << endl;
	vector<Volume*> all = service.allAway();
	for (Volume* volume : all)
		cout << volume->toString() << endl;
}

void UserInterface::getAllAvailable()
{
	cout << ">>>>TOATE VOLUMELE DISPONIBILE<<<<<<" << endl;
	vector<Volume*> all = service.allAvailable();
	for (Volume* volume : all)
		cout << volume->toString() << endl;
	cout << endl;
}

void UserInterface::readNovellas(char*& author, char*& title, char*& publishingHouse)
{
	cout << "Dati autor:";
	author = new char[20];
	cin.ignore();
	cin.getline(author, 20);
	cout << endl<<"Dati titlu:";
	title = new char[50];
	cin.getline(title,50);
	cout << endl<<"Dati editura:";
	publishingHouse = new char[20];
	cin.getline(publishingHouse,20);
}

void UserInterface::readPoems(char *&author, char *&title, int &numberPoems)
{
	cout << "Dati autor:";
	author = new char[20];
	cin.ignore();
	cin.getline(author,20);
	cout << "Dati titlu:";
	title = new char[50];
	cin.getline(title,50);
	cout << "Dati nr poezii:";
	cin >> numberPoems;
}

void UserInterface::sortByAuthor()
{
	cout << ">>>>VOLUMELE SORTATE DUPA AUTOR<<<<" << endl;
	for (Volume* volume : service.sortByAuthor())
		cout << volume->toString() << endl;
	cout << endl;
}

void UserInterface::showMenu()
{
	bool ok = false;
	while (!ok) 
	{
		cout <<endl<< "----------->  MENIU PRINICPAL <-----------------" << endl;
		cout << "1. Adauga un volum" << endl;
		cout << "2. Imprumuta volum" << endl;
		cout << "3. Returneaza volum" << endl;
		cout << "4. Cauta volum" << endl;
		cout << "5. Toate volumele" << endl;
		cout << "6. Sterge volum" << endl;
		cout << "7. Toate volumele imprumutate" << endl;
		cout << "8. Toate volumele disponibile" << endl;
		cout << "9. Toate nuvelele" << endl;
		cout << "10. Toate poeziile " << endl;
		cout << "11. Toate volumele sortate alfabetic dupa autor" << endl;
		cout << "0. Exit" << endl;

		int option;
		cout << "Dati optiunea:";
		cin >> option;
		switch (option) {
		case 1: {addVolume(); break; }
		case 2: {borrowVolume(); break; }
		case 3: {returnVolume(); break; }
		case 4: {findVolume(); break; }
		case 5: {getAllVolume(); break; }
		case 6: {removeVolume(); break; }
		case 7: {getAllAway(); break; }
		case 8: {getAllAvailable(); break; }
		case 9: {getAllNovellas(); break; }
		case 10: {getAllPoems(); break; }
		case 11: {sortByAuthor(); break; }
		case 0: {ok = true; }
		}
	}
}