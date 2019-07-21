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
	int n;
	map<string, int>ma;
	string color;
	while (cin>>n,n)
	{
		int m = 0;
		ma.clear();
		for (int i = 0;i < n;i++)
		{
			cin >> color;
			ma[color]++;
			m = MAX(m, ma[color]);
		}
		map<string, int>::iterator it;
		for (it = ma.begin();it != ma.end();it++)
		{
			if (it->second == m)
			{
				cout << it->first << endl;
				break;
			}
		}
		
	}
	return 0;
}


