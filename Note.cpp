/*Worker.cpp*/

#include "Note.h"

Note::Note() {
	firstname = "";
	secondname = "";
	phonenumber = "";
	birthday[0] = 0;
	birthday[1] = 0;
	birthday[2] = 0;
	cout << "������ ������ Note ��� ������ ������������� ��� ����������" << endl;
}

Note::Note(string firstname, string secondname, string phonenumber, int *birthday) {
	this->firstname = firstname;
	this->secondname = secondname;
	this->phonenumber = phonenumber;
	this->birthday[0] = birthday[0];
	this->birthday[1] = birthday[1];
	this->birthday[2] = birthday[2];
	cout << "������ ������ Note " << firstname << " " << secondname << " ��� ������ ������������� � �����������" << endl;
}

Note::Note(const Note& note) {
	this->firstname = note.firstname;
	this->secondname = note.secondname;
	this->phonenumber = note.phonenumber;
	this->birthday[0] = note.birthday[0];
	this->birthday[1] = note.birthday[1];
	this->birthday[2] = note.birthday[2];
	cout << "������" << firstname << " " << secondname << " ��� ������ ������������� �����������" << endl;
}

Note::~Note() {
	cout << "������� ������ Note " << firstname << " " << secondname << endl;
	this->firstname = "";
	this->secondname = "";
	this->phonenumber = "";
	this->birthday[0] = 0;
	this->birthday[1] = 0;
	this->birthday[2] = 0;
}

string Note::getFirstname() {
	return this->firstname;
}

string Note::getSecondname() {
	return this->secondname;
}

string Note::getPhonenumber() {
	return this->phonenumber;
}

int Note::getBirthday() {
	return this->birthday[1];
}

void Note::setFirstname(string firstname) {
	this->firstname = firstname;
}

void Note::setSecondname(string secondname) {
	this->secondname = secondname;
}

void Note::setPhonenumber(string phonenumber) {
	this->phonenumber = phonenumber;
}

int Note::setBirthday(int year, int month, int day) {
	this->birthday[0] = year;
	this->birthday[1] = month;
	this->birthday[2] = day;
	return month;
}

istream& operator>>(istream& s, Note& note) {
	cout << "������� ��� " << endl;
	cin >> note.firstname;
	cout << "������� ������� " << endl;
	cin >> note.secondname;
	cout << "������� ����� �������� (������: 89213334455) " << endl;
	s >> note.phonenumber;
	cout << "������� ��� �������� " << endl;
	int year = 0;
	int month = 0;
	int day = 0;
	s.clear();
	s.sync();
	s >> year;
	while ((month < 1)||(month > 12))
	{
		cout << "������� ����� �������� " << endl;
		s.clear();
		s.sync();
		s >> month;
	}
	while ((day < 1) || (day > 31))
	{
		cout << "������� ���� �������� " << endl;
		s.clear();
		s.sync();
		s >> day;
	}
	note.setBirthday(year, month, day);
	return s;
}

ostream& operator<<(ostream& s, const Note& note) {
	cout << "���: " << note.firstname << endl;
	cout << "�������: " << note.secondname << endl;
	cout << "�������: " << note.phonenumber << endl;
	cout << "���� ��������: " << note.birthday[0] << "/" << note.birthday[1] << "/" << note.birthday[2] << endl;
	return s;
}