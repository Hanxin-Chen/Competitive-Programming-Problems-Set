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
#define N 6
int n;
char a[N][N];
int ans = 0;

bool judge(int x, int y)
{
	for (int i = x - 1;i >= 0 && a[i][y] != 'X';i--)
		if (a[i][y] == '0')
			return false;
	for (int i = y - 1;i >= 0 && a[x][i] != 'X';i--)
		if (a[x][i] == '0')
			return false;
	return true;
}

void dfs(int dep, int num)
{
	int x = dep / n;
	int y = dep % n;
	if (dep >= n * n)
	{
		if (ans < num)
			ans = num;
		return;
	}
	if (a[x][y] == '.' && judge(x, y))
	{
		a[x][y] = '0';
		dfs(dep + 1, num + 1);
		a[x][y] = '.';
	}
	dfs(dep + 1, num);
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n,n)
	{
		memset(a, -1, sizeof(a));
		for(int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				cin >> a[i][j];
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}