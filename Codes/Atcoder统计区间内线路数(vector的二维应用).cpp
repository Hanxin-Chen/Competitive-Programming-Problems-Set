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

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	vector< int > ev[501];
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		ev[x].emplace_back(y);
	}
	for (int i = 0; i <= N; i++) {
		sort(begin(ev[i]), end(ev[i]));
	}
	while (Q--) {
		int p, q;
		cin >> p >> q;
		int ret = 0;
		for (int i = p; i <= q; i++) {
			ret += upper_bound(begin(ev[i]), end(ev[i]), q) - begin(ev[i]);
		}
		cout << ret << endl;
	}

}
