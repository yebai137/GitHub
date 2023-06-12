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
						con = 2;//��¼ʧ�ܣ����˺�������Υ���������
					}
					else 
					{
						con = 0;//��¼�ɹ�
						break;
					}
				}
			}
			file.close();
			break;
		}
		else
		{
		con = 1;//��¼ʧ�ܣ��˺��������
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
			return con;//ע��ʧ�ܣ������ظ��˺�
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
	con = true;//ע��ɹ�
	return con;
}

bool StuAccount::changePassword(string id,string npw)
{
	bool con = false;
	if (deleteAccount(id))
	{
		allstu.push_back(setSerialNumber(id) + setSerialNumber(npw) + id + npw);
		con = true;//������ɹ�
	}
	else 
	{
	con = false;//������ʧ�ܣ��Ҳ�����Ӧ�˻�
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
			con = true;//ɾ���˺ųɹ�
			break;
		}
		else
		{
		con = false;//ɾ���˺�ʧ�ܣ��Ҳ�����Ӧ�˻�
		}
	}
	return con;
}