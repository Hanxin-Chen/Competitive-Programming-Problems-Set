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
#define N 100050
using namespace std;
__int64 n;
__int64 m = 1000000007;
struct matrix
{
	__int64 a[3][3];
};
matrix mul(matrix m1, matrix m2)
{
	matrix ret;
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			ret.a[i][j] = ((m1.a[i][0]%m) * (m2.a[0][j]%m)+ (m1.a[i][1] % m) * (m2.a[1][j] % m)+ (m1.a[i][2] % m) * (m2.a[2][j] % m))%m;
	return ret;
}

matrix powM(matrix m, __int64 n)
{
	if (n == 1)
		return m;
	matrix tmp;
	tmp = powM(m, n >> 1);
	if (n & 1)
		return mul(m, mul(tmp, tmp));
	else
		return mul(tmp, tmp);
}
matrix ma = { 1,0,1,1,0,0,0,1,0};
int k[7] = { 0,0,3,4,6,9 };
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		matrix ret;
		__int64 a;
		if (n > 4)
		{
			ret = powM(ma, n - 4);
			a = (6 * ret.a[0][0] % m + 4*ret.a[0][1]%m+ 3 * ret.a[0][2] % m ) % m;
		}
		else
		{
			a = k[n];
		}
		cout << a%m << endl;
	}
	return 0;
}

