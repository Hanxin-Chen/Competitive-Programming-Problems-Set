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
#define N 21

int ans = 0, ans1 = 0;
int x[N];    //x[i]==0 represents untake i-th goods, else take
int n, w,k;           //背包容量与物品数量
int cor = 0,cnt=0;     //当前背包已放的物品重量

struct node
{
	int weight;
	int value;
}goods[N];


void dfs(int dep)             //第i个物品
{
	if (dep >= n)
	{
		if (ans1 > ans)
			ans = ans1;
		return;
	}
	//加入第dep个物品
	if (cor + goods[dep].weight <= w && cnt< k)
	{
		x[dep] = 1;
		ans1 += goods[dep].value;
		cor += goods[dep].weight;
		cnt++;
		dfs(dep + 1);
		cor -= goods[dep].weight;            //回溯的时候减去已经加上的值
		ans1 -= goods[dep].value;
		cnt--;
	}
	//不加入物品
	x[dep] = 0;
	dfs(dep + 1);

}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		ans = 0, ans1 = 0;
		cor = 0;
		cnt = 0;
		memset(x, 0, sizeof(x));
		for (int i = 0;i < n;i++)
		{
			cin >> goods[i].value >> goods[i].weight;
		}
		cin >> w;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}

