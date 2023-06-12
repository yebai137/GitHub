#include<string>
#include<vector>
#include"Person.h"
#include"GlobalFile.h"
using namespace std;

void Person::setName(string a) 
{
	name = a;
	return;
}

void Person::setID(string a)
{
	ID = a;
	return;
}

void Person::setPassword(string a)
{
	password = a;
	return;
}

string Person::getName() 
{
	return name;
}

string Person::getID() 
{
	return ID;
}

string Person::getPassword()
{
	return password;
}

string Person::setSerialNumber99(string a)
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

string Person::setNumber99(int b) 
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

string Person::setSerialNumber999(string a)
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

vector<string> Person::getSerialNumber(string s) 
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