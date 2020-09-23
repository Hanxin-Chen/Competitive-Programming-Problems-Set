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
#define N 2020
using namespace std;
int h[5][N];
int main()
{
	ios::sync_with_stdio(false);
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
			carry = 0;

			for (int j = 0;j <= count;j++)
			{
				k = h[3][j] + h[2][j] + h[1][j] + h[0][j] + carry;
				carry = k / 10;
				h[4][j] = k % 10;
				h[0][j] = h[1][j];
				h[1][j] = h[2][j];
				h[2][j] = h[3][j];
				h[3][j] = h[4][j];
			}
			while (carry)
			{
				count++;
				h[3][count] += carry % 10;
				carry = carry / 10;
			}

		}
		for (int i = count; i >= 0; i--)
		{
			cout << h[3][i];
		}
		cout << endl;
	}
	return 0;
}