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
#define N 5050
int n, m, p;
struct node {
	int data;
	int parent;   //父节点
	int rank;
}uf[N];

int find1(int x)
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = find1(uf[x].parent);
	return uf[x].parent;
}

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
int main()
{
	int x, y;
	cin >> n >> m >> p;
	for (int  i = 1; i <= n; i++)
	{
		uf[i].parent = i;
	}
	for (int i = 0; i < m; i++)
	{
		
		cin >> x >> y;
		Union(x, y);
	}
	for (int i = 0;i < p;i++)
	{
		cin >> x >> y;
		x = find(x);
		y = find(y);
		if (x == y)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}
