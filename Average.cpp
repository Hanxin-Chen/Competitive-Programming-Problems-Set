#include<cstdio>
#include<iostream>
using namespace std;
#define maxn 111111
int a[maxn], b[maxn];
int main()
{
	int t;
	scanf_s("%d", &t);
	while (t--)
	{
		int n;
		scanf_s("%d", &n);
		long long sum = 0;
		int av = 0, maxx = 0;
		for (int i = 0;i<n;i++)
		{
			scanf_s("%d", &a[i]);
			b[i] = a[i];
			sum += a[i];
			if (a[i]>a[maxx])
				maxx = i;
		}
		if (sum%n != 0)
		{
			printf("NO\n");
			continue;
		}
		av = sum / n;
		if (a[maxx]>av + 2)
		{
			printf("NO\n");
			continue;
		}
		if (a[maxx] == av)
		{
			printf("YES\n0\n");
			continue;
		}
		int flag1 = 1, flag2 = 1;
		int res = 0;
		pair<int, int>ans[maxn];
		for (int i = 0, j = maxx;i<n;i++, j = (j + 1) % n)
		{
			int k = (j + 1) % n;
			if (b[j] == av + 1 || j == maxx && b[j] == av + 2)
			{
				b[j]--, b[k]++;
				ans[res].first = j;
				ans[res++].second = k;
			}
			else if (b[j] == av)
				continue;
			else if (b[j] == av - 1)
			{
				b[j]++, b[k]--;
				ans[res].first = k;
				ans[res++].second = j;
			}
			else
			{
				flag1 = 0;
				res = 0;
				break;
			}
		}
		if (flag1)
		{
			printf("YES\n");
			printf("%d\n", res);
			for (int i = 0;i<res;i++)
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
			continue;
		}

		for (int i = 0, j = maxx;i<n;i++, j = (j + n - 1) % n)
		{
			int k = (j + n - 1) % n;
			if (a[j] == av + 1 || j == maxx && a[j] == av + 2)
			{
				a[j]--, a[k]++;
				ans[res].first = j;
				ans[res++].second = k;
			}
			else if (a[j] == av)
				continue;
			else if (a[j] == av - 1)
			{
				a[j]++, a[k]--;
				ans[res].first = k;
				ans[res++].second = j;
			}
			else
			{
				flag2 = 0;
				res = 0;
				break;
			}
		}
		if (flag2)
		{
			printf("YES\n");
			printf("%d\n", res);
			for (int i = 0;i<res;i++)
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
