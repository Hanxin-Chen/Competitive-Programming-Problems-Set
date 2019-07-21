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
#define	N 100
int n;

int vis[N],dis[N],dis1[N];
vector<int>g[N];

int main()
{
	cin >> n;
	int from, to;
	int cur, now;
	queue<int> qu;
	for (int i = 1; i < n; i++)
	{
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	dis[1] = 0;
	vis[1] = 1;
	qu.push(1); 

	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			now = g[cur][i];
			if (vis[now])
				continue;
			vis[now] = 1;
			dis[now] = dis[cur] + 1;
			qu.push(now);
		}
		
	}
	memset(vis, 0, sizeof(vis));
	dis1[n] = 0;
	vis[n] = 1;
	qu.push(n);
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			now = g[cur][i];
			if (vis[now])
				continue;
			vis[now] = 1;
			dis1[now] = dis1[cur] + 1;
			qu.push(now);
		}

	}
	int num1 = 0, num2 = 0;
	for (int i = 2; i < n; i++)
	{
		if (dis[i] <= dis1[i])
			num1++;
		else
			num2++;
	}
	if (num1 > num2)
		cout << "Fennec" << endl;
	else
		cout << "Snuke" << endl;
	return 0;
}