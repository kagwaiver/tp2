#include "stdafx.h" 
#include "List.h"
#include "Note.h"
using namespace std;

int main()
{
	int z = 1;
	int a, b;
	int wmonth = 0;
	setlocale(LC_ALL, "Russian");

	List* finded = new List();
	List* nlist = new List();
	Note* nr = new Note();

	int k2;
	int div;
	int smallLetterFound;
	string buf;
	int bufsize;
	ifstream file;
	char Sglas[] = "aeiouy";
	char Bglas[] = "AEIOUY";
	char Wend[] = " .,?!:;()/<>'[]{}|";

	while (z) 
	{
		cout << "Press 1 for STANDART\nPress 2 for STROK and FILE\nPress 3 for EXIT\n";
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "STANDART\n";
			cout << "1 - добавить объект\n";
			cout << "2 - показать все объекты в алфавитном порядке\n";
			cout << "3 - вывести на экран объекты, рождённые в определённый месяц\n";
			cout << "4 - вернуться в главное меню\n";
			cin >> b;
			switch (b)
			{
			case 1:
				cout << "Добавляем объект\n";
				cin >> *nr;
				nlist->add(nr);
				break;
			case 2:
				cout << "Показываем объекты\n";
				nlist->sort();
				nlist->print();
				break;
			case 3:
				wmonth = 0;
				while ((wmonth < 1) || (wmonth > 12))
				{
					cout << "Введите МЕСЯЦ цифрой от 1 до 12 " << endl;
					cin >> wmonth;
				}
				nlist->sort();
				*finded = nlist->find(wmonth, finded);
				finded->print();
				break;
			case 4:
				cout << "Возврат в меню\n";
				break;
			default:
				cout << "Ошибка. Попробуйте ещё раз.\n";
			}
			break;
		case 2:
			cout << "STROK and FILE\n";
			try {
				file.open("file.txt", ios::in);
			}
			catch (const ifstream::failure & e) {
				cout << "Exception opening/reading file";
				exit(EXIT_FAILURE);
			}
			int isPointInLine, isCommaInSent; // no "." / no ","
			int lastdot;
			while (file) {
				getline(file, buf, '\0');
				cout << "Original:\n" << buf << endl;
				bufsize = buf.size();
				for (int i = 0; i < bufsize; i++) {
					div = 0;
					smallLetterFound = 0;
					for (int l = 0; l < 18; l++)
					{
						if (buf[i] == Wend[l])
						{
							div = 1;
							for (int k = 0; k < 6; k++)
							{
								if (buf[i + 1] == Sglas[k])
								{
									smallLetterFound = 1;
									k2 = k;
								}
							}
						}
					}
					if ((div == 1) && (smallLetterFound == 1))
					{
						buf[i + 1] = Bglas[k2];
					}
					cout << buf[i];
					/*if (file.eof())
						break;*/
				}
				cout << "\n";
				file.close();
				break;
		case 3:
			z = 0;
			break;
		default:
			cout << "Error. Try again\n";
			break;
			}
		}
	}
	delete finded;
	delete nlist;
	delete nr;
	return 0;
}