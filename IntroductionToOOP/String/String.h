#pragma once
#include<iostream> 
#include<string>
using namespace std;


//ќбъ€вление класса - Class declaration
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	int size;//размер строки в байтах
	char* str;//адркс строки в динамической пам€ти

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//Operators

	String& operator=(const String& other);

	String& operator=(String&& other);

	String operator+=(const String& right);

	const char& operator[](int i)const;
	char& operator[](int i);

	void print()const;


};
//Class declaration END ( онец объ€влени€ класса)