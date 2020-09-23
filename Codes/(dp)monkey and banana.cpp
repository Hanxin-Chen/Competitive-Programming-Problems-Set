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
#include<queue>
using namespace std;
struct node
{
	int l, w, h;
}data1[1010];

bool cmp(node a, node b)
{
	if (a.l == b.l) return a.w > b.w;
	return a.l > b.l;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, i, j, len, a, b, c, Max, t = 0;
	int dp[1010];
	while (cin >> n && n)
	{
		for (i = len = 0;i < n;i++)
		{
			cin >> a >> b >> c;
			//无穷多个是个幌子，只需要三种形态，每种形态长和宽度交换，一共六种！
			data1[len].h = a, data1[len].l = b, data1[len].w = c;
			data1[len + 1].w = a, data1[len + 1].h = b, data1[len + 1].l = c;
			data1[len + 2].l = a, data1[len + 2].w = b, data1[len + 2].h = c;
			data1[len + 3].h = a, data1[len + 3].w = b, data1[len + 3].l = c;
			data1[len + 4].w = a, data1[len + 4].l = b, data1[len + 4].h = c;
			data1[len + 5].l = a, data1[len + 5].h = b, data1[len + 5].w = c;
			len += 6;
		}
		sort(data1, data1 + len, cmp);  //越靠前的底部长和宽越大
		for (i = Max = 0;i < len;i++)  //顶部方块的约束
		{
			dp[i] = data1[i].h;
			for (j = 0;j < i;j++)  //找之前以底边比他大的块为顶部的组合
				if (data1[j].w > data1[i].w && data1[j].l > data1[i].l)
					dp[i] = max(dp[i], dp[j] + data1[i].h);  //换一个头的约束
			Max = max(dp[i], Max);
		}
		cout << "Case " << ++t << ": maximum height = " << Max << endl;
	}
	return 0;
}
