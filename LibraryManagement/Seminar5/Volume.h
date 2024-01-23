#pragma once
#include <string>

using namespace std;

class Volume
{ 
protected:
	char* author;
	char* title;
	bool available;
public:
	Volume();
	Volume(const char* author, const char* title);
	Volume(const Volume&);
	virtual ~Volume();

	virtual bool operator==(const Volume&);
	virtual bool equals(Volume*);

	char* getAuthor();
	char* getTitle();
	bool getAvailable();

	void setAuthor(const char*);
	void setTitle(const char*);
	void setAvailable(bool);

	bool isAvailable();

	virtual string toString();
};