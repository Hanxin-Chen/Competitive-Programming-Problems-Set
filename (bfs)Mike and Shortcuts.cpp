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
#define	N 200005
int vis[N],dis[N];
vector<int> g[N];
int main()
{
	int to;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> to;
		g[i].push_back(to);
	}
	for (int i = 1; i < n; i++)
	{
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);

	}
	queue<int> qu;
	qu.push(1);
	int cur,now;
	vis[1] = 1;
	dis[1] = 0;
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
	for (int i =1; i <=n; i++)
	{

		if (i != 1)
			cout << " ";
		cout << dis[i];
	}
	cout << endl;
	return 0;
}