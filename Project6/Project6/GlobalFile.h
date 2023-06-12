#pragma once
#ifndef GLOBALFILE_H
#define GLOBALFILE_H

#ifndef STUDENT_TXT
#define STUDENT_TXT
#endif

#ifndef TEACHER_TXT
#define TEACHER_TXT
#endif

#ifndef ADMIN_TXT
#define ADMIN_TXT
#endif

#ifndef CLASSROOM_TXT
#define CLASSROOM_TXT
#endif

#include<string>
using namespace std;

const string weekday[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
const string start_time[11] = { "8:50","9:40","10:40","11:30","14:00","14:50","15:45","16:35","19:00","19:55","20:50" };
const string end_time[11] = { "9:35","10:25","11:25","12:15","14:45","15:35","16:30","17:20","19:45","20:40","21:35" };
const string order_state[3] = { "Under review","Accepted","Rejected" };

#endif