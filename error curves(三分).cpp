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
#define N 10005
int n;
struct node
{
	int a, b, c;
}fun[N];

double f(int a, int b, int c, double x)
{
	double fx = a * x*x + b * x + c;
	return fx;
}

double maxval(double x)
{
	double max = -9999999;
	for (int i = 0;i < n;i++)
	{
		if (max < f(fun[i].a, fun[i].b, fun[i].c, x))
			max = f(fun[i].a, fun[i].b, fun[i].c, x);
	}
	return max;
}

double find(double left, double right)
{
	double lm = left + (right - left) / 3;
	double rm = right - (right - left) / 3;
	if (fabs(left - right) < 10e-12)             //精度要求较高
		return maxval(left);
	if (maxval(lm) < maxval(rm))
		return find(left, rm);
	else
		return find(lm, right);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> fun[i].a >> fun[i].b >> fun[i].c;
		double left = 0, right = 1000;
		double ans = find(left, right);
		printf("%.4lf\n", ans);
	}
	return 0;
}
