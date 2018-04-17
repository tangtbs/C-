#pragma once
#include<iostream>
#include<conio.h>
#include"Slist.h"
using namespace std;
class Student
{
public:
	Student()
	{

	}
	~Student()
	{

	}
	Slist L1,L2;
	Slist*pl;
	int Menu();
	void Browse();
	int BrowseMenu();
	void Add();
	void Delete();
	void Modify();
	void Find();
	int FindMenu();
	int AddMenu();
	int DeleteMenu();
	void Deletesome();
	void DeleteAll();
	int Main();
	Slist*Select();
};