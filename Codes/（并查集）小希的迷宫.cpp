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
#define N 100005
int m, n;
set<int> mst;
set<int>::iterator it;
struct node 
{
	int data;
	int parent;   
	int rank;
	node() :rank(1) {}
}uf[N];



int find(int x)     
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


void Union(int x, int y)    
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
				uf[x].rank++;           
		}
	}
}
void ini()
{
	for (int i = 1; i <= N; i++)     
	{
		uf[i].parent = i;
	}
}

int findthecase()
{
	int ans = 0;
	for ( it = mst.begin();it != mst.end();it++)
		if (find(*it) == *it)
			ans++;
	return ans;
}
int main()
{
	
	int a, b, flag, sum;
	while (1)
	{
		flag = 0;
		ini();
		mst.clear();
		while (cin>>a>>b && a != 0 && b != 0)
		{
			if (a == -1 && b == -1)return 0;
			if (a!=b && find(a) == find(b))
				flag = 1;
			Union(a, b);
			mst.insert(a);
			mst.insert(b);           //房间不是按照从1-N 排序的
		}
		sum = findthecase();
		if ( sum > 1 || flag == 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
}
