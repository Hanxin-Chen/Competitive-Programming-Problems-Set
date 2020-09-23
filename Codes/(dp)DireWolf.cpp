#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10;
int f[maxn][maxn];
struct node {
	int ac, bc;
}a[maxn];
int main() {
	int n;
	int t;
	cin >> t;
	int k = 0;
	while (t--) {
		cin >> n;
		memset(f, 0x3f, sizeof(f));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> a[i].ac;
		}
		for (int j = 1; j <= n; j++) {
			cin >> a[j].bc;
		}
		for (int i = 1; i <= n; i++) {
			f[i][i] = a[i].ac + a[i - 1].bc + a[i + 1].bc;
			f[i][i - 1] = 0;
		}
		f[n + 1][n] = 0;
		for (int len = 2; len <= n; len++) {
			for (int i = 1, j; (j = i + len - 1) <= n; i++) {
				for (int k = i; k <= j; k++) {
					f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j] + a[i - 1].bc + a[j + 1].bc + a[k].ac);
				}
			}
		}
		printf("Case #%d: %d\n", ++k, f[1][n]);
	}
}