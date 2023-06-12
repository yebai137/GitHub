#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include<string>
#include<vector>
#include"Classroom.h"
#include"StuAccount.h"
#include"TchAccount.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;

class Admin
{
public:
	Admin();
	~Admin();
	bool log(string);
	void setAdminPassword(string);
	string getAdminPassword();
	void changeAdminPassword(string);
	string setSerialNumber99(string);
	string setNumber99(int);
	string setSerialNumber999(string);
	vector<string> getSerialNumber(string);
	void printAllEmptyCl(Classroom*, int, string, int, int);
	void printClPerWeek(Classroom*, string, int);
	void printClPerBuilding(Classroom*, string, int, string);
	void printAllCl(Classroom*, int, string);
	void printClAllWeek(Classroom*, string, string);
	bool checkOrder(string);
	bool changeOrder(Classroom*, string, int, char);
	bool checkCourse(string);
	bool checkCourseTime(string);
	void setWarning(string, string, int, string, int, int, string);
private:
	string pw;
};

#endif