#include<iostream>
#include "Human.h"
#include "Student.h"
#include "Graduateh.h"
#include "Teacher.h"
using namespace std;

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 98);
	s.print();

	Teacher t("Ivanov", "Ivan", 35, "1C", 8, 7.5);
	t.print();

	Graduate g("Ivanova", "Larisa", 22, "AS", "AS-05", 90, "Automatical Systems", "Module of online store");
	g.print();
#endif // INHERITANCE
	//Generalisation
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 98),//upcast
		new Student("Vercetti","Tomas",30,"Criminal","Vice",90), // upcast
		new Teacher("Ivanov", "Ivan", 35, "1C", 8, 7.5), // upcast
		new Student("Diaz","Ricardo",55,"Weapons istribution","Vice",80),
		new Graduate("Ivanova", "Larisa", 22, "AS", "AS-05", 90, "Automatical Systems", "Module of online store"),
		new Teacher("Eistein","Albert",143,"Astronomy",120,10)
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "----------------------------------------------\n";
		group[i]->print();
	}
	cout << "----------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
	cout << sizeof(Human*)<<endl;//размер массива в байтах
	cout << sizeof(group)<<endl;//размер 1 элемента массива в байтах
	cout << sizeof(group) / sizeof(Human*) << endl;//так получаем, что выводить надо для 6 элементов массива
}