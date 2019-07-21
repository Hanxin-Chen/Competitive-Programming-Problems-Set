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
#define N 10005
#define PI acos(-1.0)
using namespace std;
int ri;
double V[N];
double find(double left,double right,int n,int k)
{
	double mid = (left + right)/2;
	if (right-left<=10e-6)
		return mid;
	int cnt = 0;
	for (int i = 0;i < n;i++)
		cnt += (int)floor(V[i] / mid);
	if (cnt >= k)
		return find(mid, right, n, k);
	else
		return find(left, mid, n, k);
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n,f;
	cin >> t;
	while (t--)
	{
		double vmax=0;
		cin >> n >> f;
		f++;
		for (int i = 0;i < n;i++)
		{
			cin >> ri;
			V[i] = 1.0*ri * ri*PI;
			if (vmax < V[i])
				vmax = V[i];
		}
		double left = 0.0, right = vmax;
		double ans = find(left, right, n, f);
		printf("%.4lf\n", ans);
	}
	return 0;
}

