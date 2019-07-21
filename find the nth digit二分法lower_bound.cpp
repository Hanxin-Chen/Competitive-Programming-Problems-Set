#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll val[66000];
int n, m;
int main() {
	int T, i, j, k;
	val[0] = 0;
	for (i = 1;val[i - 1] + i<pow(2, 31);i++)
		val[i] = val[i - 1] + i;
	scanf("%d", &T);
	while (T--) {
		cin >> n;
		k = lower_bound(val + 1, val + i, n) - val;
		k = (n - val[k - 1]) % 9;
		if (!k) printf("9\n");
		else printf("%d\n", k);
	}
	return 0;
}