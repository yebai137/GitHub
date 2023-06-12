#pragma once
#ifndef PERSON_H
#define PERSON_H

#include<string>
#include<vector>
using namespace std;

class Person 
{
public:
	void setName(string);
	void setID(string);
	void setPassword(string);
	string getName();
	string getID();
	string getPassword();
	string setSerialNumber99(string);
	string setNumber99(int);
	string setSerialNumber999(string);
	vector<string> getSerialNumber(string);
protected:
	string name;
	string ID;
	string password;
};

#endif