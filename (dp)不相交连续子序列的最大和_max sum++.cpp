
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
#define N 1000010
#define inf 0x7fffffff
int a[N], pre[N],dp[N];
int  m, n;
int main()
{
	int tp;
	ios::sync_with_stdio(false);
	while (cin>>m>>n)
	{
		memset(pre, 0, sizeof(pre));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++)
		{
			tp = -inf;
			for (int j = i; j <= n; j++)
			{
				dp[j] = max(dp[j - 1] + a[j], pre[j - 1] + a[j]);
				pre[j-1] = tp;
				tp = max(tp, dp[j]);
			}
		}
		cout << tp << endl;
	}
	
	return 0;
}
