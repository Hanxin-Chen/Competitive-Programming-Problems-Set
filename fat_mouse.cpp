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
#define N 10002
using namespace std;
struct node
{
	int JavaBean;
	int catfood;

}room[N];
bool cmp(const node &n1, const node &n2)     //const 提高效率并且保护参数
{
	//return (1.0*n1.JavaBean / n1.catfood) > (1.0*n2.JavaBean / n2.catfood);
	return n1.JavaBean*n2.catfood > n1.catfood*n2.JavaBean;                //尽量避免除法（精度损失）转换为乘法；
}
int n, m;
int main()
{ 
	ios::sync_with_stdio(false);
	while (cin >> m >> n&&(n!=-1||m!=-1))
	{
		double ret = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> room[i].JavaBean >> room[i].catfood;
		}
		sort(room, room + n, cmp);
		int i = 0;
		for (i = 0; i < n; i++)
		{
			if (m >= room[i].catfood)
			{
				ret += room[i].JavaBean;
				m -= room[i].catfood;
			}
			else
				break;
		}
		if (i < n)
			ret += 1.0*room[i].JavaBean*m / room[i].catfood;

		printf("%.3lf\n", ret);

	}
	return 0;
}