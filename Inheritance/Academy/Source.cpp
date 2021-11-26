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
		//return os <<left << setw(10)<<last_name << left << setw(10) << first_name<< left << setw(4)<<age;
		//return os<<last_name << " " << first_name << " " << age << " ";
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
	virtual ofstream& print(ofstream& os)const
	{
		//return os <<left << setw(10)<<last_name << left << setw(10) << first_name<< left << setw(4)<<age;
		//return os<<last_name << " " << first_name << " " << age << " ";
		os.width(15);
		os << std::left;
		os << typeid(*this).name() << "|";
		os.width(10);
		os << std::left;
		os << last_name << "|";
		os.width(10);
		os << std::left;
		os << first_name << "|";
		os.width(5);
		os << std::left;
		os << age << "|";
		return os;

	}
	virtual void write()const
	{
		ofstream fout("File.txt", std::ios_base::app);
		fout << last_name << " " << first_name << " " << age << " лет.\n";
		fout.close();
	}
	virtual istream& input(istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
	virtual ifstream& input(ifstream& is)
	{
		std::getline(is, last_name, '|');//чтение до верт черты
		std::getline(is, first_name, '|');
		string age_buffer;
		std::getline(is, age_buffer, '|');
		this->age = std::stoi(age_buffer);//преобразует строку в число
		return is;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);

}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}

istream& operator>>(istream& is, Human& obj)
{
	/*string last_name, first_name;
	int age;
	is >> last_name >> first_name >> age;
	obj.set_last_name(last_name);
	obj.set_first_name(first_name);
	obj.set_age(age);
	return is; реализация без виртуального метода*/
	return obj.input(is);

}

ifstream& operator>>(ifstream& is, Human& obj)
{
	return obj.input(is);
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
		return os << left << setw(25) << speciality << left << setw(10) << group << right << setw(4) << rating << "%";
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os << left << setw(25);
		os << speciality << "|";
		os << left << setw(10);
		os << group << "|";
		os << right << setw(5);
		os << rating << "%|";
		return os;
	}
	void write()const
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Специальность: " << speciality << " ,группа: " << group << " ,успеваемость: " << rating << endl;
		fout.close();
	}
	istream& input(istream& is)
	{
		Human::input(is);
		is >> speciality;
		is >> group;
		is >> rating;
		return is;
	}
	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is,speciality,'|');
		std::getline(is,group,'|');
		string rating_buffer;
		std::getline(is, rating_buffer,'|');
		this->rating = std::stod(rating_buffer);
		return is;
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
		return os << left << setw(35) << speciality << right << setw(4) << experience << "y" << " " << left << setw(4) << evil;
	}

	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		os << left << setw(35);
		os << speciality << " | ";
		os << right << setw(4);
		os << experience << "y" << "|";
		os << " " << left << setw(4) << evil;
		return os;
	}

	ifstream& input(ifstream& is)
	{
		Human::input(is);
		std::getline(is, speciality,'|');
		string xp_buffer;
		std::getline(is, xp_buffer,'|');
		experience = std::stod(xp_buffer);
		string evil_buffer;
		std::getline(is, evil_buffer);
		evil = std::stod(evil_buffer);
		return is;
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
		return os << left << " " << discipline << name_of_project;

	}
	ofstream& print(ofstream& os)const
	{
		Student::print(os);
		//return os << /*Дисциплина:*/" " << discipline << " "/*,тема дипломного проекта:*/ << " " << name_of_project;
		os << left << " " << discipline << "|" << name_of_project;
		return os;
	}

	ifstream& input(ifstream& is)
	{
		Student::input(is);
		std::getline(is, discipline, '|');
		std::getline(is, name_of_project);
		return is;
	}
	void write()const
	{
		Student::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "Дисциплина: " << discipline << " ,тема дипломного проекта: " << name_of_project << endl;
		fout.close();

	}

};

void SaveToFile(Human* group[], const int size, const string& filename);
void Print(Human* group[], const int size);
Human** LoadFromFile(const std::string& filename);
Human* HumanFactory(const std::string& human_type);

//#define INHERITANCE
//#define POLIMORPHISM
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
	const Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 5),//upcast
		new Student("Vercetti","Tomas",30,"Criminal","Vice",100), // upcast
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

	/*ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");*/

	std::string filename = "group.txt";
	SaveToFile(group, sizeof(group) / sizeof(group[0]), filename);
	system((string("notepad ") + filename).c_str());
	//(string("notepad ") - преобразует строковую константу в объект класса std::string
	//(string("notepad ") + filename - конкатенация
	//(std::string).c_str() - метод возвращает содержимое объекта std::string
	//в виде обычной NULL Terminated line (C-string), то есть в виде массива элементов char

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

	/*Human human("last_name", "first_name",  0);
	cout << "Кто к нам пришел: ";
	cin >> human;
	cout << human << endl;*/

	/*Student stud("", "", 0, "", "", 0);
	cout << "Кто к нам пришел: ";
	cin >> stud;
	cout << stud << endl;*/
	Human**group=LoadFromFile("group.txt");
	Print(group, 6);
}
void SaveToFile(Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();

}
void Print(Human* group[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}
	
}

Human** LoadFromFile(const std::string& filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		//1)Вычисляем размер файла
		std::string buffer;//в этот буфер будем читать строки из файла
		int n = 0;//количество строк в файле
		while (!fin.eof())
		{
			std::getline(fin, buffer);//читать будем из файла в буфер
			cout << fin.tellg() << endl;
			n++;
		}
		//2)выделяем память под масси
		Human** group = new Human * [n] {};
		//3)возвращаем курсор в начало файла для того, чтобы заново его прочитать
		fin.clear();//очистка потока
		fin.seekg(ios::beg, 0);
		cout << fin.tellg() << endl;
		//4)заново читаем файл и загружаем его содержимое в массив объектов
		string human_type;
		for (int i = 0; i<n; i++)
		{
			std::getline(fin, human_type,'|');
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
			cout << *group[i];
			//cout << buffer << endl;
		}

		fin.close();
		return group;
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr;//если файл прочитать не удалось, возвращаем указатель на 0
}

Human* HumanFactory(const std::string& human_type)
{
	if (human_type.find("class Student")!=string::npos) return new Student("last_name", "first_name", 0, "spec", "gr", 0);
	if (human_type.find("class Graduate") != string::npos) return new Graduate("last_name", "first_name", 0, "spec", "gr", 0, "subj", "diploma");
	if (human_type.find("class Teacher") != string::npos) return new Teacher("last_name", "first_name", 0, "spec", 0, 0);
	return nullptr;
}
