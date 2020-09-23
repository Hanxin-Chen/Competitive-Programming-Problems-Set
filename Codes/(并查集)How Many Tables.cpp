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
int m, n;
struct node 
{
	int data;
	int parent;   
	int rank;
	node() :rank(1) {}
}uf[N];



int find(int x)     //while—≠ª∑∑Ω Ω*****∑¿÷π±¨’ª
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
	for (int i = 1; i <= n; i++)     
	{
		uf[i].parent = i;
	}
}

int findthecase()
{
	int ans = 0;
	for (int i = 1;i <= n;i++)
		if (find(i) == i)
			ans++;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		ini();
		int a, b;
		while (m--)
		{
			cin >> a >> b;
			Union(a, b);
		}
		int ans = findthecase();
		cout << ans << endl;
	}
}
