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
#define N 8
int a[N][N];
int n, m, q;
int ans;

bool judge(int x, int y)
{
	int flag1 = 0;
	for (int i = x - 1;i >= 0;i--)
	{
		if (a[i][y] != 0)
			flag1++;
		if (flag1-1==1 && a[i][y] == 2)
			return false;
	}
	flag1 = 0;
	for (int i = y - 1;i >= 0;i--)
	{
		if (a[x][i] != 0)
			flag1++;
		if (flag1-1==1 && a[x][i] == 2)
			return false;
	}
	return true;
}

void dfs(int dep,int num)
{
	if (dep >= n*m)
	{
		if (ans < num)
			ans = num;
		return;
	}
	int x = dep / m;
	int y = dep % m;
	if (a[x][y] == 0 && judge(x, y))
	{
		a[x][y] = 2;
		dfs(dep + 1, num + 1);
		a[x][y] = 0;
	}
	dfs(dep + 1, num);
}

int main()
{
	ios::sync_with_stdio(false);
	int x, y;
	while (cin>>n>>m>>q)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0;i < q;i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
		}
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	
	return 0;
}