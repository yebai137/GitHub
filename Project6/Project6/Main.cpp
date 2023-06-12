#include<iostream>
#include<string>
#include<fstream>
#include<istream>
#include"GlobalFile.h"
#include"StuAccount.h"
#include"TchAccount.h"
#include"Student.h"
#include"Teacher.h"
#include"Admin.h"
#include"Classroom.h"
using namespace std;

bool checkInput(string, int);
string removeSpace(string);
void main1();
void stuLogin2();
void tchLogin2();
void admLogin2();
void admMain3(Admin*);
void stuReg3(StuAccount*);
void stuLog3(StuAccount*);
void tchReg3(TchAccount*);
void tchLog3(TchAccount*);
int stuMain4(StuAccount*, Student*);
int tchMain4(TchAccount*, Teacher*);
void admMain3(Admin*);
void admCla4(Classroom*, Admin*);
void tchCou5(Classroom*, Teacher*);
void tchCla5(Teacher*, Classroom*);
void stuOrd5(Student*, Classroom*);
void stuCla5(Student*, Classroom*);
void stuAddOrd6(Student*, Classroom*);
void stuRemOrd6(Student*);

int main() 
{
	main1();
	cout << "You have exit the program!\n";
	system("pause");
	return 0;
}

bool checkInput(string a, int b) 
{
	bool con = false;
	if (a.size() > b || a.size() <= 2) 
	{
		con = false;//输入字符不符合设定的长度限制
	}
	else
	{
	con = true;
	}
	return con;
}

string removeSpace(string s) 
{
	string st;
	for (size_t i = 0; i < s.size(); i++) 
	{
		if (s.at(i) != ' ') 
		{
			st.push_back(s.at(i));
		}
	}
	return st;
}

void main1() 
{
	int count1 = 1;
	system("cls");
	cout << "Welcome to the Empty Classroom Reservation System!\n";
	cout << "Please enter an integer to choose the operation you want:\n";
	cout << "1: Log in as a student.\n";
	cout << "2: Log in as a teacher.\n";
	cout << "3: Log in as the administrator.\n";
	cout << "4: Show the operation list again.\n";
	cout << "0: Exit.\n";
	while (count1 != 0) 
	{
		cin >> count1;
		switch (count1) 
		{
		case 1: 
		{
			stuLogin2();
			break;
		}
		case 2: 
		{
			tchLogin2();
			break;
		}
		case 3: 
		{
			admLogin2();
			break;
		}
		case 4:
		{
			cout << "1: Log in as a student.\n";
			cout << "2: Log in as a teacher.\n";
			cout << "3: Log in as the administrator.\n";
			cout << "4: Show the operation list again.\n";
			cout << "0: Exit.\n";
			cout << "Please enter an integer to choose the operation you want:\n";
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			cout << "The integer you've entered is invalid!\n";
			cout << "Please enter an integer again: ";
			break;
		}
		}
	}
	return;
}

void stuLogin2() 
{
	int count2 = 1;
	cout << "Please enter an integer to choose the operation you want:\n";
	cout << "1: Log in to an existing account.\n";
	cout << "2: Register a new account.\n";
	cout << "3: Show the operation list again.\n";
	cout << "0: Return to the previous menu.\n";
	StuAccount* sa = new StuAccount();
	while (count2 != 0) 
	{
		cin >> count2;
		switch (count2) 
		{
		case 1: 
		{
			stuLog3(sa);
			break;
		}
		case 2: 
		{
			stuReg3(sa);
			break;
		}
		case 3: 
		{
			cout << "1: Log in to an existing account.\n";
			cout << "2: Register a new account.\n";
			cout << "3: Show the operation list again.\n";
			cout << "0: Return to the previous menu.\n";
			cout << "Please enter an integer to choose the operation you want:\n";
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			cout << "The integer you've entered is invalid!\n";
			cout << "Please enter an integer again: ";
			break;
		}
		}
	}
	delete sa;
	sa = nullptr;
	return;
}

