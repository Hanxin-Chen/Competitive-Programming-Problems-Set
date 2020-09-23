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
#include <stack>
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
string str;
int p=0;
int fun() {
	int a = 0, b = 0;
	while (p<str.size())
	{
		if (str[p] == 'x') {
			b++;
			p++;
		}
		else if (str[p] == '|') {
			p++;
			a = max(a, b);
			b = 0;
		}
		else if (str[p] == '(') {
			p++;
			b += fun();
		}
		else if (str[p] == ')') {
			p++;
			break;
		}
	}
	return max(a, b);
}

stack<int>num;
stack<char>op;

int fun2() {
	int a = 0,b;
	p = 0;
	while (p < str.size())
	{
		if (str[p] == 'x') {
			a++;
			p++;
		}
		else if (str[p] == '|') {
			p++;
			num.push(a);
			a = 0;
			op.push('|');
		}
		else if (str[p] == '(') {
			p++;
			op.push('(');
			if (a != 0) {
				num.push(a);
				a = 0;
			}
		}
		else if (str[p] == ')') {
			p++;
			num.push(a);
			while (op.top()!='(')
			{
				op.pop();
				a = num.top();
				num.pop();
				b = num.top();
				num.pop();
				num.push(max(a, b));
			}
			a = num.top();
			num.pop();
			if (num.empty()) {
				num.push(a);
			}
			else {
				b = num.top();
				num.top();
			}
			num.push(a + b);
			a = 0;
			op.pop();
		}
	}
	if (a)
		num.push(a);
	while (!op.empty())
	{
		op.pop();
		a = num.top();
		num.pop();
		b = num.top();
		num.pop();
		num.push(max(a, b));
	}
	a = num.top();
	num.pop();
	if (num.empty()) {
		num.push(a);
	}
	else {
		b = num.top();
		num.top();
	}
	num.push(a + b);
	return num.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	cout << fun2();
	return 0;
}
