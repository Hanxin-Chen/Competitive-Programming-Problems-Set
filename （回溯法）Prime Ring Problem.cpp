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
#define N 25
int n;
int ans[N], vis[N];
bool isprime(int x)
{
	if (!(x & 1) && x != 2)
		return false;
	else if (x == 2)
		return true;
	for (int i = 3;i*i <= x;i += 2)
		if (x % i == 0)
			return false;
	return true;
}


bool judge(int x,int y)  //ans[y]为之前一个元素，x为当前元素
{
	int ret = x + ans[y];
	if (y == n - 2)
		if (!isprime(x + 1))
			return false;
	if (isprime(ret))
		return true;
	else
		return false;

}

void dfs(int dep)
{
	int i;
	if (dep >= n) {
		for (int j = 0;j < n;j++)
		{
			cout << ans[j];
			if (j != n - 1)
				cout << " ";
		}
		cout << endl;
		return;
	}
	for (i = 2;i <= n;i++)
	{
		if (!vis[i] && judge(i,dep-1))
		{
			ans[dep] = i;
			vis[i] = 1;
			dfs(dep + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t = 1;
	while (cin>>n)
	{
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		cout << "Case " << t++ << ":" << endl;
		if (n == 1)
		{
			cout << "1" << endl;
			continue;
		}
		dfs(1);
		
		cout << endl;
	}
	return 0;
}