void tchLogin2() 
{
	int count2 = 1;
	cout << "Please enter an integer to choose the operation you want:\n";
	cout << "1: Log in to an existing account.\n";
	cout << "2: Register a new account.\n";
	cout << "3: Show the operation list again.\n";
	cout << "0: Return to the previous menu.\n";
	TchAccount* ta = new TchAccount();
	while (count2 != 0) 
	{
		cin >> count2;
		switch (count2) 
		{
		case 1: 
		{
			tchLog3(ta);
			break;
		}
		case 2: 
		{
			tchReg3(ta);
			break;
		}
		case 3: 
		{
			cout << "1: Log in to an existing account.\n";
			cout << "2: Register a new account.\n";
			cout << "3: Show the operation list again.\n";
			cout << "0: Return to the previous menu.\n";
			cout << "Please enter an integer to choose the operation you want:\n";
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			cout << "The integer you've entered is invalid!\n";
			cout << "Please enter an integer again: ";
			break;
		}
		}
	}
	delete ta;
	ta = nullptr;
	return;
}

void stuLog3(StuAccount* sa) 
{
	int a = 1;
	while (a!=0) 
	{
		string id, pw;
		cout << "Please enter your student ID: ";
		cin >> id;
		cout << "Please enter the password: ";
		cin >> pw;
		if (sa->log(removeSpace(id), removeSpace(pw)) == 0) 
		{
			cout << "You've logged in successfully!\n";
			Student* s = new Student(removeSpace(id));
			a = stuMain4(sa,s);
			delete s;
			s = nullptr;
		}
		else if (sa->log(removeSpace(id), removeSpace(pw)) == 2) 
		{
			cout << "You have been blocked for too much illegal behaviour!\n";
			cout << "Please enter 1 to continue to log in or enter 0 to return to the previous menu: ";
			int a;
			cin >> a;
			if (a != 0) 
			{
				cout << "\n\nPlease enter an integer to choose the operation you want:\n";
				cout << "1: Log in to an existing account.\n";
				cout << "2: Register a new account.\n";
				cout << "0: Return to the previous menu.\n";
				break;
			}
		}
		else 
		{
			cout << "The student ID or the password you've entered is invalid!\n";
			cout << "Please enter 1 to continue to log in or enter 0 to return to the previous menu: ";
			int a;
			cin >> a;
			if (a != 0) 
			{
				cout << "\n\nPlease enter an integer to choose the operation you want:\n";
				cout << "1: Log in to an existing account.\n";
				cout << "2: Register a new account.\n";
				cout << "0: Return to the previous menu.\n";
				break;
			}
		}
	}
	return;
}

void stuReg3(StuAccount* sa) 
{
	while (true) 
	{
		string name, id, pw;
		cout << "Please enter your name: ";
		cin >> name;
		while (!checkInput(name,99)) 
		{
			cout << "The name you've entered is too large!\nPlease enter the name properly: ";
			cin >> name;
		}
		cout << "Please enter your student ID: ";
		cin >> id;
		while (!checkInput(removeSpace(id), 30)) 
		{
			cout << "The student ID you've entered is too large!\nPlease enter the student ID properly: ";
			cin >> id;
		}
		cout << "Please enter the password: ";
		cin >> pw;
		while (!checkInput(removeSpace(pw), 30)) 
		{
			cout << "The password you've entered is too large!\nPlease enter the password properly: ";
			cin >> pw;
		}
		if (sa->reg(name, removeSpace(id), removeSpace(pw))) 
		{
			cout << "You've registered successfully!\n\n";
			cout << "Please enter an integer to choose the operation you want:\n";
			cout << "1: Log in to an existing account.\n";
			cout << "2: Register a new account.\n";
			cout << "3: Show the operation list again.\n";
			cout << "0: Return to the previous menu.\n";
			break;
		}
		else 
		{
			cout << "You've registered an existing account!\n";
			cout << "Please enter 1 to continue to log in or enter 0 to return to the previous menu: ";
			int a;
			cin >> a;
			if (a == 0) 
			{
				cout << "\n\nPlease enter an integer to choose the operation you want:\n";
				cout << "1: Log in to an existing account.\n";
				cout << "2: Register a new account.\n";
				cout << "0: Return to the previous menu.\n";
				break;
			}
		}
	}
	return;
}

void tchLog3(TchAccount* ta) {
	int a = 1;
	while (a!=0) 
	{
		string id, pw;
		cout << "Please enter your teacher ID: ";
		cin >> id;
		cout << "Please enter the password: ";
		cin >> pw;
		if (ta->log(removeSpace(id), removeSpace(pw))==0) 
		{
			cout << "You've logged in successfully!\n";
			Teacher* t = new Teacher(removeSpace(id));
			a=tchMain4(ta, t);
			delete t;
			t = nullptr;
		}
		else 
		{
			cout << "The teacher ID or the password you've entered is invalid!\n";
			cout << "Please enter 1 to continue to log in or enter 0 to return to the previous menu: ";
			int a;
			cin >> a;
			if (a != 0) {
				cout << "\n\nPlease enter an integer to choose the operation you want:\n";
				cout << "1: Log in to an existing account.\n";
				cout << "2: Register a new account.\n";
				cout << "0: Return to the previous menu.\n";
				break;
			}
		}
	}
	return;
}

