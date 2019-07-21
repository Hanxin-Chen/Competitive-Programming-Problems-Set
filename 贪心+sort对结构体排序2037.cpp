#include <cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Program
{
	int start;
	int end;
};
bool cmp(Program x, Program y)
{
	return x.end < y.end;
}
int main()
{
	Program p[100];
	int n,i,j,sum;
	while (cin >> n && n != 0)
	{
		sum = 1;
		for (i = 0;i < n;i++)
			cin >> p[i].start >> p[i].end;
		sort(p, p + n, cmp);
		for (i = 0, j = 1;j < n;j++)
		{
			if (p[j].start >= p[i].end)
			{
				sum++;
				i = j;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}