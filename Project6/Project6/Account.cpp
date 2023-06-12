#include<string>
#include"Account.h"
using namespace std;

string Account::setSerialNumber(string a) 
{
	int b = a.size();
	string c;
	if (b >= 1 && b <= 9) {
		c = "0" + to_string(b);
	}
	else c = to_string(b);
	return c;
}