#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
	ios::sync_with_stdio(false);
	int T, l, i, j, f, la, lb, lc, dp[202][202];
	char a[202], b[202], c[1001];

	scanf_s("%d", &T);
	for (l = 0; l < T; l++)
	{
		cin >> a >> b >> c;
		la = strlen(a);
		lb = strlen(b);
		lc = strlen(c);
		f = 0;

		for (i = 0; i <= la; i++)
		{
			for (j = 0; j <= lb; j++)
			{
				if (a[i - 1] == c[i + j - 1] && (dp[i - 1][j] == i + j - 2 || !j))
					dp[i][j] = i + j - 1;
				else if (b[j - 1] == c[i + j - 1] && (dp[i][j - 1] == i + j - 2 || !i))
					dp[i][j] = i + j - 1;
				else
					dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);

				if (dp[i][j] == lc - 1)
				{
					f = 1;
					break;
				}
			}
		}

		if (f) printf("Data set %d: yes\n", l + 1);
		else printf("Data set %d: no\n", l + 1);
	}
	return 0;
}