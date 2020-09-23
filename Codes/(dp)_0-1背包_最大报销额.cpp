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
#define N 50
int dp[3000500];
int total[N];
int main()
{
	ios::sync_with_stdio(false);
	int  n, m;
	double q;
	int money;
	double price;
	string type;
	while (cin>>q>>n,n)
	{
		memset(dp, 0, sizeof(dp));
		memset(total, 0, sizeof(total));
		int top = (int)(q * 100);
		
		for (int i = 1;i <= n;i++)
		{
			cin >> m;
			int a = 0, b = 0, c = 0;
			int tag = 0;
			for (int j = 1;j <= m;j++)
			{
				cin >> setw(2) >> type;
				cin >> price;
				money = (int)(price * 100);
				if (type == "A:")
					a += money;
				else if (type == "B:")
					b += money;
				else if (type == "C:")
					c += money;
				else
					tag = 1;
			}

				if (tag == 0 && a <= 60000 && b <= 60000 && c <= 60000 && a + b + c <= 100000)
					total[i] = a + b + c;
				else
					total[i] = top + 1;
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = top;j >= total[i];j--)
				dp[j] = max(dp[j], dp[j - total[i]] + total[i]);   //从后往前AC，从前往后WA，解释参见算法书273
		}

		printf("%.2lf\n", dp[top] / 100.0);
	}
	return 0;
}
