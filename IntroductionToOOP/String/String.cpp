#include "String.h"
//Class definition - определение класса

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//Constructors
String::String(int size) :size(size), str(new char[size]/*{}*/)
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)//Делегируем выделение памяти конструктору по умолчанию
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{   //Deep copy
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	cout << "MoveConstructor:\t" << this << endl;
	other.str = nullptr;
	other.size = 0;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//Operators

String& String::operator=(const String& other)
{
	if (this == &other) return *this;//проверка на самоприсваивание
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size;
	return *this;

}

String String::operator+=(const String& right)
{
	return  *this = *this + right;
}

const char& String::operator[](int i)const
{
	return str[i];

}
char& String::operator[](int i)
{
	return str[i];

}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}


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
	for (int i = 0; i < left.get_size(); i++)
		buffer[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i];

	return buffer;
}


//Class definition END - конец определения класса
