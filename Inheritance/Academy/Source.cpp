#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<iomanip>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual~Human()
	{
		cout << "HDestructor\t" << this << endl;
	}
	//Methods:
	virtual ostream& print(ostream& os)const
	{
		return os <<left << setw(10)<<last_name << left << setw(10) << first_name<< left << setw(4)<<age;
		//return os<<last_name << " " << first_name << " " << age << " ";
	}
	virtual void write()const
	{
		ofstream fout("File.txt", std::ios_base::app);
		fout << last_name << " " << first_name << " " << age << " лет.\n";
		fout.close();
	}

};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);

}
class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}

	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//Constuctors:

	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating)
		:Human(last_name, first_name, age)//Делегируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		//return os << /*Специальность:*/" " << speciality << /*" ,группа:*/" " << group << " " <</*,успеваемость:*/" " << rating;
		return os << left << setw(20) << speciality << left << setw(10) << group << left << setw(4)<< rating;
	}
	void write()const
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специальность: " << speciality << " ,группа: " << group << " ,успеваемость: " << rating << endl;
		fout.close();
	}
};

class Teacher : public Human
{
	string speciality;
	unsigned int experience;
	double evil;
public:
	const string& get_peciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	double get_evil()const
	{
		return evil;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_evil(double evil)
	{
		this->evil = evil;
	}
	//Constructors:
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience, double evil)
		:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		set_evil(evil);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		//return os << /*Специализация:*/" " << speciality << " "/*,опыт:*/ << " " << experience << " "/*,строгость:*/ << " " << evil;
		return os << left << setw(30) << speciality << left << setw(4) << experience << evil;
	}
	void write()const
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специализация: " << speciality << " ,опыт: " << experience << " ,строгость: " << evil;
		fout.close();
	}


};

class Graduate :public Student
{
	string  discipline;
	string name_of_project;

public:
	const string& get_discipline()const
	{
		return discipline;
	}
	const string& get_name_of_project()const
	{
		return name_of_project;
	}
	void set_discipline(const string& discipline)
	{
		this->discipline = discipline;
	}
	void set_name_of_project(const string& name_of_project)
	{
		this->name_of_project = name_of_project;
	}

	//Constructors:
	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& discipline, const string& name_of_project)

		:Student(last_name, first_name, age, speciality, group, rating)
	{
		set_discipline(discipline);
		set_name_of_project(name_of_project);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//Methods:
	ostream& print(ostream& os)const
	{
		Student::print(os);
		//return os << /*Дисциплина:*/" " << discipline << " "/*,тема дипломного проекта:*/ << " " << name_of_project;
		return os << left << setw(10) << discipline << name_of_project;

	}
	void write()const
	{
		Student::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Дисциплина: " << discipline << " ,тема дипломного проекта: " << name_of_project << endl;
		fout.close();

	}

};

//#define INHERITANCE
#define POLIMORPHISM
//#define WRITE_TO_FILE

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

#ifdef POLIMORPHISM
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
		//group[i]->print();
		cout << *group[i] << endl;
	}
	cout << "----------------------------------------------\n";

	ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}


	/*	cout << sizeof(Human*) << endl;//размер массива в байтах
		cout << sizeof(group) << endl;//размер 1 элемента массива в байтах
		cout << sizeof(group) / sizeof(Human*) << endl;//так получаем, что выводить надо для 6 элементов массива*/
#endif // POLIMORPHISM

#ifdef WRITE_TO_FILE
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 98),//upcast
		new Student("Vercetti","Tomas",30,"Criminal","Vice",90), // upcast
		new Teacher("Ivanov", "Ivan", 35, "1C", 8, 7.5), // upcast
		new Student("Diaz","Ricardo",55,"Weapons istribution","Vice",80),
		new Graduate("Ivanova", "Larisa", 22, "AS", "AS-05", 90, "Automatical Systems", "Module of online store"),
		new Teacher("Eistein","Albert",143,"Astronomy",120,10)
	};

	ofstream fout("File.txt", std::ios_base::app); //Создаем и открываем поток
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->write();
	}
	cout << "----------------------------------------------\n";

	system("notepad File.txt");// в блокноте
	//system("more File.txt");// в консоли  
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
#endif // WRITE_TO_FILE

}