void tchReg3(TchAccount* ta) 
{
	while (true) 
	{
		string name, id, pw;
		cout << "Please enter your name: ";
		cin >> name;
		while (!checkInput(name, 99)) 
		{
			cout << "The name you've entered is too large!\nPlease enter the name properly: ";
			cin >> name;
		}
		cout << "Please enter your teacher ID: ";
		cin >> id;
		while (!checkInput(removeSpace(id), 30)) 
		{
			cout << "The teacher ID you've entered is too large!\nPlease enter the teacher ID properly: ";
			cin >> id;
		}
		cout << "Please enter the password: ";
		cin >> pw;
		while (!checkInput(removeSpace(pw), 30)) 
		{
			cout << "The password you've entered is too large!\nPlease enter the password properly: ";
			cin >> pw;
		}
		if (ta->reg(name, removeSpace(id), removeSpace(pw))) 
		{
			cout << "You've registered successfully!\n\n";
			cout << "Please enter an integer to choose the operation you want:\n";
			cout << "1: Log in to an existing account.\n";
			cout << "2: Register a new account.\n";
			cout << "3: Show the operation list again.\n";
			cout << "0: Return to the previous menu.\n";
			break;
		}
		else 
		{
			cout << "You've registered an existing account!\n";
			cout << "Please enter 1 to continue to log in or enter 0 to return to the previous menu: ";
			int a;
			cin >> a;
			if (a != 0) 
			{
				cout << "\n\nPlease enter an integer to choose the operation you want:\n";
				cout << "1: Log in to an existing account.\n";
				cout << "2: Register a new account.\n";
				cout << "0: Return to the previous menu.\n";
				break;
			}
		}
	}
	return;
}

int stuMain4(StuAccount* sa, Student* s) 
{
	Classroom* c = new Classroom();
	int abc = 1;
	while (abc != 0) {
		cout << "Welcome!" << s->getName() << endl;
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Add, change,or remove your order.\n";
		cout << "2: Print the warning you've received.\n";
		cout << "3: Show the classroom table.\n";
		cout << "4: Change your password.\n";
		cout << "5: Delete your account.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> abc;
		switch (abc) 
		{
		case 1: 
		{
			stuOrd5(s, c);
			break;
		}
		case 2: 
		{
			if (!s->getWarn()) 
			{
				cout << "You haven't received any warning yet!\n";
			}
			break;
		}
		case 3: 
		{
			stuCla5(s, c);
			break;
		}
		case 4: 
		{
			cout << "Please enter your new password: ";
			string npw;
			cin >> npw;
			s->changePassword(removeSpace(npw));
			cout << "You've changed your password successfully!\n";
			break;
		}
		case 5: 
		{
			cout << "Do you really want to delete your account? It's irrecoverable!\nPlease enter 0 to continue.\n";
			int a = 1;
			cin >> a;
			if (a == 0) 
			{
				s->deleteAccount(sa);
				system("cls");
				cout << "Your account has been deleted successsfully!\n";
			}
			else 
			{
				break;
			}
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			break;
		}
		}
	}
	delete c;
	c = nullptr;
	return 0;
}

int tchMain4(TchAccount* ta, Teacher* t) 
{
	Classroom* c = new Classroom();
	int abc = 1;
	while (abc != 0) 
	{
		cout << "Welcome!" << t->getName() << endl;
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Add, change,or remove your course and its time.\n";
		cout << "2: Show the classroom table.\n";
		cout << "3: Change your password.\n";
		cout << "4: Delete your account.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> abc;
		switch (abc) 
		{
		case 1: 
		{
			tchCou5(c, t);
			break;
		}
		case 2: 
		{
			tchCla5(t, c);
			break;
		}
		case 3: 
		{
			cout << "Please enter your new password: ";
			string npw;
			cin >> npw;
			t->changePassword(removeSpace(npw));
			cout << "You've changed your password successfully!\n";
			break;
		}
		case 4: 
		{
			cout << "Do you really want to delete your account? It's irrecoverable!\nPlease enter 0 to continue.\n";
			int a = 1;
			cin >> a;
			if (a == 0) 
			{
				t->deleteAccount(ta, c);
				system("cls");
				cout << "Your account has been deleted successsfully!\n";
			}
			else 
			{
				break;
			}
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			break;
		}
		}
	}
	delete c;
	c = nullptr;
	return 0;
}

