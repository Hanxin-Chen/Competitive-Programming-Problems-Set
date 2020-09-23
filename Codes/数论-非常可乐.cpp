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
#pragma warning(disable:4996);
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c), a + b + c)
	{
		a /= gcd(b, c);
		if (a & 1)printf("NO\n");
		else printf("%d\n", a - 1);
	}
	return 0;
}