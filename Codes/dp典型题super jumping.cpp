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
#define N 1005
using namespace std;
int m,n;
int dp[N], a[N];
int main()
{
	while (cin>>n,n)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			dp[i] = a[i];
		}
		for (int i = 1;i < n;i++)
		{
			m = 0;
			for (int j = 0; j < i; j++)
			{
				if (a[j] < a[i] && m < dp[j])
					m = dp[j];
			}
			dp[i] += m;
		}
		sort(dp, dp + n);
		cout << dp[n - 1] << endl;
	}
	return 0;
}