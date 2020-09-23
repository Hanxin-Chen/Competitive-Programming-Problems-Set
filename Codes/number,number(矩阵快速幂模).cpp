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
#define mod 998244353
using namespace std;
//规律：斐波那契数列第2*k+3项-1
struct matrix
{
	__int64 a11, a12, a21, a22;
};
matrix mul(matrix m1, matrix m2)
{
	matrix ret;
	ret.a11 = (m1.a11* m2.a11%mod + m1.a12*m2.a21%mod) % mod;
	ret.a12 = (m1.a11*m2.a12%mod + m1.a12*m2.a22%mod) % mod;
	ret.a21 = (m1.a21*m2.a11%mod + m1.a22*m2.a21%mod) % mod;
	ret.a22 = (m1.a21*m2.a12%mod + m1.a22*m2.a22%mod) % mod;
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
matrix m = { 1,1,1,0 }, ret;
int main()
{
	ios::sync_with_stdio(false);
	__int64 k;
	__int64 ans;                     //注意数据类型
	while (cin>>k)
	{
		ret = powM(m, 2*k+3);
		ans = ((ret.a12 -1)%mod +mod)%mod;
		cout << ans << endl;
	}
	return 0;
}

