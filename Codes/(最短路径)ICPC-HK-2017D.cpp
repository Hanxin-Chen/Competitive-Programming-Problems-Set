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
#define N 100
#define INF 0x3f3f3f3f
int m, po, pt,ans=INF;
int card[N][N],vis[N],D[N];
void ini() {
	for (int i = 0; i <= m; i++) {
		D[i] = INF;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin>>m){
		memset(card, -1, sizeof(card));
		int x, y, mark;
		ini();
		cin >> po >> pt;
		while (cin >> x, x) {
			cin >> y >> mark;
			card[x][y] = card[y][x] = mark;
		}
		ans = INF;
		memset(vis, 0, sizeof(vis));
		vis[po] = 1;
		for (int i = 1; i <= m; i++) {
			if (card[po][i] <= 0)
				continue;
			D[i] = card[po][i];
		}
		for (int j = 1; j < m; j++) {
			int index=0, cost = INF;
			for (int i = 1; i <= m; i++) {
				if (vis[i])
					continue;
				if (cost > D[i]) {
					cost = D[i];
					index = i;
				}
			}
			vis[index] = 1;
			for (int i = 1; i <= m; i++) {
				if (vis[i])
					continue;
				if (card[index][i] <= 0)
					continue;
				D[i] = min(D[i], D[index] + card[index][i]);
			}
		}
		cout << D[pt] << endl;
	}
	return 0;
}


