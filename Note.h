/*Note.h*/

#ifndef NOTE
#define NOTE

#include <iostream>
#include <istream>
#include <string>
#include <ostream>

using namespace std;

class Note {
private:
	string firstname;
	string secondname;
	string phonenumber;
	int birthday[3];

public:
	Note();
	Note(string firstname, string secondname, string phonenumber, int *birthday);
	Note(const Note& worker);
	~Note();

	string getFirstname();
	string getSecondname();
	string getPhonenumber();
	int getBirthday();
	void setFirstname(string firstname);
	void setSecondname(string secondname);
	void setPhonenumber(string phonenumber);
	int setBirthday(int year, int month, int day);

	friend istream& operator>>(istream& s, Note& note);
	friend ostream& operator<<(ostream& s, const Note& note);
};

#endif //NOTE