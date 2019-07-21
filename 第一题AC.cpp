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

int main()
{
	ios::sync_with_stdio(false);
	__int64 t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		__int64 sum = 0;
		__int64 tmp = 0;
		sum = n * (n + 1) / 2;
		for (int i = 0;pow(2, i) <= n;i++)
			tmp += pow(2, i);
		sum = sum - 2 * tmp;
		cout << sum << endl;
	}
	return 0;
}
