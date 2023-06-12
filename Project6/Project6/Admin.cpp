#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<istream>
#include"Admin.h"
#include"Classroom.h"
#include"StuAccount.h"
#include"TchAccount.h"
#include"Student.h"
#include"Teacher.h"
#include"GlobalFile.h"
using namespace std;

Admin::Admin() 
{
	ifstream file;
	string s;
	file.open("admin.txt", ios::in);
	if (file.is_open()) 
	{
		getline(file, s);
		setAdminPassword(s);
	}
	else 
	{
		cout << "The file\"admin.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

Admin::~Admin() 
{
	ofstream file;
	file.open("admin.txt", ios::out);
	if (file.is_open()) 
	{
		file << getAdminPassword();
	}
	else 
	{
		cout << "The file\"admin.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

void Admin::setAdminPassword(string a) 
{
	pw = a;
}

string Admin::getAdminPassword() 
{
	return pw;
}

bool Admin::log(string pw) 
{
	bool con = false;
	if (pw == getAdminPassword()) 
	{
		con = true;//µÇÂ¼³É¹¦
	}
	else
	{
	con = false;//µÇÂ¼Ê§°Ü£ºÃÜÂë²»ÕýÈ·
	}
	return con;
}

void Admin::changeAdminPassword(string n) 
{
	setAdminPassword(n);
	return;
}

string Admin::setSerialNumber99(string a) 
{
	int b = a.size();
	string c;
	if (b >= 1 && b <= 9) 
	{
		c = "0" + to_string(b);
	}
	else
	{
	c = to_string(b);
	}
	return c;
}

string Admin::setNumber99(int b)
{
	string c;
	if (b >= 1 && b <= 9) 
	{
		c = "0" + to_string(b);
	}
	else
	{
	c = to_string(b);
	}
	return c;
}

string Admin::setSerialNumber999(string a) 
{
	int b = a.size();
	string c;
	if (b >= 1 && b <= 9) 
	{
		c = "00" + to_string(b);
	}
	else if (b >= 10 && b <= 99) 
	{
		c = "0" + to_string(b);
	}
	else
	{
	c = to_string(b);
	}
	return c;
}

vector<string> Admin::getSerialNumber(string s) 
{
	vector<string>o;
	if (s.at(0) == 'P') 
	{
		int a = (static_cast<int>(s.at(2)) - 48) * 10 + (static_cast<int>(s.at(3)) - 48);
		int b = (static_cast<int>(s.at(4)) - 48) * 10 + (static_cast<int>(s.at(5)) - 48);
		int c = (static_cast<int>(s.at(6)) - 48) * 10 + (static_cast<int>(s.at(7)) - 48);
		int na0 = a + 8;
		int id0 = na0 + b;
		int pw0 = id0 + c;
		o.push_back(s.substr(8, a));
		o.push_back(s.substr(na0, b));
		o.push_back(s.substr(id0, c));
	}
	else if (s.at(0) == 'O') 
	{
		o.push_back(s.substr(1, 5));
		o.push_back(s.substr(6, 2));;
		int a = static_cast<int>(s.at(8)) - 48;
		int b = (static_cast<int>(s.at(9)) - 48) * 10 + (static_cast<int>(s.at(10)) - 48);
		int c = (static_cast<int>(s.at(11)) - 48) * 10 + (static_cast<int>(s.at(12)) - 48);
		o.push_back(weekday[a]);
		o.push_back(start_time[b]);
		o.push_back(end_time[c]);
		int d = (static_cast<int>(s.at(13)) - 48) * 100 + (static_cast<int>(s.at(14)) - 48) * 10 + (static_cast<int>(s.at(15)) - 48);
		o.push_back(s.substr(16, d));
		int e = static_cast<int>(s.back()) - 48;
		o.push_back(order_state[e]);
	}
	else if (s.at(0) == 'C') 
	{
		int a = (static_cast<int>(s.at(3)) - 48) * 10 + (static_cast<int>(s.at(4)) - 48);
		o.push_back(s.substr(5, a));
	}
	else if (s.at(0) == 'W') 
	{
		o.push_back(s.substr(1, 5));
		int a = (static_cast<int>(s.at(6)) - 48) * 10 + (static_cast<int>(s.at(7)) - 48);
		o.push_back("Week " + to_string(a));
		o.push_back(weekday[static_cast<int>(s.at(8)) - 48]);
		int b = (static_cast<int>(s.at(9)) - 48) * 10 + (static_cast<int>(s.at(10)) - 48);
		int c = (static_cast<int>(s.at(11)) - 48) * 10 + (static_cast<int>(s.at(12)) - 48);
		o.push_back(start_time[b] + "~" + end_time[c]);
		int d = (static_cast<int>(s.at(13)) - 48) * 100 + (static_cast<int>(s.at(14)) - 48) * 10 + static_cast<int>(s.at(15)) - 48;
		o.push_back(s.substr(16, d));
	}
	else if (s.at(0) == 'T') 
	{
		int a = (static_cast<int>(s.at(1)) - 48) * 10 + (static_cast<int>(s.at(2)) - 48);
		o.push_back(to_string(a));
		o.push_back(s.substr(3, 5));
		int b = (static_cast<int>(s.at(8)) - 48) * 10 + (static_cast<int>(s.at(9)) - 48);
		int c = (static_cast<int>(s.at(10)) - 48) * 10 + (static_cast<int>(s.at(11)) - 48);
		o.push_back("Week " + to_string(b) + "~" + to_string(c));
		o.push_back(weekday[static_cast<size_t>(s.at(12) - 48)]);
		int d = (static_cast<int>(s.at(13)) - 48) * 10 + (static_cast<int>(s.at(14)) - 48);
		int e = (static_cast<int>(s.at(15)) - 48) * 10 + (static_cast<int>(s.at(16)) - 48);
		o.push_back(start_time[d] + "~" + end_time[e]);
	}
	return o;
}

void Admin::printAllEmptyCl(Classroom* e, int a, string b, int c, int d) 
{
	e->printAllEmptyClassroom(a, b, c, d);
	return;
}

void Admin::printClPerWeek(Classroom* e, string a, int b) 
{
	e->printClassroomPerWeek(a, b);
	return;
}

void Admin::printClPerBuilding(Classroom* e, string a, int b, string c) 
{
	e->printClassroomPerBuilding(a, b, c);
	return;
}

void Admin::printAllCl(Classroom* e, int a, string b) 
{
	e->printAllClassroom(a, b);
	return;
}

void Admin::printClAllWeek(Classroom* e, string a, string b) 
{
	e->printClassroomAllWeek(a, b);
	return;
}

bool Admin::checkOrder(string id) 
{
	bool con = false;
	ifstream file;
	string s;
	file.open("student.txt", ios::in);
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			if (s.find(id) != string::npos) 
			{
				con = true;
				Student* s0 = new Student(id);
				if (!s0->printOrder()) 
				{
					cout << "This student doesn't have any order!\n";
				}
				delete s0;
				s0 = nullptr;
				break;
			}
			else 
			{
				con = false;
			}
		}
	}
	else 
	{
		cout << "The file\"student.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	return con;
}

bool Admin::changeOrder(Classroom* c, string id, int a, char b) 
{
	bool con = false;
	ifstream file;
	string s;
	file.open("student.txt", ios::in);
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			if (s.find(id) != string::npos) 
			{
				con = true;
				Student* s0 = new Student(id);
				con = s0->changeOrder(c, a, b);
				delete s0;
				s0 = nullptr;
				break;
			}
			else 
			{
				con = false;
			}
		}
	}
	else 
	{
		cout << "The file\"student.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	return con;
}

bool Admin::checkCourse(string id) 
{
	bool con = false;
	ifstream file;
	string s;
	file.open("teacher.txt", ios::in);
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			if (s.find(id) != string::npos) 
			{
				con = true;
				Teacher* t0 = new Teacher(id);
				if (!t0->printCourse()) 
				{
					cout << "This teahcer doesn't have any course!\n";
				}
				delete t0;
				t0 = nullptr;
				break;
			}
			else 
			{
				con = false;
			}
		}
	}
	else 
	{
		cout << "The file\"teacher.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	return con;
}

bool Admin::checkCourseTime(string id) 
{
	bool con = false;
	ifstream file;
	string s;
	file.open("teacher.txt", ios::in);
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			if (s.find(id) != string::npos) 
			{
				con = true;
				Teacher* t0 = new Teacher(id);
				if (!t0->printCourseTime()) 
				{
					cout << "This teacher doesn't have any course time!\n";
				}
				delete t0;
				t0 = nullptr;
				break;
			}
			else 
			{
				con = false;
			}
		}
	}
	else 
	{
		cout << "The file\"teacher.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	return con;
}

void Admin::setWarning(string id, string cl, int we, string da, int st, int en, string re){
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	string ss = "W" + cl + setNumber99(we) + to_string(day) + setNumber99(st) + setNumber99(en) + setSerialNumber999(re) + re;
	ofstream file;
	file.open("S" + id + ".txt", ios::out | ios::app);
	if (file.is_open()) 
	{
		file << ss << endl;
	}
	else 
	{
		cout << "The file\"S" << id << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}
