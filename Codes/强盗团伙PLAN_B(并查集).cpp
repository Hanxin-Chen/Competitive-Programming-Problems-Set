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
#define N 1000
#define M 100005
int n, m, u, v;
struct node {
	int data;
	int parent;   //父节点
	int rank;
	node() :rank(1) {
	}
}uf[N*2];

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
	for (int i = 1; i <= n*2; i++)     //初始化
	{
		uf[i].parent = i;
	}
}

int root[N];
int main()
{
	int x, y, t;
	char ch;
	cin >> n >> m;
	ini();
	for (int i = 0; i < m; i++)   //联通关系
	{
		cin >> ch >> x >> y;
		if (ch = 'F')
			Union(x, y);
		else
		{
			Union(x + n, y);
			Union(x, y + n);
		}
	}
	int k;
	for (int i = 1;i <= n;i++)
	{
		k = find(i);
		root[i] = k;
	}
	sort(root+1, root + n+1);
	cout << (unique(root + 1, root + n + 1) - root-1) << endl;
	return 0;
}
