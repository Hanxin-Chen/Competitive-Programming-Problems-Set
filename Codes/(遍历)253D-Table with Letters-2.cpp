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
#define N 1000
int  n,m,s, a[N][N],sum[N][N];
long long int ans = 0;
map<int, int>ma;

/*
http://codeforces.com/problemset/problem/253/D
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> s;
	char ch;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			a[i][j] = (int)(ch - 'a');
			sum[i][j] =  sum[i - 1][j] + sum[i][j - 1]- sum[i - 1][j - 1] ;
			if (ch == 'a')
				sum[i][j]++;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int temp = 1;
			ma.clear();
			for (int k = 1; k <= m; k++) {
				if (a[i][k] == a[j][k]) {
					ma[a[i][k]]--;
					while (temp<=m&&sum[j][temp]-sum[i-1][temp]-sum[j][k-1]+sum[i-1][k-1]<=s)
					{
						if (a[i][temp] == a[j][temp])
							ma[a[j][temp]]++;
						temp++;
					}
					if (ma[a[i][k]] > 0)
						ans += ma[a[i][k]];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}


