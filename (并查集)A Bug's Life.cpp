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
#define N 2005
int m, n;
struct node
{
	int data;
	int parent;
	int rank;
	node() :rank(1) {}
}uf[N];

int sex[N];

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
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		cin >> n >> m;
		memset(sex, -1, sizeof(sex));
		ini();
		int a, b;
		cout << "Scenario #" << ++cnt << ":" << endl;
		int flag = 0;
		for (int i = 1;i <= m;i++)
		{
			cin >> a >> b;
			if (!flag)
			{
				if (find(a) == find(b))
					flag = 1;
				if (sex[a] == -1)sex[a] = b;
				else Union(sex[a], b);
				if (sex[b] == -1)sex[b] = a;
				else Union(sex[b], a);
				
			}
		}
		if (flag == 1)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;
		cout << endl;
	}
}
