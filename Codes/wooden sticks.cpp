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
struct wooden
{
	int len;
	int we;
	int flag=0;
}stick[5050];
bool cmp1(wooden a, wooden b)
{
	if (a.len == b.len)
		return a.we > b.we;
	else
	{
		return a.len > b.len;
	}
	
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> stick[i].len >> stick[i].we;
			stick[i].flag = 0;
		}
		sort(stick, stick + n, cmp1);          //len优先，we次之，排序，从大到小
		wooden tmp;
		int ans = 0;
		int flag2 = 1;
		for (int i = 0;i < n;i++)            //从第一个开始遍历
		{
			if (stick[i].flag == 1)         //木棒被加工过，跳过
				continue;
			tmp = stick[i];
			flag2 = 1;
			stick[i].flag = 1;
			for (int j = i + 1;j < n;j++)    //从i之后开始遍历 （i之前已经处理过）
			{
				if (tmp.we >= stick[j].we&&stick[j].flag!=1&&tmp.len>=stick[j].len)      //判断未被加工过 并且符合条件的
				{
					stick[j].flag = 1;
					tmp = stick[j];                               //tmp是因为machine和之前一个有关
				}
			}
			ans++;
			for (int j = 0;j < n;j++)                          //遍历数组，判断是否加工完。
				if (stick[j].flag !=1)
					flag2 = 0;
			if (flag2 == 1)
				break;
		}
		
		cout << ans << endl;
	}
	return 0;
}
