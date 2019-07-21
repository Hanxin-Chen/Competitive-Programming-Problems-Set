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
#define N 1000005
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int a[N],n,dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0)
			tmp = a[0];
		tmp = gcd(tmp, a[i]);
	}
	if (tmp != 1)
	{
		cout << "INF" << endl;
		return 0;
	}
	dp[0] = 1; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + a[i] < 100 * 100 + 5; j++) {
			if (dp[j]) dp[j + a[i]] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100 * 100 + 5; i++) {
		if (!dp[i])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}