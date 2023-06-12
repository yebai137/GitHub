#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>
#include<vector>
using namespace std;

class Account 
{
public:
	virtual int log(string, string) = 0;
	virtual bool reg(string, string, string) = 0;
	virtual bool changePassword(string, string) = 0;
	virtual bool deleteAccount(string) = 0;
	string setSerialNumber(string);
};

#endif