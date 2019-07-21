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
#define N 105
int a[N][N], dp[N][N];
int n;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= i;j++)
				cin >> a[i][j];
		dp[1][1] = a[1][1];
		for(int i=2;i<=n;i++)
			for (int j = 1;j <= i;j++)
			{
				dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		int ret = 0;
		for (int i = 1;i <= n;i++)
			if (dp[n][i] > ret)
				ret = dp[n][i];
		cout << ret << endl;
	}
	
	return 0;
}
