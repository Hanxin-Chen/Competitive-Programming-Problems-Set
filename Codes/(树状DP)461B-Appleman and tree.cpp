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
#define MOD 1000000007
int n, m;
int color[N];
long long int dp[N][2];
vector<int> Tree[N];
// codeforces 461B
void dfs(int u, int p)
{
	dp[u][color[u]] = 1;
	for (int i = 0; i < Tree[u].size(); i++)
	{
		int v = Tree[u][i];
		if (v == p) continue;
		dfs(v, u);
		long long int old[] = { dp[u][0],dp[u][1] };
		dp[u][1] = old[1] * dp[v][0] % MOD + old[0] * dp[v][1] % MOD+ old[1] * dp[v][1] % MOD;
		dp[u][1] %= MOD;
		dp[u][0] = old[0] * dp[v][0] %MOD + old[0] * dp[v][1] % MOD;
		dp[u][0] %= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int  y;
	memset(color, 0, sizeof(color));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n; i++){
		cin >>  y;
		Tree[i].push_back(y);
		Tree[y].push_back(i);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y;
		color[i] = y;
	}
	dfs(0, -1);
	cout << dp[0][1] << endl;
	return 0;
}
