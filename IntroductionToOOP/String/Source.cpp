#include<iostream> 
#include<string>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;//размер строки в байтах
	char* str;//адркс строки в динамической пам€ти

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//Constructors
	explicit String(int size = 80):size(size),str(new char[size]/*{}*/)
	{
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str):String(strlen(str)+1)//ƒелегируем выделение пам€ти конструктору по умолчанию
	{
		//for (int i = 0; i < size; i++)this->str[i] = str[i];
		strcpy(this->str, str);
		//strcpy - string copy
		//strcpy(dat,src)
		//dst(destination)-строка, в кот копируетс€ содержимое
		//src(source) - срока источник, строка, из которой копируетс€ содержимое

		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{   //Deep copy
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other):size(other.size),str(other.str)
	{
		cout << "MoveConstructor:\t" << this << endl;
		other.str = nullptr;
		other.size = 0;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//Operators

	String& operator=(const String& other)
	{
		if (this == &other) return *this;//проверка на самоприсваивание
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size;
		return *this;

	}

	String operator+=(const String& right)
	{
		return  *this = *this + right;
	}

	const char& operator[](int i)const
	{
		return str[i];

	}
	char& operator[](int i)
	{
		return str[i];

	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	

};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	/*for (int i = 0; i < left.get_size(); i++)
		buffer[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i];*/

	strcpy(buffer.get_str(), left.get_str());
	strcat(buffer.get_str(), right.get_str());

	//strcat - конкатенаци€ строк
	//strcat(dst/src);
	//dst - строка получатель
	//src - строка источник
	//в dst будет объединенна€ строка


	return buffer;
}


	


//#define CONSTRUCTORS_CHECK
#define delimiter "\n---------------------------------------\n"
//#define OPERATORS_PLUS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str;            //Default constructor
	str.print();

	String str1 = "Hello";//Single-argument constructor
	//str1.print();
	cout << str1 << endl;

	String str2 = str1; //Copy Constructor
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef OPERATORS_PLUS_CHECK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;
#endif // OPERATORS_PLUS_CHECK
	String str1(25);//Default constructor;
	str1.print();
	String str2="Hello";//Single-argument constructor
	//cout << str2 << endl;
	str2.print();
	String str3("World");//Single-argument constructor
	cout << str3 << endl;
	String str4();//ќбь€вление функции str4, котора€ ничего не принимает и возвращает объект класса String
	              //здесь не создаетс€ объект, а обь€вл€етс€ функци€ str4
	String str5{};//явный вызов конструктора по умолчанию
	cout << str5 << endl;
	String str6{ "ѕараметры в конструктор можно передавать в фигурных скобках" };
	cout << str6 << endl;
	String str7 = str6;
	cout << str7 << endl;
	cout << str2 + " " + str3 << endl;

}