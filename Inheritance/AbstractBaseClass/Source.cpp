//AbstractBaseClass
#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;//pure vurtual function
	//������ ���� ����� � ������ ����� �����������

};

class GroundVehicle :public Vehicle//��
{

};

class WaterVehicle :public Vehicle//��
{

};

class AirVehicle :public Vehicle//��
{
	int height;
};
class Bike :public GroundVehicle//���������� �����, ��� ��� ���������� ����� ���� ����� move
{
public:
	void move()
	{
		cout << "�������� ���� �� 2 �������" << endl;
	}
};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� 4 �������" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move()
	{
		cout << "����� ������" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;//���������� ������� ��������� ����������� ������
	//GroundVehicle gv;���� ����� ����� ��� �����������, ��������� �� ���������� ����� move
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();
	Boat boat;
	boat.move();
}