void tchCou5(Classroom* c, Teacher* t) 
{
	int op = 1;
	while (op != 0) 
	{
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Add a new course.\n";
		cout << "2: Print all your course.\n";
		cout << "3: Remove your course.\n";
		cout << "4: Set the time of your course.\n";
		cout << "5: Remove the time of your course.\n";
		cout << "6: Change the time of your course.\n";
		cout << "7: Print all the time of your course.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> op;
		switch (op) 
		{
		case 1:
		{
			string s;
			cout << "Please enter the name of the course: ";
			cin >> s;
			while (!checkInput(s, 99)) {
				cout << "The name you've entered is too large!\nPlease enter the name properly: ";
				cin >> s;
			}
			t->addCourse(s);
			break;
		}
		case 2: 
		{
			if (!t->printCourse()) 
			{
				cout << "You don't have any course yet!\n";
			}
			break;
		}
		case 3: 
		{
			if (!t->printCourse()) 
			{
				cout << "You don't have any course yet!\n";
				break;
			}
			else
			{
				int p = 0;
				cout << "Please enter the serial number of the course you want to remove: ";
				cin >> p;
				if (!t->removeCourse(c, p)) 
				{
					cout << "The number you've entered is invalid!\n";
					break;
				}
			}
			break;
		}
		case 4: 
		{
			int a = 0, stwe = 0, enwe = 0, stti = 0, enti = 0;
			string cl, da;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (c->isClassroomValid(cl)) 
			{
				cout << "Please enter the week when your course begins: ";
				cin >> stwe;
				cout << "Please enter the week when your course ends: ";
				cin >> enwe;
				cout << "Please enter the day of your course(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (c->isDayValid(stwe, da) && c->isDayValid(enwe, da)) 
				{
					cout << "Please enter the start time: \n";
					for (int i = 0; i < 11; i++) {
						cout << i + 1 << ":" << start_time[i] << " ";
						if (i == 6) 
						{
							cout << endl;
						}
					}
					cout << endl;
					cin >> stti;
					cout << "Please enter the end time: \n";
					for (int i = 0; i < 11; i++) {
						cout << i + 1 << ":" << end_time[i] << " ";
						if (i == 6) 
						{
							cout << endl;
						}
					}
					cout << endl;
					cin >> enti;
					int st_ti = stti < enti ? stti : enti;
					int en_ti = stti > enti ? stti : enti;
					if (c->isTimeValid(st_ti, en_ti)) 
					{
						if (!t->printCourse()) 
						{
							cout << "You don't have any course yet!\n";
							break;
						}
						cout << "Please enter the serial number of the course: ";
						cin >> a;
						if (!t->setCourseTime(c, a, cl, stwe, enwe, da, st_ti, en_ti)) 
						{
							cout << "The serial number you've entered is invalid or the classroom you've chosen is occupied!\n";
							break;
						}
						else 
						{
							cout << "You've set the time of the course successfully!\n";
						}
					}
					else 
					{
						cout << "The time you've entered is invalid!\n";
						break;
					}
				}
				else 
				{
					cout << "The date you've entered is invalid!\n";
					break;
				}
			}
			else 
			{
				cout << "The classroom you've entered is invalid!\n";
				break;
			}
			break;
		}
		case 5: 
		{
			int dko;
			cout << "Please enter the serial number of the course: ";
			cin >> dko;
			t->removeCourseTime(c, dko);
		}
		case 6: 
		{
			int a = 0, stwe = 0, enwe = 0, stti = 0, enti = 0;
			string cl, da;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (c->isClassroomValid(cl)) 
			{
				cout << "Please enter the week when your course begins: ";
				cin >> stwe;
				cout << "Please enter the week when your course ends: ";
				cin >> enwe;
				cout << "Please enter the day of your course(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (c->isDayValid(stwe, da) && c->isDayValid(enwe, da)) 
				{
					cout << "Please enter the start time: \n";
					for (int i = 0; i < 11; i++) 
					{
						cout << i + 1 << ":" << start_time[i] << " ";
						if (i == 6) 
						{
							cout << endl;
						}
					}
					cout << endl;
					cin >> stti;
					cout << "Please enter the end time: \n";
					for (int i = 0; i < 11; i++) 
					{
						cout << i + 1 << ":" << end_time[i] << " ";
						if (i == 6) 
						{
							cout << endl;
						}
					}
					cout << endl;
					cin >> enti;
					int st_ti = stti < enti ? stti : enti;
					int en_ti = stti > enti ? stti : enti;
					if (c->isTimeValid(st_ti, en_ti)) 
					{
						if (!t->printCourse()) 
						{
							cout << "You don't have any course yet!\n";
							break;
						}
						cout << "Please enter the serial number of the course: ";
						cin >> a;
						if (!t->changeCourseTime(c, a, cl, stwe, enwe, da, st_ti, en_ti)) 
						{
							cout << "The serial number you've entered is invalid or the classroom you've chosen is occupied!\n";
							break;
						}
						else
						{
							cout << "You've change the time of the course successfully!\n";
						}
					}
					else 
					{
						cout << "The time you've entered is invalid!\n";
						break;
					}
				}
				else 
				{
					cout << "The date you've entered is invalid!\n";
					break;
				}
			}
			else 
			{
				cout << "The classroom you've entered is invalid!\n";
				break;
			}
			break;
		}
		case 7:
		{
			if (!t->printCourseTime()) 
			{
				cout << "You haven't set the time of the course yet!\n";
			}
			break;
		}
		}
	}
	return;
}

