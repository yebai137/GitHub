#pragma once
#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<string>
#include<vector>
using namespace std;

class Classroom 
{
public:
	Classroom();
	~Classroom();
	bool isClassroomValid(string);
	bool isDayValid(int, string);
	bool isTimeValid(int, int);
	string setSerialNumber(string);
	string setSerialNumber(int);
	vector<string> getSerialNumber(string);
	bool isClassroomEmpty(string, int, string, int, int);
	void printClassroom(string, int, string, int);
	void changeClassroom(string, int, string, int, string, string);
	void deleteClassroomStatus(string);
	void deleteClassroomStatus(string, int, string, int);
	void printAllEmptyClassroom(int, string, int, int);
	void printClassroomPerWeek(string, int);
	void printClassroomPerBuilding(string, int, string);
	void printAllClassroom(int, string);
	void printClassroomAllWeek(string, string);
private:
	vector<string>allcla;
};

#endif