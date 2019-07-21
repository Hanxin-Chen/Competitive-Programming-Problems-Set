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
using namespace std;
#define N 50005
int m, n;
int dis[N];
int parent[N];


int find(int x)    
{
	if (parent[x]==-1) 
		return x;
	int fx = parent[x];
	parent[x] = find(parent[x]);     //路径压缩
	dis[x] += dis[fx];              //子节点的距离+=父节点距离
	return parent[x];
}


void Union(int x, int y,int d)
{
	int fx = find(x), fy = find(y);
	if (x != y)
	{
		parent[fy] = fx;
		dis[fy] = dis[x] - dis[y] + d;      //向量相加
	}
}

void ini()
{
	memset(parent, -1, sizeof(parent));
	memset(dis, 0,sizeof( dis));
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b, x;
	while (cin>>n>>m)
	{
		int ans = 0;
		ini();
		for (int i = 0;i < m;i++)
		{
			cin >> a >> b >> x;
			if (find(a) == find(b))
			{
				if (dis[b] - dis[a] != x)
					ans++;
			}
			else
				Union(a, b, x);
		}
		cout << ans << endl;
	}
	return 0;
}