void tchCla5(Teacher* s, Classroom* c) 
{
	int joi = 1;
	while (joi != 0)
	{
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Print all the classroom table.\n";
		cout << "2: Print all the empty classroom table.\n";
		cout << "3: Print the classroom table of all week.\n";
		cout << "4: Print the classroom table of a week.\n";
		cout << "5: Print the classroom table of a building.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> joi;
		switch (joi) 
		{
		case 1:
		{
			int we = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da)) 
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else 
			{
				s->printAllCl(c, we, da);
			}
			break;
		}
		case 2: 
		{
			int we = 0, st = 0, en = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da))
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the start time: \n";
				for (int i = 0; i < 11; i++)
				{
					cout << i + 1 << ":" << start_time[i] << " ";
					if (i == 6) 
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> st;
				cout << "Please enter the end time: \n";
				for (int i = 0; i < 11; i++) 
				{
					cout << i + 1 << ":" << end_time[i] << " ";
					if (i == 6) 
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> en;
				if (!c->isTimeValid(st, en))
				{
					cout << "The time you've entered is invalid!\n";
					break;
				}
				else 
				{
					s->printAllEmptyCl(c, we, da, st, en);
				}
			}
			break;
		}
		case 3: 
		{
			string cl, da;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl))
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (!c->isDayValid(7, da)) 
				{
					cout << "The date you've entered is invalid!\n";
					break;
				}
				else {
					s->printClAllWeek(c, cl, da);
				}
			}
			break;
		}
		case 4: 
		{
			string cl;
			int we = 0;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl)) 
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the week: ";
				cin >> we;
				if (we >= 1 && we <= 18) {
					s->printClPerWeek(c, cl, we);
				}
				else 
				{
					cout << "The week you've entereed is invalid!\n";
					break;
				}
			}
			break;
		}
		case 5:
		{
			string bu, da;
			int we = 0;
			cout << "Please enter the building number: ";
			cin >> bu;
			if (bu.size() == 2 && bu.at(0) == 'A' && bu.at(1) >= '1' && bu.at(1) <= '5') 
			{
				cout << "Please enter the week: ";
				cin >> we;
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (c->isDayValid(we, da))
				{
					s->printClPerBuilding(c, bu, we, da);
				}
				else 
				{
					cout << "The date you've entereed is invalid!\n";
					break;
				}
			}
			else 
			{
				cout << "The building number you've entered is invalid!\n";
				break;
			}
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			break;
		}
		}
	}
	return;
}

