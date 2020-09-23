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
/*			这道题和Alice and Bob类似，但是结果中需要两对元素，则无法像上一题一样使用multiset
			尝试使用map，multimap，分别出现原始数据被覆盖，迭代器失效等问题。
		解题思路：先将两者以x优先排序（x的收益优先），次之按y排序——bool cmp
				  然后以task对machine进行搜索，初步符合条件（x）放置在容器中，容器中存放的是符合条件的y的值  PS：可以考虑用map，节省时间
				  因为 y<=100 则可以从task.y 向上搜索，找到最小的y值，由于两者都是递减数列，则存放在s中的y值所对应的x必定符合条件。
				  若找到，则计数器++，计算出当前的价钱（注意：是用task来计算），将key的value--；
*/
struct node
{
	int x, y;
	int flag = 0;
}mach[N],task[N];
bool cmp(node a, node b)
{
	if(a.x==b.x)
	return a.y > b.y;
	else
	return a.x > b.x;
}
int s[150];
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		int j=0;
		int cnt = 0;
	    __int64 money = 0;
		memset(s, 0, sizeof(s));
		for (int i = 0;i < n;i++)
			cin >> mach[i].x >> mach[i].y;
		for (int j = 0;j < m;j++)
			cin >> task[j].x >> task[j].y;
		sort(mach, mach + n, cmp);
		sort(task, task + m, cmp);
		for (int i = 0;i < m;i++)
		{
			while (j < n && mach[j].x >= task[i].x)
			{
				s[mach[j].y]++;
				j++;
			}
			for (int k = task[i].y; k <= 100; k++)
			{
				if (s[k] > 0)
				{
					cnt++;
					money += 500 * task[i].x + 2 * task[i].y;
					s[k]--;
					break;
				}
			}
		}
		cout << cnt << " " << money << endl;
	}
	return 0;
}

