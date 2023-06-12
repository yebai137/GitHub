#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<istream>
#include"Classroom.h"
#include"GlobalFile.h"
using namespace std;

Classroom::Classroom() 
{
	vector<string>().swap(allcla);
	ifstream file;
	file.open("classroom.txt", ios::in);
	string s;
	if (file.is_open()) 
	{
		while (getline(file, s)) 
		{
			allcla.push_back(s);
		}
	}
	else 
	{
		cout << "The file \"classroom.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

Classroom::~Classroom() 
{
	ofstream file;
	file.open("classroom.txt", ios::out);
	if (file.is_open()) 
	{
		for (int i = 0; i < allcla.size(); i++) 
		{
			file << allcla[i] << endl;
		}
	}
	else 
	{
		cout << "The file \"classroom.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	vector<string>().swap(allcla);
	return;
}

bool Classroom::isClassroomValid(string cl) 
{
	bool con = false;
	if (cl.at(0) == 'A' && cl.at(1) >= '1' && cl.at(1) <= '5') 
	{
		if (cl.at(1) == '5') 
		{
			if (cl.at(2) >= '1' && cl.at(2) <= '8') 
			{
				if (cl.at(3) == '0' && cl.at(4) >= '1' && cl.at(4) <= '6') 
				{
					con = true;//输入正确
				}
				else con = false;
			}
			else con = false;
		}
		else 
		{
			if (cl.at(2) >= '1' && cl.at(2) <= '5') 
			{
				if (cl.at(3) == '0' && cl.at(4) >= '1' && cl.at(4) <= '8') 
				{
					con = true;
				}
				else con = false;
			}
			else con = false;
		}
	}
	else con = false;//输入错误
	return con;
}

bool Classroom::isDayValid(int we, string da) 
{
	bool con = false;
	if (we >= 1 && we <= 18) 
	{
		for (int i = 0; i < 7; i++) 
		{
			if (da == weekday[i]) 
			{
				con = true;//输入正确
				break;
			}
			else con = false;//输入错误
		}
	}
	else
	{
	con = false;
	}
	return con;
}

bool Classroom::isTimeValid(int st, int en) 
{
	bool con = false;
	if (st >= 1 && st <= 11 && en >= 1 && en <= 11) 
	{
		con = true;
	}
	else con = false;
	return con;
}

string Classroom::setSerialNumber(string a) 
{
	int b = 0;
	string c;
	if (a.at(0) == 'S') 
	{
		b = static_cast<int>(a.size());
	}
	else if (a.at(0) == 'T') 
	{
		b = static_cast<int>(a.size()) - 2;
	}
	if (b >= 1 && b <= 9) 
	{
		c = "0" + to_string(b);
	}
	else c = to_string(b);
	return c;
}

string Classroom::setSerialNumber(int a) 
{
	string b = "";
	if (a >= 1 && a <= 9) 
	{
		b = "0" + to_string(a);
	}
	else b = to_string(a);
	return b;
}

vector<string> Classroom::getSerialNumber(string s) 
{
	vector<string>con;
	int a = (static_cast<int>(s.at(10)) - 48) * 10 + static_cast<int>(s.at(11)) - 48;
	string b = s.substr(12, a);
	string c;
	if (b.at(0) == 'S') 
	{
		ifstream file;
		file.open(b + ".txt", ios::in);
		if (file.is_open()) {
			while (getline(file, c)) 
			{
				if (c.at(0) == 'P') 
				{
					int d = (static_cast<int>(s.at(2)) - 48) * 10 + (static_cast<int>(s.at(3)) - 48);
					con.push_back(c.substr(8, d));
					break;
				}
			}
		}
		else 
		{
			cout << "The file \"" << b << ".txt\" is lost!\n";
			exit(EXIT_FAILURE);
		}
		file.close();
		con.push_back("Occupied by student");
	}
	else if (b.at(0) == 'T') 
	{
		string e = "C" + s.substr(s.size() - 2, 2);
		ifstream file;
		file.open(b + ".txt", ios::in);
		if (file.is_open()) 
		{
			while (getline(file, c)) 
			{
				if (c.at(0) == 'P') 
				{
					int d = (static_cast<int>(s.at(2)) - 48) * 10 + (static_cast<int>(s.at(3)) - 48);
					con.push_back(c.substr(8, d));
					break;
				}
				else if (c.find(e) == 0) 
				{
					int d = (static_cast<int>(s.at(3)) - 48) * 10 + (static_cast<int>(s.at(4)) - 48);
					con.push_back(c.substr(5, d));
				}
			}
		}
		else 
		{
			cout << "The file \"" << b << ".txt\" is lost!\n";
			exit(EXIT_FAILURE);
		}
		file.close();
	}
	return con;
}

bool Classroom::isClassroomEmpty(string cl, int we, string da, int st, int en)
{
	int day = 0;
	bool con = true;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	string s = cl + setSerialNumber(we) + to_string(day);
	for (int i = 0; i < allcla.size(); i++) 
	{
		if (allcla[i].find(s)!=string::npos) 
		{
			int b = (static_cast<int>(allcla[i].at(8)) - 48) * 10 + static_cast<int>(allcla[i].at(9)) - 48;
			if (b >= st && b <= en) 
			{
				con = false;
				printClassroom(cl, we, da, b);
				//该教室不为空，返回该教室的信息
				break;
			}
		}
		else con = true;
	}
	return con;
}

void Classroom::printClassroom(string cl, int we, string da, int ti) {
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	cout << "Classroom: " << cl << setw(30) << "Date: Week " << we << ", " << da << setw(20) << "Time: " << start_time[ti - 1] << "~" << end_time[ti - 1] << endl;
	cout << "State: ";
	string s = cl + setSerialNumber(we) + to_string(day) + setSerialNumber(ti);
	for (int i = 0; i < allcla.size(); i++) 
	{
		if (allcla[i].find(s) != string::npos) 
		{
			cout << getSerialNumber(allcla[i])[1] << " " << getSerialNumber(allcla[i])[0] << "\n\n";
		}
		else 
		{
			cout << "Empty.\n\n";
		}
	}
	return;
}

void Classroom::changeClassroom(string cl, int we, string da, int ti, string s, string s1) 
{
	int day = 0;
	for (int i = 0; i < 7; i++) {

		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	deleteClassroomStatus(cl, we, da, ti);
	string ss = cl + setSerialNumber(we) + to_string(day) + setSerialNumber(ti) + setSerialNumber(s) + s + s1;
	allcla.push_back(ss);
}

void Classroom::deleteClassroomStatus(string s) 
{
	string a = s.substr(3, 5);
	int b = (static_cast<int>(s.at(8)) - 48) * 10 + static_cast<int>(s.at(9)) - 48;
	string c = weekday[static_cast<int>(s.at(10)) - 48];
	int d = (static_cast<int>(s.at(11)) - 48) * 10 + static_cast<int>(s.at(12)) - 48;
	deleteClassroomStatus(a, b, c, d);
}

void Classroom::deleteClassroomStatus(string cl, int we, string da, int ti) 
{
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	string ss = cl + setSerialNumber(we) + to_string(day) + setSerialNumber(ti);
	for (int i = 0; i < allcla.size(); i++) 
	{
		if (allcla[i].find(ss) != string::npos) 
		{
			auto iter = allcla.erase(begin(allcla) + i);
			break;
		}
	}
	return;
}

void Classroom::printAllEmptyClassroom(int we, string da, int st, int en) 
{
	int day = 0, sta = 0, end = 0;
	for (int i = 0; i < 7; i++) {

		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	string s = "A0000" + setSerialNumber(we) + to_string(day);
	vector<string>empcla;
	bool con = false;
	for (int i = 1; i <= 5; i++) 
	{
		s.at(1) = i + '0';
		int a = 0, b = 0;
		if (i == 5) {
			a = 8;
			b = 6;
		}
		else {
			a = 5;
			b = 8;
		}
		for (int j = 1; j <= a; j++) 
		{
			s.at(2) = j + '0';
			for (int k = 1; k <= b; k++) 
			{
				s.at(4) = '0' + k;
				for (int l = st; l <= en; l++) 
				{
					for (int m = 0; m < allcla.size(); m++) 
					{
						if (allcla[m].find(s + setSerialNumber(l)) != string::npos) {
							con = false;
							cout << con << endl;
							break;
						}
						else con = true;
					}
					if (!con) 
					{
						break;
					}
				}
				if (con) 
				{
					empcla.push_back(s.substr(0, 5));
				}
			}
		}
	}
	for (size_t i = 1; i <= empcla.size(); i++) 
	{
		cout << empcla[i - 1] << "    ";
		if (i % 10 == 0) {
			cout << "\n";
		}
	}
	return;
}

void Classroom::printClassroomPerWeek(string cl, int we) 
{
	string ss = cl + setSerialNumber(we);
	vector<vector<vector<string>>>tot(7);
	vector<vector<string>>col(11);
	for (int i = 0; i < 7; i++) 
	{
		tot[i] = col;
	}
	vector<string>unit;
	for (size_t i = 0; i < allcla.size(); i++) 
	{
		if (allcla[i].find(ss) == 0) 
		{
			int a = static_cast<int>(allcla[i].at(7)) - 48;
			int b = (static_cast<int>(allcla[i].at(8)) - 48) * 10 + static_cast<int>(allcla[i].at(9)) - 48;
			string sclass = getSerialNumber(allcla[i])[1];
			string sname = getSerialNumber(allcla[i])[0];
			for (size_t i = 0; i < sclass.size() / 15 + 1; i++) 
			{
				unit.push_back(sclass.substr(15 * i, 15));
			}
			for (size_t i = 0; i < sname.size() / 15 + 1; i++) 
			{
				unit.push_back(sname.substr(15 * i, 15));
			}
			tot[static_cast<size_t>(a - 1)][static_cast<size_t>(b - 1)] = unit;
		}
	}
	for (int i = 0; i < 119; i++) 
	{
		cout << "-";
	}
	cout << "\n|" << setw(6) << "|";
	for (int i = 0; i < 7; i++) 
	{
		cout << setw(16) << "|";
	}
	cout << "\n|" << setw(6) << "|";
	for (int i = 0; i < 7; i++) 
	{
		cout << setw(10) << weekday[i] << setw(6) << "|";
	}
	cout << "\n|" << setw(6) << "|";
	for (int i = 0; i < 7; i++) 
	{
		cout << setw(16) << "|";
	}
	cout << "\n";
	for (int i = 0; i < 119; i++) 
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < 11; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (j == 3) 
			{
				cout << "|" << setw(5) << start_time[i] << "|";
			}
			else if (j == 4) 
			{
				cout << "|  ~  |";
			}
			else if (j == 5) 
			{
				cout << "|" << setw(5) << end_time[i] << "|";
			}
			else 
			{
				cout << "|     |";
			}
			for (int k = 0; k < 7; k++) 
			{
				if (j < tot[k][i].size()) 
				{
					cout << left << setw(15) << tot[k][i][j] << "|";
				}
				else cout << right << setw(16) << "|";
			}
			cout << endl;
		}
		for (int i = 0; i < 119; i++) {
			cout << "-";
		}
		cout << endl << endl;
	}
	return;
}

void Classroom::printClassroomPerBuilding(string bu, int we, string da) 
{
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	int tot_room = 0, a = 0, b = 0;
	if (bu.at(1) == '5') 
	{
		tot_room = 48;
		a = 8;
		b = 6;
	}
	else 
	{
		tot_room = 40;
		a = 5;
		b = 8;
	}
	string ss = bu + "000" + setSerialNumber(we) + to_string(day);
	vector<vector<vector<string>>>tot(tot_room);
	vector<vector<string>>col(11);
	for (int i = 0; i < tot.size(); i++) 
	{
		tot[i] = col;
	}
	vector<string>unit;
	vector<string>title;
	for (int i = 0; i < a; i++) 
	{
		ss.at(2) = '1' + i;
		for (int j = 0; j < b; j++) 
		{
			ss.at(4) = '1' + j;
			title.push_back(ss.substr(0, 5));
			for (size_t k = 0; k < allcla.size(); k++) 
			{
				if (allcla[k].find(ss) == 0) 
				{
					int c = static_cast<int>(allcla[k].at(7)) - 48;
					int d = (static_cast<int>(allcla[k].at(8)) - 48) * 10 + static_cast<int>(allcla[k].at(9)) - 48;
					string sclass = getSerialNumber(allcla[k])[1];
					string sname = getSerialNumber(allcla[k])[0];
					for (size_t i = 0; i < sclass.size() / 15 + 1; i++) 
					{
						unit.push_back(sclass.substr(15 * i, 15));
					}
					for (size_t i = 0; i < sname.size() / 15 + 1; i++) 
					{
						unit.push_back(sname.substr(15 * i, 15));
					}
					tot[static_cast<size_t>(c - 1)][static_cast<size_t>(d - 1)] = unit;
				}
			}
		}
	}
	for (int l = 0; l < (tot_room / 7 + 1); l++) 
	{
		for (int i = 0; i < 119; i++) 
		{
			cout << "-";
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			cout << setw(16) << "|";
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			int co = i + l * 7;
			if (co < title.size()) 
			{
				cout << setw(9) << title[co] << setw(7) << "|";
			}
			else {
				cout << right << setw(16) << "|";
			}
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			cout << setw(16) << "|";
		}
		cout << "\n";
		for (int i = 0; i < 119; i++) 
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < 11; i++) 
		{
			for (int j = 0; j < 10; j++) 
			{
				if (j == 3) 
				{
					cout << "|" << setw(5) << start_time[i] << "|";
				}
				else if (j == 4) 
				{
					cout << "|  ~  |";
				}
				else if (j == 5) 
				{
					cout << "|" << setw(5) << end_time[i] << "|";
				}
				else 
				{
					cout << "|     |";
				}
				for (int k = 0; k < 7; k++) 
				{
					int uu = k + 7 * l;
					if (uu < tot.size()) 
					{
						if (j < tot[uu][i].size()) 
						{
							cout << left << setw(15) << tot[uu][i][j] << "|";
						}
						else 
						{
							cout << right << setw(16) << "|";
						}
					}
					else 
					{
						cout << right << setw(16) << "|";
					}
				}
				cout << endl;
			}
			for (int i = 0; i < 119; i++) 
			{
				cout << "-";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void Classroom::printAllClassroom(int we, string da) 
{
	int day = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	for(int n=1;n<=5;n++)
	{
		string bu = "A" + to_string(n);
		int tot_room = 208, a = 0, b = 0;
		if (bu.at(1) == '5') 
		{
			a = 8;
			b = 6;
		}
		else 
		{
			a = 5;
			b = 8;
		}
		string ss = bu + "000" + setSerialNumber(we) + to_string(day);
		vector<vector<vector<string>>>tot(tot_room);
		vector<vector<string>>col(11);
		for (int i = 0; i < tot.size(); i++) 
		{
			tot[i] = col;
		}
		vector<string>unit;
		vector<string>title;
		for (int i = 0; i < a; i++) 
		{
			ss.at(2) = '1' + i;
			for (int j = 0; j < b; j++) 
			{
				ss.at(4) = '1' + j;
				title.push_back(ss.substr(0, 5));
				for (int k = 0; k < allcla.size(); k++) 
				{
					if (allcla[k].find(ss) == 0) 
					{
						int c = static_cast<int>(allcla[k].at(7)) - 48;
						int d = (static_cast<int>(allcla[k].at(8)) - 48) * 10 + static_cast<int>(allcla[k].at(9)) - 48;
						string sclass = getSerialNumber(allcla[k])[1];
						string sname = getSerialNumber(allcla[k])[0];
						for (size_t i = 0; i < sclass.size() / 15 + 1; i++) 
						{
							unit.push_back(sclass.substr(15 * i, 15));
						}
						for (size_t i = 0; i < sname.size() / 15 + 1; i++) 
						{
							unit.push_back(sname.substr(15 * i, 15));
						}
						tot[static_cast<size_t>(c - 1)][static_cast<size_t>(d - 1)] = unit;
					}
				}
			}
		}
		for (int l = 0; l < (tot_room / 7 + 1); l++) 
		{
			for (int i = 0; i < 119; i++) 
			{
				cout << "-";
			}
			cout << "\n|" << setw(6) << "|";
			for (int i = 0; i < 7; i++) 
			{
				cout << setw(16) << "|";
			}
			cout << "\n|" << setw(6) << "|";
			for (int i = 0; i < 7; i++) 
			{
				int co = i + l * 7;
				if (co < title.size()) 
				{
					cout << setw(9) << title[co] << setw(7) << "|";
				}
				else 
				{
					cout << right << setw(16) << "|";
				}
			}
			cout << "\n|" << setw(6) << "|";
			for (int i = 0; i < 7; i++) 
			{
				cout << setw(16) << "|";
			}
			cout << "\n";
			for (int i = 0; i < 119; i++) 
			{
				cout << "-";
			}
			cout << endl;
			for (int i = 0; i < 11; i++) 
			{
				for (int j = 0; j < 10; j++) 
				{
					if (j == 3) 
					{
						cout << "|" << setw(5) << start_time[i] << "|";
					}
					else if (j == 4) 
					{
						cout << "|  ~  |";
					}
					else if (j == 5) 
					{
						cout << "|" << setw(5) << end_time[i] << "|";
					}
					else 
					{
						cout << "|     |";
					}
					for (int k = 0; k < 7; k++) 
					{
						int uu = k + 7 * l;
						if (uu < tot.size()) 
						{
							if (j < tot[uu][i].size()) 
							{
								cout << left << setw(15) << tot[uu][i][j] << "|";
							}
							else 
							{
								cout << right << setw(16) << "|";
							}
						}
						else 
						{
							cout << right << setw(16) << "|";
						}
					}
					cout << endl;
				}
				for (int i = 0; i < 119; i++) 
				{
					cout << "-";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	cout << endl;
	return;
}

void Classroom::printClassroomAllWeek(string cl, string da) 
{
	int day = 0, sta = 0, end = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekday[i] == da) 
		{
			day = i + 1;
			break;
		}
	}
	vector<vector<vector<string>>>tot(18);
	vector<vector<string>>col(11);
	for (int i = 0; i < 7; i++) 
	{
		tot[i] = col;
	}
	vector<string>unit;
	vector<string>title;
	for (int i = 0; i < 18; i++) 
	{
		title.push_back("Week " + (to_string(i + 1)));
		string ss = cl + setSerialNumber(i + 1) + to_string(day);
		for (int k = 0; k < allcla.size(); k++) 
		{
			if (allcla[k].find(ss) == 0) 
			{
				int c = static_cast<int>(allcla[k].at(7)) - 48;
				int d = (static_cast<int>(allcla[k].at(8)) - 48) * 10 + static_cast<int>(allcla[k].at(9)) - 48;
				string sclass = getSerialNumber(allcla[k])[1];
				string sname = getSerialNumber(allcla[k])[0];
				for (size_t i = 0; i < sclass.size() / 15 + 1; i++) 
				{
					unit.push_back(sclass.substr(15 * i, 15));
				}
				for (size_t i = 0; i < sname.size() / 15 + 1; i++) 
				{
					unit.push_back(sname.substr(15 * i, 15));
				}
				tot[static_cast<size_t>(c - 1)][static_cast<size_t>(d - 1)] = unit;
			}
		}
	}
	for (int l = 0; l < (18 / 7 + 1); l++) 
	{
		for (int i = 0; i < 119; i++) 
		{
			cout << "-";
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			cout << setw(16) << "|";
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			int co = i + l * 7;
			if (co < title.size()) 
			{
				cout << setw(8) << title[co] << setw(8) << "|";
			}
			else {
				cout << right << setw(16) << "|";
			}
		}
		cout << "\n|" << setw(6) << "|";
		for (int i = 0; i < 7; i++) 
		{
			cout << setw(16) << "|";
		}
		cout << "\n";
		for (int i = 0; i < 119; i++) 
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 10; j++) 
			{
				if (j == 3) 
				{
					cout << "|" << setw(5) << start_time[i] << "|";
				}
				else if (j == 4) 
				{
					cout << "|  ~  |";
				}
				else if (j == 5) 
				{
					cout << "|" << setw(5) << end_time[i] << "|";
				}
				else 
				{
					cout << "|     |";
				}
				for (int k = 0; k < 7; k++) 
				{
					int uu = k + 7 * l;
					if (uu < tot.size()) 
					{
						if (j < tot[uu][i].size()) 
						{
							cout << left << setw(15) << tot[uu][i][j] << "|";
						}
						else 
						{
							cout << right << setw(16) << "|";
						}
					}
					else 
					{
						cout << right << setw(16) << "|";
					}
				}
				cout << endl;
			}
			for (int i = 0; i < 119; i++) {
				cout << "-";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
	return;
}