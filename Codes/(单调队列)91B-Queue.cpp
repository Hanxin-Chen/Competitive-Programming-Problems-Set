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
#define N 200005
int  n, a[N],ans[N];
//codeforces 91B-Queue
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>v1, v2;
	for (int i = n-1; i >= 0; i--)
	{
		if (v1.size() == 0 || v1.back() >= a[i]) {
			v1.push_back(a[i]);
			v2.push_back(i);
			ans[i] = -1;
		}
		else {
			int j = lower_bound(v1.rbegin(), v1.rend(),a[i]) - v1.rbegin();
			j = v1.size() - j;
			ans[i] = v2[j] - i - 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}


