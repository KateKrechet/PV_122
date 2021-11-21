#pragma once
#include<iostream>
#include "Student.h"
#include<string>
using namespace std;


class Graduate :public Student
{
	string  discipline;
	string name_of_project;

public:
	const string& get_discipline()const;
	const string& get_name_of_project()const;
	void set_discipline(const string& discipline);
	void set_name_of_project(const string& name_of_project);
	//Constructors:
	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& discipline, const string& name_of_project);
	~Graduate();
	//Methods:
	void print()const;
}; 