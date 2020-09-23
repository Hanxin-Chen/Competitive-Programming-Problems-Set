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
typedef long long LL;

int judge(LL x) {
	return x % 12 == 1 || x % 12 == 2 || x % 12 == 5 || x % 12 == 7
		|| x % 12 == 10 || x % 12 == 11;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		LL n;
		scanf("%lld", &n);
		if (judge(n)) printf("-1\n");
		else {
			LL x, y, z;
			if (n % 3 == 0) x = y = z = n / 3;
			else {
				x = n / 2;
				y = z = x / 2;
			}
			printf("%lld\n", x*y*z);
		}
	}
	return 0;
}