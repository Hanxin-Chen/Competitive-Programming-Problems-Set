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
#define N 10005
#define M 100005
int n, m, u, v;
struct node {
	int data;
	int parent;   //父节点
	int rank;
	node() :rank(1) {

	}
}uf[N];

struct node1
{
	int st;
	int ed;
	int time;
	bool operator < (const node1 &n1) const {                  //重载小于号，必须加const
		return time > n1.time;
	}
}edge[M];

int find(int x)     //while循环方式*****防止爆栈
{
	int k = x, k1 = x;
	while (k != uf[k].parent)
	{
		k = uf[k].parent;
	}
	while (x != uf[x].parent)
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
	for (int i = 1; i <= n; i++)     //初始化
	{
		uf[i].parent = i;
	}
}

int main()
{
	int x, y,t;
	cin >> n >> m;
	ini();
	for (int i = 0; i < m; i++)   //联通关系
	{
		cin >> edge[i].st >> edge[i].ed >> edge[i].time;
	}
	sort(edge, edge + m);
	int ans = 0;
	int t1 = -1;
	for (int i = 0;i < m;i++)
	{
		x = edge[i].st;
		y = edge[i].ed;
		t = edge[i].time;
		if (find(x) != find(y))
		{
			if (t != t1)
			{
				ans++;
				t1 = t;
			}
			Union(x, y);
		}
	}
	cout << ans << endl;
	return 0;
}
