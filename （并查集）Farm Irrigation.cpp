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
#define N 2505
int m, n;
char area[52][52];

struct field          //用于存放11种类型的土地的水管开口方向
{                    
	//0 表示该方向没有水管，1表示有水管
	int n; //上
	int w; //左
	int e; //右
	int s; //下
}farm[15];

struct node          //并查集模板
{
	int data;
	int parent;   
	int rank;
	node() :rank(1) {}
}uf[N];

int find(int x)     
{
	int k = x, k1 = x;
	while (k != uf[k].parent)
	{
		k = uf[k].parent;
	}
	while (x != uf[x].parent)
	{
		k1 = uf[x].parent;
		uf[x].parent = k;
		x = k1;
	}
	return x;
}
void Union(int x, int y)    
{
	x = find(x), y = find(y);
	if (x != y)
	{
		if (uf[x].rank < uf[y].rank)
		{
			uf[x].parent = y;
		}
		else
		{
			uf[y].parent = x;
			if (uf[x].rank == uf[y].rank)
				uf[x].rank++;           
		}
	}
}
void ini()               //初始化
{
	for (int i = 1; i <= n*m; i++)     
	{
		uf[i].parent = i;
	}
}

int findthecase()        //查找并查集个数
{
	int ans = 0;
	for (int i = 1;i <= n * m;i++)
		if (uf[i].parent == i)
			ans++;
	return ans;
}
int main()
{
	//初始化11种类型的土地
	farm[1].n = farm[2].n = farm[5].n = farm[7].n = farm[8].n = farm[10].n = farm[11].n = 1;
	farm[3].s = farm[4].s = farm[5].s = farm[8].s = farm[9].s = farm[10].s = farm[11].s = 1;
	farm[2].e = farm[4].e = farm[6].e = farm[7].e = farm[9].e = farm[10].e = farm[11].e = 1;
	farm[1].w = farm[3].w = farm[6].w = farm[7].w = farm[8].w = farm[9].w = farm[11].w = 1;
	while (cin>>m>>n && n>=0 && m>=0)
	{
		ini();
		memset(area, 0, sizeof(area));
		for (int i = 1;i <= m;i++)
		{
			getchar();
			for (int j = 1;j <= n;j++)
				cin >> area[i][j];
		}
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				int a = (i - 1)*n + j;     // a 表示当前的位置
				//向下判断：当前位置的下方和下面位置的上方有水管
				if ( farm[(area[i][j] - 'A' + 1)].s == 1 && farm[(area[i + 1][j] - 'A' + 1)].n == 1)
					Union(a, i*n + j);
				//向左判断：当前位置的右方和右边方块的左方有水管
				if ( farm[(area[i][j] - 'A' + 1)].e == 1 && farm[(area[i][j + 1] - 'A' + 1)].w == 1)
					Union(a, a + 1);
			}
		}
		int ans = findthecase();
		cout << ans << endl;
	}
}
