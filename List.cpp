/*List.cpp*/

#include "List.h"
#include "time.h"

List::List() {
	this->size = 0;
	cout << "Объект класса List был создан конструктором по умолчанию" << endl;
}

List::~List() {
	this->size = 0;
	delete[] notes;
	cout << "Объект класса List удалён" << endl;
}

int List::getSize() {
	return this->size;
}

void List::add(Note* wr) {
	Note* buf = new Note(*wr);
	this->size++;
	Note** copy = new Note * [this->size - 1];
	for (int i = 0; i < this->size - 1; i++) {
		copy[i] = this->notes[i];
	}
	this->notes = new Note * [this->size];
	for (int i = 0; i < this->size - 1; ++i) {
		this->notes[i] = copy[i];
	}
	this->notes[this->size - 1] = buf;
	delete[]copy;
}

void List::print() {
	if (this->size == 0)
		cout << "Cписок пуст" << endl;
	else {
		for (int i = 0; i < this->size; ++i) {
			cout << *this->notes[i] << endl;
		}
	}
}

List& List::sort() {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if ((*this->notes[i]).getSecondname().compare((*this->notes[j]).getSecondname()) < 0) {
				Note* note = this->notes[i];
				this->notes[i] = this->notes[j];
				this->notes[j] = note;
			}
		}
	}
	return *this;
}

List& List::find(int value, List* finded) {
	int size = finded->getSize();
	for (int i = 0; i < size; i++) {
		delete finded->notes[i];
		finded->size--;
	}
	int wmonth = value;
	int fl = 0;
	for (int i = 0; i < this->size; i++) {
		if (wmonth == (*this->notes[i]).getBirthday()) {
			finded->add(notes[i]);
			//cout << *workers[i] << endl << endl;
			fl = 1;
		}
	}
	if (fl == 0)
		cout << "В записях таких людей не обнаружено.\n";
	return *finded;
}