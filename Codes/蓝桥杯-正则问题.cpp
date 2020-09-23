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
string str;
int p = 0;
int fun() {
	int a = 0, b = 0;
	while (p < str.size())
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	cout << fun();
	return 0;
}
