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
#define N 1005
int n, m, u,v;
int edge[N][2];
struct node {
	int data;
	int parent;   //父节点
	int rank;
}uf[N];

int find(int x)     //while循环方式*****防止爆栈
{
	int k = x,k1=x;
	while (k != uf[k].parent)
	{
		k = uf[k].parent;
	}
	while (x!=uf[x].parent)
	{
		k1 = uf[x].parent;
		uf[x].parent = k;
		x = k1;
	}
	return x;
}


void Union(int x, int y)    //优化rank版本
{
	x = find(x), y = find(y);
	if (x != y)
	{
		if (uf[x].rank < uf[y].rank)
		{
			uf[x].parent = y;
		}
		else
		{
			uf[y].parent = x;
			if (uf[x].rank == uf[y].rank)
				uf[x].rank++;            //维护高度
		}
	}
}
void ini()
{
	for (int  i = 1; i <= n; i++)     //初始化
		{
			uf[i].parent = i;
		}
}
int main()
{
	int x, y;
	cin >> n >> m ;
	for (int i = 0; i < m; i++)   //联通关系
	{
		
		cin >> x >> y;
		edge[i][0] = x;
		edge[i][1] = y;
		Union(x, y);
	}
	cin >> u >> v;
	if (find(u) != find(v))
	{
		cout << "-1" << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		ini();
		if (i == u || i == v)
			continue;
		for (int j = 0;j < m;j++)
		{
			if (edge[j][0] != i || edge[j][1] != i)
				Union(edge[j][0], edge[j][1]);
		}
		if (find(u) != find(v))
			ans++;
	}
	
	
	return 0;
}
