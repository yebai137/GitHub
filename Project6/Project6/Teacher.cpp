#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<istream>
#include"GlobalFile.h"
#include"Teacher.h"
#include"TchAccount.h"
#include"Classroom.h"
using namespace std;

Teacher::Teacher(string id)
{
	vector<string>().swap(allcou);
	vector<string>().swap(allct);
	string s;
	ifstream file;
	file.open("T" + id + ".txt", ios::in);
	if (file.is_open()) {
		while (getline(file, s)) 
		{
			if (s.at(0) == 'P') 
			{
				setName(getSerialNumber(s)[0]);
				setID(getSerialNumber(s)[1]);
				setPassword(getSerialNumber(s)[2]);
			}
			else if (s.at(0) == 'C')
			{
				allcou.push_back(s);
			}
			else if (s.at(0) == 'T') 
			{
				allct.push_back(s);
			}
		}
	}
	else 
	{
		cout << "The file\"T" << id << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

Teacher::~Teacher() 
{
	ofstream file;
	file.open("S" + getID() + ".txt", ios::out);
	if (file.is_open()) 
	{
		file << "P0" << setSerialNumber99(getName()) << setSerialNumber99(getID()) << setSerialNumber99(getPassword()) << getName() 
			<< getID() << getPassword() << "\n";
		for (size_t i = 0; i < allcou.size(); i++) 
		{
			file << allcou[i] << "\n";
		}
		for (size_t i = 0; i < allct.size(); i++) 
		{
			file << allct[i] << "\n";
		}
	}
	else 
	{
		cout << "The file\"T" << getID() << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	vector<string>().swap(allct);
	vector<string>().swap(allcou);
	return;
}

bool Teacher::isCourseExist(string s) 
{
	bool con = false;
	for (int i = 0; i < allcou.size(); i++) 
	{
		if (allcou[i].find(s)!=string::npos) 
		{
			con = true;
			break;
		}
		else {
			con = false;
		}
	}
	return con;
}

bool Teacher::isCourseExist(int s) 
{
	bool con = false;
	if (s <= 0 && s > allcou.size()) 
	{
		con = false;
	}
	else 
	{
		con = true;
	}
	return con;
}

bool Teacher::addCourse(string s)
{
	bool con = false;
	if(isCourseExist(s)) 
	{
		string ss = "C" + to_string(allcou.size() + 1) + setSerialNumber99(s) + s;
		allcou.push_back(ss);
		con = true;
	}
	else {
		con = false;
	}
	return con;
}

bool Teacher::printCourse() 
{
	bool con = false;
	if (allcou.empty()) 
	{
		con = false;
	}
	else {
		for (int i = 0; i < allcou.size(); i++) 
		{
			cout << "No." << i + 1 << ": " << getSerialNumber(allcou[i])[0] << "\n";
		}
		cout << "\n";
		con = true;
	}
	return con;
}

bool Teacher::removeCourse(Classroom* c, int a) 
{
	bool con = false;
	if (!allcou.empty()) 
	{
		if (a > 0 && a <= allcou.size()) 
		{
			auto iter = allcou.erase(begin(allcou) + a - 1);
			for (int i = 0; i < allct.size(); i++) 
			{
				int b = (static_cast<int>(allct[i].at(1)) - 48) * 10 + static_cast<int>(allct[i].at(2)) - 48;
				if (b == a) 
				{
					c->deleteClassroomStatus(allct[i]);
					auto iter = allct.erase(begin(allct) + i);
				}
			}
			con = true;
		}
		else
		{
		    con = false;
		}
	}
	else 
	{
		con = false;
	}
	return con;
}

bool Teacher::setCourseTime(Classroom* c, int a, string cl, int stwe, int enwe, string da, int stti, int enti)
{
	bool con = false;
	int day = 0;
	if (a <= 0 || a > allcou.size() || stwe > enwe)
	{
		return false;
	}
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	for (int i = stwe; i <= enwe; i++)
	{
		if (c->isClassroomEmpty(cl, i, da, stti, enti))
		{
			con = true;
		}
		else 
		{
			con = false;
			break;
		}
	}
	if (con) 
	{
		for (int i = stwe; i <= enwe; i++) 
		{
			for (int j = stti; j <= enti; j++) 
			{
				c->changeClassroom(cl, i, da, j, "T" + getID(), setNumber99(a));
			}
		}
	}
	string ss = "T" + setNumber99(a) + cl + setNumber99(stwe) + setNumber99(enwe) + to_string(day) + setNumber99(stti) + setNumber99(enti);
	allct.push_back(ss);
	return con;
}

void Teacher::removeCourseTime(Classroom* c, int a) 
{
	if (a <= 0 || a > allcou.size())
	{
		cout << "The serial number you've entered is invalid!\n";
		return;
	}
	for (int i = 0; i < allct.size(); i++)
	{
		if (allct[i].substr(1, 2) == setNumber99(a))
		{
			c->deleteClassroomStatus(allct[i].substr(3, 10));
			auto iter = allct.erase(begin(allct) + i);
		}
	}
	cout << "You've remove the course successfully!\n";
	return;
}

bool Teacher::changeCourseTime(Classroom* c, int a, string cl, int stwe, int enwe, string da, int stti, int enti)
{
	bool con = false;
	int day = 0;
	for (int i = 0; i < 7; i++)
	{
		if (weekday[i] == da)
		{
			day = i + 1;
			break;
		}
	}
	for (int i = stwe; i <= enwe; i++)
	{
		if (c->isClassroomEmpty(cl, i, da, stti, enti)) 
		{
			con = true;
		}
		else
		{
			con = false;
			break;
		}
	}
	if (con) {
		removeCourseTime(c, a);
		for (int i = stwe; i <= enwe; i++) 
		{
			for (int j = stti; j <= enti; j++) 
			{
				c->changeClassroom(cl, i, da, j, "T" + getID(), setNumber99(a));
				string ss = "T" + setNumber99(a) + cl + setNumber99(i) + to_string(day) + setNumber99(j);
				allct.push_back(ss);
			}
		}
	}
	return con;
}

bool Teacher::printCourseTime() 
{
	bool con = false;
	if (allcou.empty() || allct.empty())
	{
		con = false;
	}
	else 
	{
		for (int i = 0; i < allcou.size(); i++) 
		{
			cout << "No." << i + 1 << ": " << getSerialNumber(allcou[i])[0] << "\n" << "Classroom: ";
			string s = allcou[i].substr(1, 2);
			for (int j = 0; j < allct.size(); j++) 
			{
				if (allct[j].find(s) != string::npos)
				{
					cout << getSerialNumber(allct[i])[1] << "    Time: " << getSerialNumber(allct[i])[2] << " " << getSerialNumber(allct[i])[3];
					cout << " " << getSerialNumber(allct[i])[4] << "\n";
				}
			}
		}
		cout << "\n";
		con = true;
	}
	return con;
}

void Teacher::printAllEmptyCl(Classroom* e, int a, string b, int c, int d) 
{
	e->printAllEmptyClassroom(a, b, c, d);
	return;
}

void Teacher::printClPerWeek(Classroom* e, string a, int b)
{
	e->printClassroomPerWeek(a, b);
	return;
}

void Teacher::printClPerBuilding(Classroom* e, string a, int b, string c) 
{
	e->printClassroomPerBuilding(a, b, c);
	return;
}

void Teacher::printAllCl(Classroom* e, int a, string b) 
{
	e->printAllClassroom(a, b);
	return;
}

void Teacher::printClAllWeek(Classroom* e, string a, string b)
{
	e->printClassroomAllWeek(a, b);
	return;
}

void Teacher::changePassword(string npw) 
{
	setPassword(npw);
	return;
}

void Teacher::deleteAccount(TchAccount* t,Classroom* c) 
{
	t->deleteAccount(getID());
	for (int i = 0; i < allcou.size(); i++) 
	{
		removeCourse(c, i + 1);
	}
	vector<string>().swap(allcou);
	vector<string>().swap(allct);
	setName("");
	setID("");
	setPassword("");
	return;
}