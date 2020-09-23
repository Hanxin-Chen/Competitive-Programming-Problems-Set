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
using namespace std;
bool cmp(map<string, int>a, map<string, int>b)
{

	return a > b;
}
struct MyStruct
{
	int socre;
	string name;
}source[1002];

int main()
{
	ios::sync_with_stdio(false);
	string name;
	int t;
	while (cin >> t)
	{
		for (int ii = 0;ii < t;ii++)
		{
			int n, a, m = -0xfffffff;
			cin >> n;
			map<string, int>ma;
			set<string>win;
			for (int i = 0;i < n;i++)
			{
				cin >> name;
				cin >> a;
				ma[name] += a;
				source[i].name = name;
				source[i].socre = a;
			}
			map<string, int>::iterator it;
			for (it = ma.begin();it != ma.end();it++)
			{
				if (m < it->second)
				{
					m = it->second;
				}
			}
			for (it = ma.begin();it != ma.end();it++)
			{
				if (m == it->second)
				{
					win.insert(it->first);
				}
			}
			ma.clear();
			for (int i = 0;i < n;i++)
			{
				ma[source[i].name] += source[i].socre;
				if (ma[source[i].name] >= m && win.count(source[i].name))
				{
					cout << source[i].name << endl;
					break;
				}
			}
		}
	}
	return 0;
}


