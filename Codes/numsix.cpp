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
int m, n, w;
int a[N];
int b[N];
bool judge(int x)
{
	int d = 0, ans = 0;
	for (int i = 0;i < n;i++)
		b[i] = a[i];
	for (int i = 0;i < n;i++)
	{
		if (b[i] >= x)
			continue;
		d = x - b[i];
		for (int j = i;j <= i + w - 1;j++)
			b[j] += d;
		ans += d;
	}
	if (ans <= m)
		return true;
	else
		return false;
}

int solve(int left, int right)
{
	int mid;
	while (left + 1 < right)
	{
		mid = (left + right) >> 1;

		if (judge(mid))
			left = mid;
		else
			right = mid - 1;
	}
	if (judge(right + 2))
		return right + 2;
	else if (judge(right + 1))
		return right + 1;
	else if (judge(right))
		return right;
	else if (judge(right - 1))
		return right - 1;
	else return left;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> w;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int amax = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			amax = max(amax, a[i]);
		}
		amax += m;
		int ans = solve(0, amax + 1);
		cout << ans << endl;
	}
	return 0;
}

