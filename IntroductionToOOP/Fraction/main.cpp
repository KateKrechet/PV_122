//Fraction - описываем простую дробь
#include<iostream>
using namespace std;

int nod(int a, int b);
int nok(int a, int b);


class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		//Single-argument constructor - Конструктор с одним параметром.
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//				Methods:
	Fraction& to_proper()
	{
		//Переводит дробь в правильную - выделяет целую часть:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//Переводит дробь в НЕправильную - интегрирует целую часть в числитель:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& invert()
	{
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}
	void reduce()
	{
		//Сокращает дробь:
		int x = nod(numerator, denominator);
		numerator /= x;
		denominator /= x;

	}
	void print()
	{
		if (integer)cout << integer;	//Если есть целая часть, выводим ее на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

	friend Fraction operator*(Fraction, Fraction);
	Fraction& operator*=(const Fraction right)
	{
		/*this->to_improper();
		right.to_improper();

		numerator = numerator * right.get_numerator();
		denominator = denominator * right.get_denominator();
		return *this;*/
		*this = *this * right;
		return *this;
	}
	friend Fraction operator/(Fraction, Fraction);
	Fraction& operator/=(const Fraction right)
	{
		*this = *this / right;
		return *this;
	}
	friend Fraction operator+(Fraction, Fraction);
	Fraction& operator+=(const Fraction right)
	{
		*this = *this + right;
		return *this;
	}
	friend Fraction operator-(Fraction, Fraction);
	Fraction& operator-=(const Fraction right)
	{
		*this = *this - right;
		return *this;
	}


};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;*/
	//Явно вызываем конструктор прямо в return
	//Этот конструктор создает временный безымянный объект, кот return возвращает сразу на место вызова
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();


}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.invert();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int mult_denominator = nok(left.get_denominator(), right.get_denominator());
	return Fraction
	(
		left.get_numerator() * (mult_denominator / left.get_denominator()) + right.get_numerator() * (mult_denominator / right.get_denominator()),
		mult_denominator
	).to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int mult_denominator = nok(left.get_denominator(), right.get_denominator());
	return Fraction
	(
		left.get_numerator() * (mult_denominator / left.get_denominator()) - right.get_numerator() * (mult_denominator / right.get_denominator()),
		mult_denominator
	).to_proper();
}


ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();	//Если есть целая часть, выводим ее на экран
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

//#define CONSTRUCTORS_CHECK
//#define OSTREAM_CHECR
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();
	Fraction B = 5;	//Single-argument constructor (Конструктор с одним параметром).
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OSTREAM_CHECR
	Fraction A(14, 4);
	A.to_proper();
	//A.print();
	cout << A << endl;
	A.to_improper();
	//A.print();
	cout << A << endl;
#endif // OSTREAM_CHECR
	int a = 98;
	int b = 210;
	int c = a * b;

	Fraction A(1, 2, 3);
	Fraction B(2, 4, 5);
	cout << A << endl;
	cout << B << endl;
	Fraction C = A / B;
	cout << C << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << nok(a, b) << endl;
	Fraction D = A - B;
	cout << D << endl;
	
	A += B;
	cout << A << endl;
	A -= B;
	cout << A << endl;
}
int nod(int a, int b)
{
	while (b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int nok(int a, int b)
{
	return a * b / nod(a, b);
}
