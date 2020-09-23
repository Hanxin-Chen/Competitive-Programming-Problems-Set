#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 110
#define mod 1000000007
long long c[N][N];
int a[N];
long long dp[N][N];
void init()
{
	for (int i = 1; i <= 100; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)         //组合公式C(i,j)= C(i-1,j-1) + C(i-1,j);
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
}
//状态转移方程：dp[i][j]=(dp[i][j]+dp[i][k-1]*dp[k+1][j]*c[j-i][k-i])
int main()
{
	int n;
	init();
	while (~scanf_s("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf_s("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;
		for (int i = 0; i < n - 1; i++)
			dp[i][i + 1] = 2;
		for (int len = 2; len < n; len++)
			for (int i = 0; i + len < n; i++)
			{
				int j = i + len;
				dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
				for (int k = i + 1; k < j; k++)
					if (a[k - 1] == a[k + 1])
						dp[i][j] = (dp[i][j] + dp[i][k - 1] * dp[k + 1][j] % mod*c[j - i][k - i] % mod) % mod;
			}
		printf("%lld\n", dp[0][n - 1]);
	}
	return 0;
}