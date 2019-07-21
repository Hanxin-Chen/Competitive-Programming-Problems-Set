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
#define N 105
int n;
int ans[N][N];
int value(int x, int y)
{
	int sum;
	int i, j;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i >= x && j >= y)
				sum = max(sum, ans[i][j] + ans[i - x][j - y] - ans[i - x][j] - ans[i][j - y]);
			if (i >= y && j >= x)
				sum = max(sum, ans[i][j] + ans[i - y][j - x] - ans[i - y][j] - ans[i][j - x]);
		}
	}
	return sum;
}
int main()
{
	int i, j;
	int result;
	int num;
	int temp;
	while (scanf_s("%d", &n) != EOF)
	{
		memset(ans, 0, sizeof(ans));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf_s("%d", &num);
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + num;
			}
		}
		result = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = i; j <= n; j++)
			{
				temp = value(i, j);
				if (temp > result)
					result = temp;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}