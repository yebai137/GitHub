#pragma once
#ifndef STUACCOUNT_H
#define STUACCOUNT_H

#include<string>
#include<vector>
#include"Account.h"
using namespace std;

class StuAccount:public Account 
{
public:
	StuAccount();
	~StuAccount();
	int log(string, string);
	bool reg(string, string, string);
	bool changePassword(string, string);
	bool deleteAccount(string);
protected:
	vector<string>allstu;
};

#endif