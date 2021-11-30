#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
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

	virtual ostream& print(ostream& os)const
	{
		os.width(10);
		os << std::left;
		os << last_name;
		os.width(10);
		os << std::left;
		os << first_name;
		os.width(5);
		os << std::left;
		os << age;
		return os;

	}

};

ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);

}

class Worker :public Human
{
	string speciality;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	Worker(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality)
		:Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		cout << "WConstructor\t" << this << endl;
	}
	~Worker()
	{
		cout << "WDestructor:\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Human::print(os);
		return os << left << setw(20) << speciality;
	}

};

class SalaryWorker :public Worker
{
	double salary;
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}

	SalaryWorker(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double salary)
		:Worker(last_name, first_name, age, speciality)
	{
		set_salary(salary);
		cout << "SWConstructor:\t" << this << endl;
	}
	~SalaryWorker()
	{
		cout << "SWDestructor:\t" <<this<< endl;
	}
	ostream& print(ostream& os)const
	{
		Worker::print(os);
		return os << right << setw(6) << salary;
	}
};

class PieceSalaryWorker :public Worker
{
	double bet;
	double time;
public:
	double get_bet()const
	{
		return bet;
	}
	double get_time()const
	{
		return time;
	}
	void set_bet(double bet)
	{
		this->bet = bet;
	}
	void set_time(double time)
	{
		this->time = time;
	}

	PieceSalaryWorker(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double bet,double time)
		:Worker(last_name, first_name, age, speciality)
	{
		set_bet(bet);
		set_time(time);
		cout << "PSWConstructor:\t" << this << endl;
	}
	~PieceSalaryWorker()
	{
		cout << "PSWDestructor:\t" << this << endl;
	}
	ostream& print(ostream& os)const
	{
		Worker::print(os);
		return os << right << setw(6) << bet*time;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	const Human* group[] =

	{
		new SalaryWorker("Pinkman", "Jessie", 35, "Manager", 80000),
		new SalaryWorker("Tomilina","Svetlana",30,"Paymaster",40000),
		new SalaryWorker("Ivanova", "Larisa", 30, "Paymaster", 40000),
		new PieceSalaryWorker("Sidorov","Kirill",22,"Waiter",300,200),
		new PieceSalaryWorker("Guravleva","Svetlana",20,"Waiter",300,150),
		new PieceSalaryWorker("Komarov","Alexey",21,"Waiter",300,150)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "--------------------------------------------------------------------\n";
		cout << *group[i] << endl;
	}
	cout << "--------------------------------------------------------------------\n";
	
	ofstream fout("restaurant.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad restaurant.txt");
	
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}

}
