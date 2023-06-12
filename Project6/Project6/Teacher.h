#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include<string>
#include<vector>
#include"Person.h"
#include"TchAccount.h"
#include"Classroom.h"
using namespace std;

class Teacher :public Person 
{
public:
	Teacher(string);
	~Teacher();
	bool isCourseExist(string);
	bool isCourseExist(int);
	bool addCourse(string);
	bool printCourse();
	bool removeCourse(Classroom*, int);
	bool setCourseTime(Classroom*, int, string, int, int, string, int, int);
	void removeCourseTime(Classroom*, int);
	bool changeCourseTime(Classroom*, int, string, int, int, string, int, int);
	bool printCourseTime();
	void printAllEmptyCl(Classroom*, int, string, int, int);
	void printClPerWeek(Classroom*, string, int);
	void printClPerBuilding(Classroom*, string, int, string);
	void printAllCl(Classroom*, int, string);
	void printClAllWeek(Classroom*, string, string);
	void changePassword(string);
	void deleteAccount(TchAccount*, Classroom*);
private:
	vector<string>allcou;
	vector<string>allct;
};

#endif