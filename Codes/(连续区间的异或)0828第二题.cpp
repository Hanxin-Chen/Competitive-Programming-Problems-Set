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
#define ll long long
using namespace std;
#define N 100005
int n;
long long num;
long long  we;
ll Get_ans(ll a)
{
	if (a % 4 == 1)
		return 1;
	else if (a % 4 == 2)
		return a + 1;
	else if (a % 4 == 3 || a == 0)
		return 0;
	else
		return a;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	ll ans = 0;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> num;
			cin >> we;
			if (i == 0)
			{
				if (num > 1)
					ans = (Get_ans(we + num - 1) ^ (Get_ans(we - 1)));
				else
					ans = we;
			}
			else
			{
				if (num > 1)
					ans ^= (Get_ans(we + num - 1) ^ (Get_ans(we - 1)));
				else
					ans ^= we;
			}
		}
		if (ans <= 0)
			printf("Lose\n");
		else
			printf("Win\n");
	}
	return 0;
}
