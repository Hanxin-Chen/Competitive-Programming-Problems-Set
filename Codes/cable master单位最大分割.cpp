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
#define N 10005
using namespace std;
double s[N];
double find(double left, double right, int n, int k)
{
	double mid = (left + right) / 2;
	if (right - left <= 10e-6)
		return mid;
	int cnt = 0;

	for (int i = 0;i < n;i++)
		cnt += floor(s[i] / mid);
	if (cnt >= k)
		return find(mid, right, n, k);
	else
		return find(left, mid, n, k);
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	double t;
	while (cin >> n >> k && (n != 0 || k != 0))
	{
		double smax = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			if (smax < s[i])
				smax = s[i];
		}
		double left = 0.01, right = smax + 0.01;
		double ans = find(left, right, n, k);
		if (ans < 0.01)
		{
			printf("0.00\n");
			continue;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}

