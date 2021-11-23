#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
//#define DEBUG

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
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG

	}
	virtual~Human()
	{
#ifdef DEBUG
		cout << "HDestructor\t" << this << endl;
#endif // DEBUG

	}
	//Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
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
	return os << obj.get_last_name() << " " <<
		obj.get_first_name() << " " <<
		obj.get_age() << " лет."<<endl;
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
#ifdef DEBUG
		cout << "SConstructor:\t" << this << endl;
#endif // DEBUG

	}

	~Student()
	{
#ifdef DEBUG
		cout << "SDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << " ,группа: " << group << " ,успеваемость: " << rating << endl;
	}
	void write()const
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специальность: " << speciality << " ,группа: " << group << " ,успеваемость: " << rating << endl;
		fout.close();
	}
};
ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human)obj;
	return os <<"Специальность: " << obj.get_speciality() 
		<< " ,группа: " << obj.get_group() 
		<< " ,успеваемость: " << obj.get_rating() << endl;
}

class Teacher : public Human
{
	string speciality;
	unsigned int experience;
	double evil;
public:
	const string& get_speciality()const
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
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//Methods:
	void print()const
	{
		Human::print();
		cout << "Специализация: " << speciality << " ,опыт: " << experience << " ,строгость: " << evil << endl;
	}
	void write()const
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специализация: " << speciality << " ,опыт: " << experience << " ,строгость: " << evil << endl;
		fout.close();
	}


};

ostream& operator<<(ostream& os, const Teacher& obj)
{
		return os <<(Human)obj<< "Специализация: " << obj.get_speciality()
		<< " ,опыт: " << obj.get_experience ()
		<< " ,строгость: " << obj.get_evil() << endl;
}

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
#ifdef DEBUG
		cout << "GConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "GDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//Methods:
	void print()const
	{
		Student::print();
		cout << "Дисциплина: " << discipline << " ,тема дипломного проекта: " << name_of_project << endl;

	}
	void write()const
	{
		Student::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Дисциплина: " << discipline << " ,тема дипломного проекта: " << name_of_project << endl;
		fout.close();

	}

};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os <<(Student)obj<< "Дисциплина: " << obj.get_discipline()
		<< " ,тема дипломного проекта: " << obj.get_name_of_project() << endl;
}

//#define INHERITANCE
//#define POLIMORPHISM
#define ACADEMY_STREAMS_HARDCOR

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
		group[i]->print();
	}
	cout << "----------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}


	/*	cout << sizeof(Human*) << endl;//размер массива в байтах
		cout << sizeof(group) << endl;//размер 1 элемента массива в байтах
		cout << sizeof(group) / sizeof(Human*) << endl;//так получаем, что выводить надо для 6 элементов массива*/
#endif // POLIMORPHISM

#ifdef ACADEMY_STREAMS_HARDCOR

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

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "----------------------------------------------\n";
		//cout << *group[i] << endl;
		//cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))
			cout<<*dynamic_cast<Student*>(group[i]) << endl;//вернет указатель на студента
		if (typeid(*group[i]) == typeid(Graduate))
			cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))
			cout << *dynamic_cast<Teacher*>(group[i]) << endl;
	}
	cout << "----------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
#endif // WRITE_TO_FILE

}