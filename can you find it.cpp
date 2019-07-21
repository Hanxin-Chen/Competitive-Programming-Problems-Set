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
#define N 1000002
__int64 A[N],B[N],C[N];
__int64 num[N];
int main()
{
	ios::sync_with_stdio(false);
	int l,n,m;
	int s,x;
	int cnt = 0;
	while (cin>>l>>n>>m)
	{
		
		for (int i = 0;i < l;i++)
			cin >> A[i];
		for (int i = 0;i < n;i++)
			cin >> B[i];
		for (int i = 0;i < m;i++)
			cin >> C[i];
		for (int i = 0;i < l;i++)
			for (int j = 0;j < n;j++)
				num[i*n+j] = A[i] + B[j];
		sort(num, num + l*n);
		cout << "Case " << ++cnt << ":" << endl;
		cin >> s;
		while (s--)
		{
			cin >> x;
			int flag = 0;
			for (int i = 0;i < m;i++)
			{
				if (binary_search(num, num + l*n, x - C[i])!=0)
				{
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "NO" << endl;
			else
			{
				cout << "YES" << endl;
			}
		}
	}
	return 0;
}