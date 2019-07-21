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
int mod=10000000;
struct matrix
{
	int a11, a12, a21, a22;
	void print()
	{
		cout << a11 << "\t" << a12 << "\n" << a22 << "\t" << a21 << endl;
	}
}mach[N],task[N];
matrix mul(matrix m1, matrix m2)
{
	matrix ret;
	ret.a11 = (m1.a11* m2.a11 + m1.a12*m2.a21)%mod;
	ret.a12 = (m1.a11*m2.a12 + m1.a12*m2.a22)%mod;
	ret.a21 = (m1.a21*m2.a11 + m1.a22*m2.a21)%mod;
	ret.a22 = (m1.a21*m2.a12 + m1.a22*m2.a22)%mod;
	return ret;
}

matrix powM(matrix m, int n)
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
int main()
{
	int n;
	matrix m = { 1,1,1,0 }, ret;
	cin >> n;
	ret = powM(m, n - 1);
	cout << (ret.a11 + ret.a12)%mod << endl;
	return 0;
}

