#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
#include <map>
#include <ctime>
#include <sstream>
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
#define N 1000005
long long ans[36][36];
int main()
{
	long long n, h;
	ans[0][0] = 1;
	for (int i = 1; i <= 35; i++)
		for (int j = 1; j <= 35; j++)
			for (int k = 1; k <= i; k++)
				for (int l = 0; l < j; l++)
				{
					ans[i][j] += ans[k - 1][j - 1] * ans[i - k][l];
					if (l != j - 1)
						ans[i][j] += ans[i - k][j - 1] * ans[k - 1][l];
				}
	for (int i = 1; i <= 35; i++)
		for (int j = 1; j <= 35; j++)
			ans[i][j] += ans[i][j - 1];
	scanf("%d%d", &n, &h);
	printf("%I64d\n", ans[n][n] - ans[n][h - 1]);
	return 0;
}