void stuOrd5(Student* s, Classroom* c) 
{
	int ab = 1;
	while (ab != 0) 
	{
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Add a new order.\n";
		cout << "2: Print your existing order.\n";
		cout << "3: Remove your order.\n";
		cout << "4: Remove all your rejected order.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> ab;
		switch (ab) 
		{
		case 1:
		{
			stuAddOrd6(s, c);
			break;
		}
		case 2: 
		{
			if (!s->printOrder()) 
			{
				cout << "You haven't any order yet!\n";
			}
			break;
		}
		case 3: 
		{
			stuRemOrd6(s);
			break;
		}

		case 4: {
			if (!s->printOrder()) 
			{
				cout << "You haven't any order yet!\n";
			}
			break;
			if (!s->removeAllRejectedOrder()) 
			{
				cout << "You haven't any rejected order yet!\n";
			}
			break;
		}
		case 0: 
		{
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return;
}

void stuCla5(Student* s, Classroom* c) 
{
	int joi = 1;
	while (joi != 0) 
	{
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Print all the classroom table.\n";
		cout << "2: Print all the empty classroom table.\n";
		cout << "3: Print the classroom table of all week.\n";
		cout << "4: Print the classroom table of a week.\n";
		cout << "5: Print the classroom table of a building.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> joi;
		switch (joi) 
		{
		case 1:
		{
			int we = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da)) 
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else
			{
				s->printAllCl(c, we, da);
			}
			break;
		}
		case 2:
		{
			int we = 0, st = 0, en = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da)) 
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the start time: \n";
				for (int i = 0; i < 11; i++) 
				{
					cout << i + 1 << ":" << start_time[i] << " ";
					if (i == 6) 
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> st;
				cout << "Please enter the end time: \n";
				for (int i = 0; i < 11; i++) 
				{
					cout << i + 1 << ":" << end_time[i] << " ";
					if (i == 6) 
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> en;
				if (!c->isTimeValid(st, en)) 
				{
					cout << "The time you've entered is invalid!\n";
					break;
				}
				else 
				{
					s->printAllEmptyCl(c, we, da, st, en);
				}
			}
			break;
		}
		case 3:
		{
			string cl, da;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl)) 
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (!c->isDayValid(7, da))
				{
					cout << "The date you've entered is invalid!\n";
					break;
				}
				else 
				{
					s->printClAllWeek(c, cl, da);
				}
			}
			break;
		}
		case 4: 
		{
			string cl;
			int we = 0;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl)) 
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the week: ";
				cin >> we;
				if (we >= 1 && we <= 18) 
				{
					s->printClPerWeek(c, cl, we);
				}
				else 
				{
					cout << "The week you've entereed is invalid!\n";
					break;
				}
			}
			break;
		}
		case 5: 
		{
			string bu, da;
			int we = 0;
			cout << "Please enter the building number: ";
			cin >> bu;
			if (bu.size() == 2 && bu.at(0) == 'A' && bu.at(1) >= '1' && bu.at(1) <= '5') 
			{
				cout << "Please enter the week: ";
				cin >> we;
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (c->isDayValid(we, da)) 
				{
					s->printClPerBuilding(c, bu, we, da);
				}
				else 
				{
					cout << "The date you've entereed is invalid!\n";
					break;
				}
			}
			else 
			{
				cout << "The building number you've entered is invalid!\n";
				break;
			}
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return;
}

void stuAddOrd6(Student* s, Classroom* c) 
{
	string cl, da, re;
	int we = 0, st = 0, en = 0;
	cout << "Please enter the classroom you want to use: ";
	cin >> cl;
	if (!c->isClassroomValid(cl)) 
	{
		cout << "The classroom you've entered is invalid!\n";
		return;
	}
	else 
	{
		cout << "Please enter the week when you want to use: ";
		cin >> we;
		cout << "Please enter the day when you want to use(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): ";
		cin >> da;
		if (!c->isDayValid(we, da))
		{
			cout << "The date you've entered is invalid!\n";
			return;
		}
		else
		{
			cout<< "Please enter the start time when you want to use: \n";
			for (int i = 0; i < 11; i++) 
			{
				cout << i + 1 << ":" << start_time[i] << " ";
				if (i == 6) 
				{
					cout << endl;
				}
			}
			cout << endl;
			cin >> st;
			cout<< "Please enter the end time when you want to use: \n";
			for (int i = 0; i < 11; i++) 
			{
				cout << i + 1 << ":" << end_time[i] << " ";
				if (i == 6) 
				{
					cout << endl;
				}
			}
			cout << endl;
			cin >> en;
			if (!c->isTimeValid(st, en)) 
			{
				cout << "The time you've entered is invalid!\n";
				return;
			}
			else if (!c->isClassroomEmpty(cl,we,da,st,en))
			{
				cout << "The classroom you've chosen is occupied!\n";
				return;
			}
			else 
			{
				cout << "Please enter the remark of your order: \n";
				cin >> re;
				while (!checkInput(re, 999)) 
				{
					cout << "The remark you've entered is too large!\nPlease enter the remark properly: \n";
					cin >> re;
				}
				s->addOrder(cl, we, da, st, en, re);
			}
		}
	}
	return;
}

