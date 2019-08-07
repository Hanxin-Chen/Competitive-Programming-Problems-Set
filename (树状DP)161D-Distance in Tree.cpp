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
#define N 50005
int dp[N][510];
int n, k;
vector<int>tree[N];
int ans = 0;
void dfs(int u,int far) {
	dp[u][0] = 1;
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == far)
			continue;
		dfs(v, u);
		for (int j = 0; j < k; j++)
			ans += dp[u][j] * dp[v][k - j - 1]; 
		for (int j = 1; j <= k; j++)
			dp[u][j] += dp[v][j - 1];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1, -1);
	cout << ans << endl;
	return 0;
}


