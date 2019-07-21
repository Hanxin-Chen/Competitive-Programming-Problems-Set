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
/*
		原型为数塔：
		第t秒：						 1
		……   0	 1
		第2秒：0		0	1
		第1秒：1	0				 1
		       1	2	 3	  4 …… 10	
		从最顶层开始，类似于数塔相加，与数塔不同的是，这个为有三种选择，一条路径的数塔
*/

using namespace std;
#define N 100005
int dp[N][20];  //第一维度存放时间（行），第二维度存放坐标（列）
int main()
{
	int n;
	int x, y;
	while (scanf_s("%d",&n)!=EOF,n)
	{
		int t = -1;
		memset(dp, 0, sizeof(dp));
		for (int i = 0;i < n;i++)
		{
			scanf_s("%d %d", &x, &y);
			dp[y][x]++;
			if (y > t)
				t = y;
		}
		for(int i=t-1;i>=0;i--)
			for (int j = 10;j >= 0;j--)
			{
				dp[i][j] = max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1])) + dp[i][j];  //小bug应当从1开始，但是没大问题，a[-1]为负数

			}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}