void stuRemOrd6(Student* s) 
{
	if (!s->printOrder()) 
	{
		cout << "You haven't any order yet!\n";
		return;
	}
	else
	{
		int ehiadsods = 1;
		while (ehiadsods != 0) 
		{
			cout << "Please enter the serial number of the order you want to remove(Enter 0 to exit): ";
			cin >> ehiadsods;
			if (s->removeOrder(ehiadsods)) 
			{
				cout << "You've remove the order successfully!\n";
			}
			else 
			{
				cout << "The number you've entered is invalid!\n";
			}
		}
	}
	return;
}

void admLogin2()
{
	string s;
	Admin* adm = new Admin();
	while (s != "0") 
	{
		cout << "Please enter the password(enter 0 to exit): ";
		cin >> s;
		if (s == adm->getAdminPassword()) 
		{
			cout << "\n\nWelcome,administrator!\n";
			admMain3(adm);
		}
		else
		{
			cout << "The password you've netered is invalid!\nPlease enter the correct password(enter 0 to exit): \n";
			cin >> s;
		}
	}
	delete adm;
	adm = nullptr;
	return;
}

void admMain3(Admin* a) 
{
	int po = 1;
	Classroom* c = new Classroom();
	while (po != 0)
	{
		cout << "Please enter an integer to choose the operation you want: \n";
		cout << "1: Print a student's order.\n";
		cout << "2: Accept or reject the order of a student.\n";
		cout << "3: Print a teacher's course.\n";
		cout << "4: Print a teacher's course and time.\n";
		cout << "5: Set a warning to a student.\n";
		cout << "6: Show the classroom table.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> po;
		switch (po) 
		{
		case 1:
		{
			string id;
			cout << "Please enter a student ID: ";
			cin >> id;
			if (!a->checkOrder(id))
			{
				cout << "The student ID you've entered is invalid!\n";
			}
			break;
		}
		case 2:
		{
			char i = '0';
			int sn = 0;
			string id;
			cout << "Please enter a student ID: ";
			cin >> id;
			if (!a->checkOrder(id)) 
			{
				cout << "The student ID you've entered is invalid!\n";
				break;
			}
			else
			{
				cout<< "Please enter the serial number of the order: ";
				cin >> sn;
				cout << "Please enter 1 to accept the order or 2 to reject the order: ";
				cin >> i;
				if (a->changeOrder(c, id, sn, i)) 
				{
					cout << "You've change the order state successfully!\n";
				}
				else 
				{
					cout << "The serial number of the order you've entered is invalid!\n";
				}
			}
			break;
		}
		case 3: 
		{
			string id;
			cout << "Please enter a teacher ID: ";
			cin >> id;
			if (!a->checkCourse(id)) 
			{
				cout << "The teacher ID you've entered is invalid!\n";
			}
			break;
		}
		case 4:
		{
			string id;
			cout << "Please enter a teacher ID: ";
			cin >> id;
			if (!a->checkCourseTime(id))
			{
				cout << "The teacher ID you've entered is invalid!\n";
			}
			break;
		}
		case 5:
		{
			string id;
			cout << "Please enter a student ID: ";
			cin >> id;
			ifstream file;
			file.open("student.txt", ios::in);
			string s;
			if (file.is_open()) 
			{
				while (getline(file, s)) 
				{
					if (s.find(id) != string::npos)
					{
						int we = 0, st = 0, en = 0;
						string cl, re, da;
						cout << "Please enter the classroom: ";
						cin >> cl;
						if (c->isClassroomValid(cl))
						{
							cout << "Please enter the week: ";
							cin >> we;
							cout<< "Please enter the day (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
							cin >> da;
							if (c->isDayValid(we, da)) 
							{
								cout << "Please enter the beginning time: ";
								cin >> st;
								cout << "Please enter the beginning time: ";
								cin >> en;
								int st0 = st < en ? st : en;
								int en0 = st > en ? st : en;
								if (c->isTimeValid(st, en))
								{
									cout << "Please enter the remark: \n";
									cin >> re;
									while (!checkInput(re, 999)) 
									{
										cout << "The remark is too large!\nPlease enter a correct remark again: \n";
										cin >> re;
									}
									if (checkInput(re, 999))
									{
										a->setWarning(id, cl, we, da, st0, en0, re);
									}
								}
								else 
								{
									cout << "The time you've entered is invalid!\n";
									file.close();
									break;
								}
							}
							else 
							{
								cout << "The date you've entered is invalid!\n";
								file.close();
								break;
							}
						}
						else 
						{
							cout << "The classroom you've entered is invalid!\n";
							file.close();
							break;
						}
					}
				}
			}
			else
			{
				cout << "The file\"S" << id << ".txt\" is lost!\n";
				exit(EXIT_FAILURE);
			}
			file.close();
			break;
		}
		case 6:
		{
			admCla4(c, a);
			break;
		}
		case 0:
		{
			break;
		}
		default: 
		{
			break;
		}
		}
	}
	delete c;
	c = nullptr;
	return;
}

