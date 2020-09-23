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
#define N 3050
using namespace std;
int n;
__int64 s;
map<__int64, int> ma;
int main()
{
	ios::sync_with_stdio(false);
	while (scanf_s("%d",&n)!=EOF)
	{
		ma.clear();
		for (int i = 0; i < n; i++)
		{
			scanf_s("%I64d", &s);
			ma[s]++;
		}
		int ans = 0;
		map<__int64, int>::iterator it;
		for ( it = ma.begin(); it!=ma.end(); it++)
		{
			if (ans < it->second)
				ans = it->second;
		}
		cout << ans << endl;
	}
	return 0;
}
