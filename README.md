# library-management
C++ application with a 4-layered architecture: 
- data access layer (`Domain`)
- persistence layer (`Repository`)
- business layer (`Service`)
- presentation layer (`UserInterface`)

The data is saved in memory. Several tests for functionality and data validation have been created. The main class is Applications. Interaction with the user is done from the console.

## Key concepts:
- encapsulation
- inheritance
- polymorphism
- validations
- exceptions

## Requirements

Application for managing a library with literary volumes. There are two types of volumes in the library: volumes of short stories (author, title, publisher) and volumes of poems (author, title, number of poems).

The application helps the librarian in the management of volumes, operations such as:
1.  Adding volumes
2.  Deleting volumes
3.  Borrowing volumes
4.  Returning volumes
5.  Searching for volumes
6.  Viewing volumes sorted by author.
