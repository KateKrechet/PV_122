#include "String.h"
#include<iostream>

//объ€вление класса

//--------------------------------------------------------------------------//

//Class definition - определение класса

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