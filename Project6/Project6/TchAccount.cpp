#include<iostream>
#include<string>
#include<vector>
#include<istream>
#include<fstream>
#include<algorithm>
#include"TchAccount.h"
using namespace std;

TchAccount::TchAccount() 
{
	while (!alltch.empty()) 
	{
		vector<string>().swap(alltch);
	}
	ifstream file;
	file.open("teacher.txt", ios::in);
	if (file.is_open()) 
	{
		string stu;
		while (getline(file, stu)) 
		{
			alltch.push_back(stu);
		}
	}
	else 
	{
		cout << "The file \"teahcer.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	return;
}

TchAccount::~TchAccount()
{
	ofstream file;
	file.open("teacher.txt", ios::out);
	if (file.is_open()) {
		for (size_t i = 0; i < alltch.size(); i++) 
		{
			file << alltch[i] << "\n";
		}
	}
	else 
	{
		cout << "The file \"teahcer.txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	while (!alltch.empty())
	{
		vector<string>().swap(alltch);
	}
	return;
}

int TchAccount::log(string id, string password) 
{
	int con = 1;
	string a = id + password;
	for (int i = 0; i < alltch.size(); i++) 
	{
		if (alltch[i].find(a)!=string::npos) 
		{
			con = 0;//��¼�ɹ�
			break;
		}
		else
		{
		con = 1;//��¼ʧ��
		}
	}
	return con;
}

bool TchAccount::reg(string name, string id, string pw) 
{
	bool con = true;
	string a = setSerialNumber(id) + setSerialNumber(pw) + id + pw;
	for (int i = 0; i < alltch.size(); i++)
	{
		if (alltch[i].find(a)!=string::npos)
		{
			con = false;
			return con;//ע��ʧ�ܣ������ظ��˺ţ�
		}
	}
	alltch.push_back(a);
	ofstream file;
	file.open("T" + id + ".txt", ios::out);
	if (file.is_open())
	{
		string b = "P0" + setSerialNumber(name) + setSerialNumber(id) + setSerialNumber(pw) + name + id + pw + "\n";
		file << b;
	}
	else 
	{
		cout << "The file \"T" << id << ".txt\" is lost!\n";
		exit(EXIT_FAILURE);
	}
	file.close();
	con = true;//ע��ɹ�
	for (int i = 0; i < alltch.size(); i++) 
	{
		cout << alltch[i] << endl;
	}
	return con;
}

bool TchAccount::changePassword(string id, string npw) 
{
	bool con = false;
	if (deleteAccount(id)) 
	{
		alltch.push_back(setSerialNumber(id) + setSerialNumber(npw) + id + npw);
		con = true;//������ɹ�
	}
	else
	{
	con = false;//������ʧ�ܣ��Ҳ�����Ӧ�˻�
	}
	return con;
}

bool TchAccount::deleteAccount(string id) 
{
	bool con = false;
	for (int i = 0; i < alltch.size(); i++) 
	{
		if (alltch[i].find(id) != string::npos) 
		{
			swap(alltch[i], alltch[alltch.size() - 1]);
			alltch.pop_back();
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