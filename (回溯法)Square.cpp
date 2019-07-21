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
int stick[N], vis[N];
int sum = 0;
int target;
int flag;

void dfs(int num, int len, int st)
{
	if (flag)
		return;
	if (num == 4)
	{
		flag = 1;
		return;
	}
	if (len == target)
	{
		dfs(num + 1, 0, 0);
		if (flag)
			return;
	}
	for (int i = st;i < n;i++)
	{
		if (vis[i] == 0 && len + stick[i] <= target)
		{
			vis[i] = 1;
			dfs(num, len + stick[i], i + 1);
			vis[i] = 0;
		}
		if (flag)
			return;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(stick, 0, sizeof(stick));
		memset(vis, 0, sizeof(vis));
		sum = 0;
		flag = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> stick[i];
			sum += stick[i];
		}
		sort(stick, stick + n);
		if (sum % 4 != 0)
		{
			cout << "no" << endl;
			continue;
		}
		target = sum / 4;
		if (stick[n - 1] > target)
		{
			cout << "no" << endl;
			continue;
		}
		dfs(0, 0, 0);
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	return 0;
}