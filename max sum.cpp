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
int maxseg(int a[], int left, int right)
{
	int mid = (left + right) >> 1;
	int ret, max1, max2;
	if (left == right)
		return a[left];
	max1 = maxseg(a, left, mid);
	max2 = maxseg(a, mid + 1, right);
	ret = max(max1, max2);
	int tmp1, tmp2, ret1, ret2;
	tmp1 = ret1 = a[mid];
	for (int i = mid; i >= left; i--)
	{
		if (i != mid)
			tmp1 += a[i];
		if (tmp1 > ret1)
			ret1 = tmp1;
	}
	tmp2 = ret2 = a[mid + 1];
	for (int i = mid + 1; i <= right; i++)
	{
		if (i != mid + 1)
			tmp2 += a[i];
		if (tmp2 > ret2)
			ret2 = tmp2;
	}
	ret = max(ret, ret1 + ret2);
	return ret;
}
int a[100002];
__int64 sum[100002];
int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		cout << "Case " << ++cnt << ":" << endl;
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			sum[i + 1] = sum[i] + a[i];

		}
		int ans = maxseg(a, 0, n - 1);
		cout << ans << " ";
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++)
		{
			int flag = 0;
			for (int j = 0; j < i; j++)
			{
				if (sum[i] - sum[j] == ans)
				{
					x = i;
					y = j + 1;
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		cout << y << " " << x << endl;
		if (t)
			cout << endl;
	}
	return 0;
}