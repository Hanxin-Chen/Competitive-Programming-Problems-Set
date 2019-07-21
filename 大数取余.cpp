#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cctype>
#include<sstream>
#define N 2020
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	string s;
	while (cin >> s >> n)
	{
		int t = 0;
		for (int i = 0; i < s.length(); i++)
		{
			t = t * 10 + s[i] - '0';
			t = t % n;
		}
		cout << t << endl;
	}
	return 0;
}