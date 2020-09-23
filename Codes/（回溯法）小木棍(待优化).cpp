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
#define N 65
int a[N], vis[N];
int n, len, num;
int s = 0;
int rest;
int dfs(int k, int cur_len, int st)
{
	int pre = 0;
	if (k >= num - 1)
	{
		
		return 1;
	}
	for (int i = st;i < n;i++)
	{
		if (!vis[i] && a[i]!=pre) 
		{
			pre = 0;
			if (cur_len + a[i] == len)
			{
				vis[i] = 1;
				rest -= a[i];
				if (dfs(k + 1, 0, 0))
					return 1;
				vis[i] = 0;
				rest += a[i];
			}
			else if (cur_len + a[i] < len)
			{
				vis[i] = 1;
				rest -= a[i];
				if (dfs(k, cur_len + a[i], i + 1))
					return 1;
				if (cur_len + rest < len)          //不取a[i]，剩余的木棍总长与当前木棍的长度之和达不到len
					break;
				rest += a[i];
				vis[i] = 0;
			}
			else if (cur_len + a[n - 1] > len)      //弱剪枝
				break;
		}
		pre = a[i];     //强剪枝
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n,greater<int>());
	for (int i = a[0];i <= s;i++)
	{
		rest = s;
		if (s%i == 0)
		{
			len = i;      //小木棍的长度
			num = s / i;  //小木棍的根数
			memset(vis, 0, sizeof(vis));
			if (dfs(1, 0, 0))
			{
				cout << "YES" << endl;
			}
		}
		
	}
	return 0;
}
