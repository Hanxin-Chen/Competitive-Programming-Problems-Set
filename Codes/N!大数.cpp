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
#define N 10000
using namespace std;
int h[N][N];
int main()
{
	int n;
	while (cin >> n)
	{
		memset(h, 0, sizeof(h));
		h[0][0] = 1;
		h[1][0] = 1;
		h[2][0] = 1;
		h[3][0] = 1;
		int carry;
		int count = 0;
		int k, a, b;
		for (int i = 4;i < n;i++)
		{
			for (int k = 1;k <= 4;k++)
			{
				carry = 0;
				for (int j = 0;j <= count;j++)
				{
					k = h[i][j] + h[i - k][j] + carry;
					carry = k / 10000;
					h[i][j] = k % 10000;
				}
				while (carry)
				{
					count++;
					h[count] += carry % 10000;
					carry = carry / 10000;
				}
			}
		}
		for (int i = count; i >= 0; i--)
		{
			if (i == count)
				cout << h[n - 1][i];
			else
			{
				printf("%04d", h[i]);
			}
		}
		cout << endl;
	}
	return 0;
}