#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#include<istream>
#include"Student.h"
#include"GlobalFile.h"
#include"StuAccount.h"
#include"Classroom.h"
using namespace std;

Student::Student(string id) 
{
	vector<string>().swap(allord);
	vector<string>().swap(allwar);
	warn = 0;
	string s;
	ifstream file;
	file.open("S" + id + ".txt", ios::in);
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			if (s.at(0) == 'P') 
			{
				setName(getSerialNumber(s)[0]);
				setID(getSerialNumber(s)[1]);
				setPassword(getSerialNumber(s)[2]);
			}
			else if (s.at(0) == 'O')
			{
				allord.push_back(s);
			}
			else if (s.at(0) == 'W') 
			{
				allwar.push_back(s);
				++warn;
			}
		}
	}
	else 
	{
		cout << "The file\"S" << id << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

Student::~Student()
{
	ofstream file;
	file.open("S" + getID() + ".txt", ios::out);
	if (file.is_open())
	{
		file << "P" << to_string(getWarn()) << setSerialNumber99(getName()) << setSerialNumber99(getID()) << setSerialNumber99(getPassword()) << getName() << getID() << getPassword() << "\n";
		for (size_t i = 0; i < allord.size(); i++)
		{
			file << allord[i] << "\n";
		}
		for (size_t i = 0; i < allwar.size(); i++) 
		{
			file << allwar[i] << "\n";
		}
	}
	else 
	{
		cout << "The file\"S" << getID() << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	vector<string>().swap(allord);
	vector<string>().swap(allwar);
	return;
}

void Student::setWarn(int a) 
{
	warn = a;
	return;
}

int Student::getWarn() 
{
	return warn;
}

bool Student::printWarn() 
{
	bool con = false;
	if (allwar.empty()&& warn == 0)
	{
		con = false;//无警告记录
	}
	else {
		for (int i = 0; i < allwar.size(); i++) 
		{
			cout << "Classroom: " << getSerialNumber(allwar[i])[0] << "     Date: " << getSerialNumber(allwar[i])[1];
			cout << " " << getSerialNumber(allwar[i])[2] << endl << "Time: " << getSerialNumber(allwar[i])[3] << endl;
			cout << "Remark: " << getSerialNumber(allwar[i])[4] << "\n\n";
		}
		con = true;//输出警告记录
	}
	return con;
}

void Student::changePassword(string npw)
{
	setPassword(npw);
	return;
}

bool Student::addOrder(string cl, int we, string da, int st, int en, string remark)
{
	bool con = false;
	string s = "O";
	string we0;
	string st0;
	string en0;
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (da == weekday[i]) 
		{
			day = i;
		}
	}
	if (we >= 1 && we <= 9) 
	{
		we0 = "0" + to_string(we);
	}
	else we0 = to_string(we);
	if (st == 10 || st == 11) 
	{
		st0 = to_string(st);
	}
	else st0 = "0" + to_string(st);
	if (en == 10 || en == 11)
	{
		st0 = to_string(en);
	}
	else st0 = "0" + to_string(en);
	for (int i = 0; i < allord.size(); i++)
	{
		if (allord[i].find(cl + to_string(we) + to_string(day) + st0 + en0) != string::npos) 
		{
			con = false;
			break;
		}
		else 
		{
			con = true;
		}
	}
	if(con) 
	{
		s += (cl + to_string(we) + to_string(day) + st0 + en0 + setSerialNumber999(remark) + remark + "0");//0：正在审核
		allord.push_back(s);
		cout << "You've added a new order successfully!\n";
	}
	return con;
}

bool Student::printOrder() 
{
	bool con = true;
	if (allord.empty()) 
	{
		con = false;//没有预约记录
	}
	else {
		string s;
		for (int i = 0; i < allord.size(); i++)
		{
			cout << "Order No." << i + 1 << "\n";
			cout << "Applicant: " << getName() << "     Student ID: " << getID() << "\n";
			cout << "Classroom: " << getSerialNumber(allord[i])[0] << "     Date: Week " << getSerialNumber(allord[i])[1] << ", ";
			cout << getSerialNumber(allord[i])[2] << "     Time: " << getSerialNumber(allord[i])[3] << "~" << getSerialNumber(allord[i])[4] << "\n";
			cout << "Remark: " << getSerialNumber(allord[i])[5] << endl;
			cout << "State: " << getSerialNumber(allord[i])[6] << "\n\n";
		}
		con = true;
	}
	return true;
}

bool Student::removeOrder(int a) 
{
	bool con = false;
	if (!allord.empty()) 
	{
		if (a > 0 && a <= allord.size())
		{
			auto iter = allord.erase(begin(allord) + a - 1);
			con = true;
		}
		else con = false;
	}
	else con = false;
	return con;
}

bool Student::removeAllRejectedOrder()
{
	bool con = false;
	for (int i = 0; i < allord.size(); i++) 
	{
		if (allord[i].back() == '2') 
		{
			auto iter = allord.erase(begin(allord) + i);
			con = true;
		}
	}
	return con;
}

bool Student::changeOrder(Classroom* c, int a, char b) 
{
	bool con = false;
	if (!allord.empty())
	{
		if (a > 0 && a <= allord.size())
		{
			size_t te = static_cast<size_t>(a - 1);
			allord[te].at(allord[te].size() - 1) = b;
			string cl = getSerialNumber(allord[te])[0];
			int we = (static_cast<int>(allord[te].at(6)) - 48) * 10 + (static_cast<int>(allord[te].at(7)) - 48);
			string da = getSerialNumber(allord[te])[2];
			int st0 = (static_cast<int>(allord[te].at(9)) - 48) * 10 + (static_cast<int>(allord[te].at(10)) - 48);
			int en0 = (static_cast<int>(allord[te].at(11)) - 48) * 10 + (static_cast<int>(allord[te].at(12)) - 48);
			int st = st0 < en0 ? st0 : en0;
			int en = st0 > en0 ? st0 : en0;
			for (int i = st; i <= en; i++) 
			{
				c->changeClassroom(cl, we, da, i, "S" + getID(),"");
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

void Student::deleteAccount(StuAccount* a) 
{
	a->deleteAccount(getID());
	setName("");
	setID("");
	setPassword("");
	vector<string>().swap(allord);
	vector<string>().swap(allwar);
	return;
}

void Student::printAllEmptyCl(Classroom* e, int a, string b, int c, int d) 
{
	e->printAllEmptyClassroom(a, b, c, d);
	return;
}

void Student::printClPerWeek(Classroom* e, string a, int b) 
{
	e->printClassroomPerWeek(a, b);
	return;
}

void Student::printClPerBuilding(Classroom* e, string a, int b, string c) 
{
	e->printClassroomPerBuilding(a, b, c);
	return;
}

void Student::printAllCl(Classroom* e, int a, string b) 
{
	e->printAllClassroom(a, b);
	return;
}

void Student::printClAllWeek(Classroom* e, string a, string b)
{
	e->printClassroomAllWeek(a, b);
	return;
}