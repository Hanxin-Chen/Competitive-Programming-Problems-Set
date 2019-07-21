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
#define N 15

int ans = 0, ans1 = 0;
int x[N];    //x[i]==0 represents untake i-th goods, else take
int n,w;           //背包容量与物品数量
int cor = 0;     //当前背包已放的物品重量
int rest = 0;    //没有考虑的物品价值总和
int ret[N];

struct node
{
	int weight;
	int value;
}goods[N];


void dfs(int dep)             //第i个物品
{
	if (dep >= n) 
	{
		if (ans1 > ans) {
			ans = ans1;
			for (int i = 0;i < n;i++)
				ret[i] = x[i];
		}
		return;
	}
	rest -= goods[dep].value;
	//加入第dep个物品
	if (cor + goods[dep].weight <= w)
	{
		x[dep] = 1;
		ans1 += goods[dep].value;
		cor += goods[dep].weight;
		dfs(dep + 1);
		cor -= goods[dep].weight;            //回溯的时候减去已经加上的值
		ans1 -= goods[dep].value;
	}
	//不加入物品
	if (rest + ans1 > ans)                   //剪枝
	{
		x[dep] = 0;
		dfs(dep + 1);
	}
	rest += goods[dep].value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> w;
	for (int i = 0;i < n;i++)
	{
		cin >> goods[i].weight >> goods[i].value;
		rest += goods[i].value;
	}
	dfs(0);
	cout << ans << endl;
	for (int i = 0;i < n;i++)
		if (ret[i] != 0)
			cout << i + 1 << " ";
	cout << endl;
	return 0;
}
