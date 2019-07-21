#include <cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>     
#include<map>
#include<iomanip>
#include<cctype>
#include<vector>
#include<set>
#define MAX(x,y) (x>y?x:y)
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s[10];
	int a, b, ans;
	map<string, int>num;
	num["zero"] = 0;
	num["one"] = 1;
	num["two"] = 2;
	num["three"] = 3;
	num["four"] = 4;
	num["five"] = 5;
	num["six"] = 6;
	num["seven"] = 7;
	num["eight"] = 8;
	num["nine"] = 9;
	while (cin >> s[0])
	{
		a = 0;b = 0;ans = 0;
		int i = 1;
		for (i = 1;i < 10;i++)
		{
			cin >> s[i];
			if (s[i] == "=")
				break;
		}
		if (s[0] == "zero"&&s[2] == "zero")
			break;
		a = num[s[0]];
		b = num[s[i - 1]];
		if (s[1] != "+")
			a = 10 * a + num[s[1]];
		if (s[i - 2] != "+")
			b = b + 10 * num[s[i - 2]];
		ans = a + b;
		cout << ans << endl;
	}

	return 0;
}


