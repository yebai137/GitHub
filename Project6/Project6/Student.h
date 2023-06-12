#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>
#include"Person.h"
#include"StuAccount.h"
#include"Classroom.h"
using namespace std;

class Student :public Person 
{
public:
	Student(string);
	~Student();
	void setWarn(int);
	int getWarn();
	bool printWarn();
	void changePassword(string);
	bool addOrder(string, int, string, int, int, string);
	bool printOrder();
	bool removeOrder(int);
	bool removeAllRejectedOrder();
	bool changeOrder(Classroom*, int, char);
	void deleteAccount(StuAccount*);
	void printAllEmptyCl(Classroom*, int, string, int, int);
	void printClPerWeek(Classroom*, string, int);
	void printClPerBuilding(Classroom*, string, int, string);
	void printAllCl(Classroom*, int, string);
	void printClAllWeek(Classroom*, string, string);
protected:
	vector<string>allord;
	vector<string>allwar;
	int warn;
};

#endif