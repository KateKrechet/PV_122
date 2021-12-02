#include<iostream>
#include<math.h>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;

namespace Geometry
{
	enum Color
	{
		console_gray = 0x88,//16-ричный код цвета
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		red = 0x000000FF,
		green = 0x0000FF00,
		dark_green = 0x0000A000,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF

	};
	//enum - набор именованных констант типа int

	class Shape
	{
	protected:
		Color color;
		//ширина линии
		unsigned int width;
		//Начальные координаты для риования фигуры
		unsigned int start_x;
		unsigned int start_y;
	public:
		unsigned int get_width()const
		{
			return width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		void set_width(unsigned int width)
		{
			if (width > 20) width = 20;
			this->width = width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 1000) start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_x > 700) start_x = 700;
			this->start_y = start_y;
		}
		Shape(Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :color(color)
		{
			set_width(width);
			set_start_x(start_x);
			set_start_y(start_y);
			cout << "ShConstructor:\t" << this << endl;
		}
		virtual~Shape()
		{
			cout << "ShDestructor:\t" << this << endl;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}

		void set_side(double side)
		{
			if (side <= 0) side = 1;
			this->side = side;
		}
		Square(double side, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_side(side);
		}
		~Square()
		{

		}
		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
	};

	class Rectangle :public Shape
	{
		double side1;
		double side2;
	public:
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}

		void set_side1(double side1)
		{
			if (side1 <= 0) side1 = 1;
			this->side1 = side1;
		}
		void set_side2(double side2)
		{
			if (side2 <= 0) side2 = 2;
			this->side2 = side2;
		}
		Rectangle(double side1, double side2, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_side1(side1);
			set_side2(side2);
		}
		~Rectangle()
		{

		}
		double get_area()const
		{
			return side1 * side2;
		}
		double get_perimeter()const
		{
			return (side1 + side2) * 2;
		}
		void draw()const
		{
			//1)Получаем окно консоли
			HWND hwnd = GetConsoleWindow();
			//HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");//чтобы посмотреть прозрачность
			//2)Получаем контекст устройства полученного окна
			HDC hdc = GetDC(hwnd);
			//3)Создаем карандаш
			HPEN hPen = CreatePen(PS_SOLID, 5, color);//PS_SOLID-сплошная линия,5 - толщина 5 пикселей
			//4)Прежде чем рисовать карандашом, нужно выбрать чем и на чем рисовать
			SelectObject(hdc, hPen);
			//5)Чтобы фигура была закрашена опеределенным цветом,нужно создать и применить кисть
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);


			::Rectangle(hdc, start_x, start_y, start_x + side2, start_y + side1);//положение в окне
			//Удаляем кисть
			DeleteObject(hBrush);
			// )Удаляем карандаш
			DeleteObject(hPen);
			// )Все контексты устройств надо удалть, 
			//чтобы освободить занимаемые ими ресурсы
			ReleaseDC(hwnd, hdc);
		}
	};

	class Circle :public Shape
	{
		double radius;
		CONST double PI = 3.141592653589793;
	public:
		double get_radius()const
		{
			return radius;
		}

		void set_radius(double radius)
		{
			if (radius <= 0) radius = 5;
			this->radius = radius;
		}

		Circle(double radius, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_radius(radius);
		}
		~Circle()
		{

		}
		double get_area()const
		{
			return PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * PI * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			SelectObject(hdc, hPen);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
	};
}

	/*class Triangle :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}

		void set_side(double side)
		{
			if (side <= 0) side = 1;
			this->side = side;
		}
		Triangle(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Triangle()
		{

		}
		double get_area()const
		{
			return pow(side, 2) / 2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cout << "*";
				}
				cout << endl;
			}

		}
	};

}*/

	void main()
	{//вывод изображения на полный экран
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD buffer = { 80,50 };
		SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
		system("pause");



		setlocale(LC_ALL, "Russian");
		/*Geometry::Square square(5, Geometry::Color::console_red);
		cout << "Площадь квадрата: " << square.get_area() << endl;
		cout << "Периметр квадрата: " << square.get_perimeter() << endl;
		square.draw();*/

		/*Geometry::Rectangle rect1(100, 400, Geometry::Color::yellow, 5, 200, 400);
		cout << "Площадь прямоугольника: " << rect1.get_area() << endl;
		cout << "Периметр прямоугольника: " << rect1.get_perimeter() << endl;
		rect1.draw();*/

		Geometry::Circle elip(100, Geometry::Color::red, 5, 200, 400);
		cout << "Площадь круга: " << elip.get_area() << endl;
		cout << "Периметр круга: " << elip.get_perimeter() << endl;
		elip.draw();

		/*Triangle triangle(5, Color::console_red);
		cout << "Площадь треугольника: " << triangle.get_area() << endl;
		cout << "Периметр треугольника: " << triangle.get_perimeter() << endl;
		triangle.draw();*/



	}