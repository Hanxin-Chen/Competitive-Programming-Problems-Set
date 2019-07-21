#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
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
#include <stack>
#pragma warning(disable:4996);
using namespace std;
#define N 105
int ans[N][N][N];
int a1[N][N], a2[N][N], a3[N][N];
int x, y, z;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin>>x>>y>>z){
		int ans = 0;
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		for (int i = 1; i <=x; i++){
			for (int j = 1; j <= y; j++) {
				cin >> a1[i][j];
			}
		}
		
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= z; j++) {
				cin >> a2[i][j];
			}
		}
		for (int i = 1; i <= z; i++) {
			for (int j = 1; j <= x; j++) {
				cin >> a3[i][j];
			}
		}
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				for (int k = 1; k <= z; k++) {
					if (a1[i][j] == 1 && a2[j][k] == 1 && a3[k][i] == 1)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
