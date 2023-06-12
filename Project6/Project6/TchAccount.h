#pragma once
#ifndef TCHACCOUNT_H
#define TCHACCOUNT_H

#include<string>
#include<vector>
#include"Account.h"
using namespace std;

class TchAccount :public Account 
{
public:
	TchAccount();
	~TchAccount();
	int log(string, string);
	bool reg(string, string, string);
	bool changePassword(string, string);
	bool deleteAccount(string);
protected:
	vector<string>alltch;
};

#endif