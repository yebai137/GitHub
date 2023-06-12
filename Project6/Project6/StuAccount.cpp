#include<iostream>
#include<string>
#include<vector>
#include<istream>
#include<fstream>
#include<algorithm>
#include"StuAccount.h"
using namespace std;

StuAccount::StuAccount() 
{
	while (!allstu.empty()) 
	{
		vector<string>().swap(allstu);
	}
	ifstream file;
	file.open("student.txt", ios::in);
	if (file.is_open()) 
	{
		string stu;
		while (getline(file, stu)) 
		{
			allstu.push_back(stu);
		}
	}
	else 
	{
		cout << "The file \"student.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

StuAccount::~StuAccount()
{
	ofstream file;
	file.open("student.txt", ios::out);
	if (file.is_open()) 
	{
		for (size_t i = 0; i < allstu.size(); i++)
		{
			file << allstu[i] << "\n";
		}
	}
	else
	{
		cout << "The file \"student.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	while (!allstu.empty())
	{
		vector<string>().swap(allstu);
	}
	return;
}

int StuAccount::log(string id, string password) 
{
	int con = 1;
	string a = id + password;
	for (int i = 0; i < allstu.size(); i++) 
	{
		cout << allstu[i] << endl;
	}
	for (int i = 0; i < allstu.size(); i++)
	{
		if (allstu[i].find(a)!=string::npos)
		{
			string s;
			ifstream file;
			file.open("S" + id + ".txt", ios::in);
			while (getline(file, s))
			{
				if (s.at(0) == 'P') 
				{
					if (s.at(1) >= '3')
					{
						con = 2;//登录失败：该账号所有者违规次数过多
					}
					else 
					{
						con = 0;//登录成功
						break;
					}
				}
			}
			file.close();
			break;
		}
		else
		{
		con = 1;//登录失败：账号密码错误
		}
	}
	return con;
}

bool StuAccount::reg(string name, string id, string pw)
{
	bool con = true;
	string a = setSerialNumber(id) + setSerialNumber(pw) + id + pw;
	for (int i = 0; i < allstu.size(); i++) 
	{
		if (allstu[i].find(a)!=string::npos) 
		{
			con = false;
			return con;//注册失败：已有重复账号
		}
	}
	allstu.push_back(a);
	ofstream file;
	file.open("S" + id + ".txt", ios::out);
	if (file.is_open()) 
	{
		string b = "P0" + setSerialNumber(name) + setSerialNumber(id) + setSerialNumber(pw) + name + id + pw + "\n";
		file << b;
	}
	else
	{
		cout << "The file \"S" << id << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	con = true;//注册成功
	return con;
}

bool StuAccount::changePassword(string id,string npw)
{
	bool con = false;
	if (deleteAccount(id))
	{
		allstu.push_back(setSerialNumber(id) + setSerialNumber(npw) + id + npw);
		con = true;//改密码成功
	}
	else 
	{
	con = false;//改密码失败：找不到对应账户
	}
	return con;
}

bool StuAccount::deleteAccount(string id) 
{
	bool con = false;
	for (int i = 0; i < allstu.size(); i++) 
	{
		if (allstu[i].find(id) != string::npos) 
		{
			swap(allstu[i], allstu[allstu.size() - 1]);
			allstu.pop_back();
			con = true;//删除账号成功
			break;
		}
		else
		{
		con = false;//删除账号失败：找不到对应账户
		}
	}
	return con;
}