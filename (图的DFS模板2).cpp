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
#define N 1005
#define inf 1<<30
vector<int>g[N];
int n, m; //n:the point number; m: the number of edges
int vis[N],dfs_num[N];
int cnt = 1;
int dis[N];

void dfs(int cur)
{
	int k;
	vis[cur] = 1;    //不需要还原
	dfs_num[cur] = cnt++;
	for (int i = 0;i < g[cur].size();i++) 
	{
		k = g[cur][i];   // the point next to cur
		
		if (!vis[k]) 
		{
			for (int j = 0; j < g[k].size(); j++)
			{
				dis[k] = min(dis[k], dis[g[k][j]] + 1);
			}
			dfs(k);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);      //x is near by y;
		g[y].push_back(x);		//y is near by x;
	}
	for (int i = 0; i <=m ; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;
	dfs(1);
	return 0;
}