void admCla4(Classroom* c, Admin* s)
{
	int joi = 1;
	while (joi != 0)
	{
		cout << "\n\nPlease enter an integer to choose the operation you want : \n";
		cout << "1: Print all the classroom table.\n";
		cout << "2: Print all the empty classroom table.\n";
		cout << "3: Print the classroom table of all week.\n";
		cout << "4: Print the classroom table of a week.\n";
		cout << "5: Print the classroom table of a building.\n";
		cout << "0: Return to the previous menu.\n";
		cin >> joi;
		switch (joi)
		{
		case 1: 
		{
			int we = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da))
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else 
			{
				s->printAllCl(c, we, da);
			}
			break;
		}
		case 2: 
		{
			int we = 0, st = 0, en = 0;
			string da;
			cout << "Please enter the week: ";
			cin >> we;
			cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
			cin >> da;
			if (!c->isDayValid(we, da)) 
			{
				cout << "The date You've entered is invalid!\n";
				break;
			}
			else
			{
				cout << "Please enter the start time: \n";
				for (int i = 0; i < 11; i++) 
				{
					cout << i + 1 << ":" << start_time[i] << " ";
					if (i == 6) 
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> st;
				cout << "Please enter the end time: \n";
				for (int i = 0; i < 11; i++) 
				{
					cout << i + 1 << ":" << end_time[i] << " ";
					if (i == 6)
					{
						cout << endl;
					}
				}
				cout << endl;
				cin >> en;
				if (!c->isTimeValid(st, en)) 
				{
					cout << "The time you've entered is invalid!\n";
					break;
				}
				else 
				{
					s->printAllEmptyCl(c, we, da, st, en);
				}
			}
			break;
		}
		case 3:
		{
			string cl, da;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl))
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else 
			{
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (!c->isDayValid(7, da))
				{
					cout << "The date you've entered is invalid!\n";
					break;
				}
				else
				{
					s->printClAllWeek(c, cl, da);
				}
			}
			break;
		}
		case 4:
		{
			string cl;
			int we = 0;
			cout << "Please enter the classroom: ";
			cin >> cl;
			if (!c->isClassroomValid(cl))
			{
				cout << "The classroom you've entereed is invalid!\n";
				break;
			}
			else
			{
				cout << "Please enter the week: ";
				cin >> we;
				if (we >= 1 && we <= 18) 
				{
					s->printClPerWeek(c, cl, we);
				}
				else 
				{
					cout << "The week you've entereed is invalid!\n";
					break;
				}
			}
			break;
		}
		case 5: 
		{
			string bu, da;
			int we = 0;
			cout << "Please enter the building number: ";
			cin >> bu;
			if (bu.size() == 2 && bu.at(0) == 'A' && bu.at(1) >= '1' && bu.at(1) <= '5')
			{
				cout << "Please enter the week: ";
				cin >> we;
				cout << "Please enter the day(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday): \n";
				cin >> da;
				if (c->isDayValid(we, da)) 
				{
					s->printClPerBuilding(c, bu, we, da);
				}
				else 
				{
					cout << "The date you've entereed is invalid!\n";
					break;
				}
			}
			else 
			{
				cout << "The building number you've entered is invalid!\n";
				break;
			}
			break;
		}
		case 0: 
		{
			break;
		}
		default: 
		{
			break;
		}
		}
	}
	return;
}