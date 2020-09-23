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
#define N 100050
long long  m, n, w;
long long  a[N];
long long  b[N];
/*bool judge(long long x)
{
	long long  d = 0, ans = 0;
	for (int i = 0;i < n;i++)
		b[i] = a[i];
	for (int i = 0;i < n;i++)
	{
		if (b[i] >= x)
			continue;
		d = x - b[i];
		for (int j = i;j <= i + w - 1;j++)
			if (j < n)
				b[j] += d;
		ans += d;
	}
	if (ans <= m)
		return true;
	else
		return false;
}*/                              //TLE at codeforces in the test of 20
bool judge(long long mid)
{
	memset(b, 0, sizeof(b));
	long long waternum = 0;
	long long temp = 0;
	for (int i = 0;i < n;i++)
	{
		temp -= (i >= w ? b[i - w] : 0);
		if (mid>a[i] + temp)
		{
			b[i] = mid - temp - a[i];
			temp += b[i];
			waternum += b[i];
		}
	}
	if (waternum>m) return false;
	else return true;
}

long long solve(long long left, long long right)
{
	long long mid;
	long long ans;
	while (left <= right)
	{
		mid = (left + right) >>1;
		if (judge(mid) == true)
		{
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return ans;
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
		long long  amax = 0;
		for (long long i = 0;i < n;i++)
		{
			cin >> a[i];
			amax = max(amax, a[i]);
		}
		amax += m;
		long long ans = solve(0, amax + 1);
		cout << ans << endl;
	}
	return 0;
}
