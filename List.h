/*List.h*/

#ifndef LIST
#define LIST

#include <iostream>
#include "Note.h"

using namespace std;

class List {
private:
	Note** notes;
	int size;
public:
	List();
	~List();
	int getSize();

	void print();
	void add(Note* nr);
	List& sort();
	List& find(int value, List* finded);
};

#endif //LIST