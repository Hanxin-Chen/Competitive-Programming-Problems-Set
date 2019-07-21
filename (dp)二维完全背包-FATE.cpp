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
#include<queue>
using namespace std;
#define N 110
#define inf 1<<30
int dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k, s, value, cost;
	while (cin>>n>>m>>k>>s)
	{
		int MIN = inf;
		memset(dp, 0, sizeof(dp));
		for (int i = 1;i <= k;i++)
		{
			cin >> value >> cost;
			for (int j = cost;j <= m;j++)
			{
				for (int z = 1;z <= s;z++)
				{
					dp[z][j] = max(dp[z][j], dp[z - 1][j - cost] + value);
					if (dp[z][j] >= n && MIN > j)
						MIN = j;
				}
			}
		}
		if (MIN == inf)
			cout << "-1" << endl;
		else
			cout << m - MIN << endl;
	}
	return 0;
}
