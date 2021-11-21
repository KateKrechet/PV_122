#pragma once
#include<iostream>
#include "Human.h"
#include<string>
using namespace std;

class Teacher : public Human
{
	string speciality;
	unsigned int experience;
	double evil;
public:
	const string& get_peciality()const;
	unsigned int get_experience()const;
	double get_evil()const;
	void set_speciality(const string& speciality);
	void set_experience(unsigned int experience);
	void set_evil(double evil);
	//Constructors:
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience, double evil);
	~Teacher();
	//Methods:
	void print()const;
};
