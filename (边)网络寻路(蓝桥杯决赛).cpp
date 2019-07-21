
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
#include<queue>
using namespace std;
#define N 100003
vector<int>g[N];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int to, from, ret = 0;
	int now;
	for (int i = 0; i < m; i++)
	{
		cin >> to >> from;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			now = g[i][j];
			ret += (g[i].size() - 1)*(g[now].size() - 1);
		}
	}
	cout << ret << endl;
	return 0;
}
