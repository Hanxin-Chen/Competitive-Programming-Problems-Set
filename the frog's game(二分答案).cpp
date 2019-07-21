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
#define N 500005
int l,n,m;
int dis[N];
bool judge(int x)
{
	int pos = 0,ans=0;
	for (int i = 0;i < n+1;)
	{
		pos = i;
		for (int j = i+1;j <= n + 1 && dis[j] - dis[i] <= x;j++)
			pos = j;
		if (pos == i)
			return false;
		ans++;
		i = pos;
	}
	return ans <= m ? true : false;
}

int solve(int left, int right)
{
	int mid;
	while (left<=right)
	{
		mid = (left + right) >> 1;
		if (judge(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;     //一定要注意返回值****(第一遍错因：返回mid)
}

int main()
{
	while (cin>>l>>n>>m)
	{
		for (int i = 1; i <= n; i++)
			cin >> dis[i];
		sort(dis, dis + n+1);
		dis[n+1] = l;
		int ans = solve(0, l);
		cout << ans << endl;
	}
	return 0;
}
