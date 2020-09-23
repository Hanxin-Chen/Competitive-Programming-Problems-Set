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
#define N 1005
int n, b;
struct node {
	string type;
	string name;
	int price;
	int quality;
}com[N];

bool judge(int x)             //判断当前quality是否符合预算
{
	int i,j,sum = 0;
	for ( i = 0; i < n; )
	{
		int Min = 1 << 30;
		int pos = -1;
		for ( j = i; j < n && com[i].type==com[j].type; j++)      //取同名大于等于当前quality的最少钱数
		{
			if (com[j].quality >= x && Min > com[j].price)
			{
				pos = j;
				Min = com[j].price;
			}
		}
		if (pos == -1)              //没有符合的等级，返回false
			return false;
		sum += Min;
		i = j;
	}
	return sum <= b ? true : false;
}

int solve(int Min, int Max)
{
	int left, mid, right;
	left = Min, right = Max;
	while (left<=right)
	{
		mid = (left + right) >> 1;
		if (judge(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> b;
		int Max = 0, Min = 1 << 30;
		for (int i = 0;i < n;i++)
		{
			cin >> com[i].type >> com[i].name;
			cin >> com[i].price >> com[i].quality;
			Min = min(Min, com[i].quality);
			Max = max(Max, com[i].quality);      //找出最小quality和最大quality二分
		}
		int ans = solve(Min, Max);
		for (int i = 0; i < n; i++)
		{
			if (com[i].quality >= ans)              //有可能二分的答案不在quality里面
				ans = min(ans, com[i].quality);
		}
		cout << ans << endl;
	}
	return 0;
}
