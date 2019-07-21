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
using namespace std;
long long  n;
long long  a, b, c;
long long  k;
/*
	费马大定理：当n>=3时，a^n+b^n=c^n无解
*/
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		scanf_s("%lld %lld", &n, &a);
		if (n == 1)
		{
			//cout << b << " " << c << endl;
			printf("1 %lld\n", a+1);
		}
		else if (n == 2)
		{
			if (a & 1)
			{
				k = (a - 1) >> 1;
				b = 2 * k * k + 2 * k;
				c = b + 1;
			}
			else
			{
				k = a >> 1;
				b = k * k - 1;
				c = b + 2;
			}
			//cout << b << " " << c << endl;
			printf("%lld %lld\n", b, c);
		}
		else
			printf("-1 -1\n");
			//cout << "-1 -1" << endl;
	}

	return 0;
}