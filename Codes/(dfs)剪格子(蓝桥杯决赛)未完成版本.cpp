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
#include<queue>
using namespace std;
#define N 12
vector<int> ans;
int m, n, a[N][N];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int sum = 0;
int vis[N][N],vis1[N][N];
int cur = 0;

bool judge(int x, int y)
{
	if (x <= 0 || y <= 0 || x > n || y > m || vis[x][y] == 1)
		return false;
	else
		return true;
}

void dfs1(int x, int y, int cnt2)
{

}

int check(int s)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!vis[i][j])
			{
				memset(vis1, 0, sizeof(vis1));

			}
		}
	}
}

void dfs(int x, int y,int cnt)
{
	int xx, yy;
	if (cur >= sum / 2)
	{
		if (cur == sum / 2 || check(cur)==1)
		{
			if (vis[1][1] == 1)
				ans.push_back(cnt);
			else
				ans.push_back(n*m - cnt);
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		xx = x + dir[i][0];
		yy = y + dir[i][1];
		if (judge(xx, yy) == false)
			continue;
		vis[xx][yy] = 1;
		cnt++;
		cur += a[xx][yy];
		dfs(xx, yy,cnt);
		cur -= a[xx][yy];
		vis[xx][yy] = 0;
		cnt--;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	if (sum % 2)
	{
		cout << "0" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			vis[i][j] = 1;
			cur = a[i][j];
			dfs(i, j,1);
			cur = 0;
			vis[i][j] = 0;
		}
	}
	if (ans.empty())
		cout << "0" << endl;
	else
	{
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}
	
	return 0;
}