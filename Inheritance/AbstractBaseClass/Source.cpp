//AbstractBaseClass
#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;//pure vurtual function
	//именно этот метод и делает класс абстрактным

};

class GroundVehicle :public Vehicle//АК
{

};

class WaterVehicle :public Vehicle//АК
{

};

class AirVehicle :public Vehicle//АК
{
	int height;
};
class Bike :public GroundVehicle//конкретный класс, так как определяет чисто вирт метод move
{
public:
	void move()
	{
		cout << "Мотоцикл едет на 2 колесах" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едет на 4 колесах" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()
	{
		cout << "Лодка плывет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;//невозможно создать экземпляр абстрактого класса
	//GroundVehicle gv;этот класс также явл абстрактным, поскольку не оперделяет метод move
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();
	Boat boat;
	boat.move();
}