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
#define N 1000
#define inf 1<<30;
char x[N], y[N];
int dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	cin >> x + 1 >> y + 1;
	x[0] = ' ';
	y[0] = ' ';
	int lenx, leny;
	lenx = strlen(x) , leny = strlen(y) ;
	for (int i = 0;i < lenx;i++)
		dp[i][0] = 0;
	for (int i = 0;i < leny;i++)
		dp[0][i] = 0;
	for(int i=1;i<lenx;i++)
		for (int j = 1;j < lenx;j++)
		{
			if (x[i] == y[i])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[lenx - 1][leny - 1] << endl;
	return 0;
}