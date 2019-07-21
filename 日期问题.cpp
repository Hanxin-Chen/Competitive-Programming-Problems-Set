#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
#include <map>
#include <ctime>
#include <sstream>
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
int months[20] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct node
{
	int year;
	int month;
	int day;
	node() {

	}
	node(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	bool operator == (const node &n1) const {
		if (this->day == n1.day && this->month == n1.month && this->year == n1.year)
			return true;
		return false;
	}
	bool operator <(const node &n1)const {
		if (year < n1.year)
			return true;
		else if (year == n1.year) {
			if (month < n1.month)
				return true;
			else if (month == n1.month) {
				return day < n1.day;
			}
		}
		return false;
	}
};
set<node> sa;
int leapyear(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

bool judge(int yy, int mm, int dd) {
	if (yy > 2059 || yy < 1960)
		return false;
	if (mm < 1 || mm>12)
		return false;
	if (mm != 2) {
		if (dd > months[mm])
			return false;
	}
	else if(dd>months[mm]+leapyear(yy))
		return false;
	return true;
}

void handle(int yy, int mm, int dd) {
	node tmp;
	tmp.year = 1900 +yy;
	tmp.month = mm;
	tmp.day = dd;
	if (judge(1900 + yy, mm, dd))
		sa.insert(tmp);
	tmp.year = 2000 + yy;
	tmp.month = mm;
	tmp.day =dd;
	if (judge(2000 + yy, mm, dd))
		sa.insert(tmp);
}
int main() {
	ios::sync_with_stdio(false);
	int a[3],d,y,m;
	node tmp;
	scanf("%d/%d/%d", &a[0], &a[1], &a[2]);
	handle(a[0], a[1], a[2]);
	handle(a[2], a[1], a[0]);
	handle(a[2], a[0], a[1]);

	for (set<node>::iterator it = sa.begin(); it !=sa.end(); it++)
	{
		tmp = *it;
		y = tmp.year;
		m = tmp.month;
		d = tmp.day;
		cout << y << "-";
		if (m < 10)
			cout << 0;
		cout << m << "-";
		if (d < 10)
			cout << 0;
		cout<< d << endl;
		//printf("%02d", d);
	}
	return 0;
}

