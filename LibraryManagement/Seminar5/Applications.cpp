#include "Poems.h"
#include "Novellas.h"
#include "RepositoryInMemory.h"
#include "ValidationPoems.h"
#include "ValidationNovellas.h"
#include "UserInterface.h"
#include "TestService.h"
#include <iostream>
using namespace std;

/*O biblioteca gestioneaza volume literare. In biblioteca exista doua tipuri de volume: 
nuvele (autor, titlu,editura) si volume de poezii (autor, titlu, numar de poezii). 
Scrieti o aplicatie care va ajuta bibliotecara in gestiunea volumelor 
(adaugare, stergere volume, imprumut volume, returnare volume, cautare volume, vizualizare volume sortate dupa autor).
Se va defini un singur Repository care sa gestioneze volumele din biblioteca.
*/

int main() {

	TestService testService;
	testService.runTests();

	ValidationVolume* validationPoems = new ValidationPoems();
	ValidationVolume* validationNovellas = new ValidationNovellas();
	Repository* repositoryPoems = new RepositoryInMemory(validationPoems);
	Repository* repositoryNovellas = new RepositoryInMemory(validationNovellas);
	
	Service service(*repositoryNovellas, *repositoryPoems);

	UserInterface userInterface(service);
	userInterface.showMenu();
	
	delete validationPoems;
	delete validationNovellas;
	delete repositoryPoems;
	delete repositoryNovellas;

	return 0;
}