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
#define N 1000005
using namespace std;
__int64 pow(__int64 a, __int64 b)
{
	__int64 ret = 1, tmp = a;
	while (b)
	{
		if (b & 1)
			ret *= tmp;
		tmp *= tmp;
	}
	return ret;
}
int judge(__int64 left, __int64 right, __int64 k)
{
	__int64 mid = (left + right) >> 1;
	if (left + 1 == right)
		return left;
	if (pow(2, mid) > k)
		return judge(left, mid, k);
	else
		return judge(mid, right, k);
}
int main()
{
	ios::sync_with_stdio(false);
	__int64 t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		__int64 sum = 0;
		sum = n * (n + 1) / 2;
		__int64 ret = judge(0, 63, n);
		sum -= 2 * (pow(2, ret + 1) - 1);
		if (n == 0)
			sum = 0;
		cout << sum << endl;
		//cout << ret << endl;
	}
	return 0;
}
