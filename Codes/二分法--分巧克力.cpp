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
//#include <Windows.h>
#pragma warning(disable:4996);
using namespace std;
#define N 100008
int n, k;
int len[N], wid[N];

int handle(int left, int right) {
	if (left+1 >= right) {
		return left;
	}
	int ans;
	int mid = (left + right) >> 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += (len[i] / mid)*(wid[i] / mid);
	}
	if (cnt >= k) {
		ans=handle(mid, right);
	}
	else
	{
		ans=handle(left, mid);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int ans;
	for (int i = 0; i < n; i++)
	{
		cin >> len[i] >> wid[i];
	}
	ans = handle(1, N);
	cout << ans;
	return 0;
}