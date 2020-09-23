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
int m,l;
struct matrix
{
	__int64 a[4][4];
};
matrix mul(matrix m1, matrix m2)
{
	matrix ret;
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++)
			ret.a[i][j] = ((m1.a[i][0]%m) * (m2.a[0][j]%m)+ (m1.a[i][1] % m) * (m2.a[1][j] % m)+ (m1.a[i][2] % m) * (m2.a[2][j] % m)+ (m1.a[i][3] % m) * (m2.a[3][j] % m))%m;
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
matrix ma = { 1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
int k[1000005] = { 0,2,4,6,9 };
int main()
{
	ios::sync_with_stdio(false);
	while (cin>>l>>m)
	{
		matrix ret;
		
		if (l > 4)
		{
			ret = powM(ma, l - 4);
			k[l] = (9 * ret.a[0][0] % m + 6*ret.a[0][1]%m+ 4 * ret.a[0][2] % m + 2 * ret.a[0][3] % m) % m;
		}
		cout << k[l]%m << endl;
	}
	return 0;
}

