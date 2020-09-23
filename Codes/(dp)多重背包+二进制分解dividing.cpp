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
#define N 50010
#define inf 1<<30
int dp[N];
int f[10];
int thing[23000];
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	while (cin>>f[1]>>f[2]>>f[3]>>f[4]>>f[5]>>f[6], f[1] + f[2] + f[3] + f[4] + f[5] + f[6])
	{
		memset(dp, 0, sizeof(dp));
		memset(thing, 0, sizeof(thing));
		int k = 1, sum = 0;
		for (int i = 1;i <= 6;i++)    //二进制分解
		{
			sum += i * f[i];
			for (int j = 1;j <= f[i];j <<= 1)
			{
				thing[k++] = j * i;
				f[i] -= j;
			}
			if (f[i] > 0)
				thing[k++] = f[i] * i;     //考虑偶数最后剩余情况
		}
		int top = sum / 2;
		for (int i = 1;i < k;i++)
		{
			for (int j = top;j >= thing[i];j--)
				dp[j] = max(dp[j], dp[j - thing[i]] + thing[i]);
		}
		printf("Collection #%d:\n", ++cnt);
		if(dp[top]==sum-top)
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
}
