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
#define UP 10000.0
struct point
{
	double x, y;
};
point p;
int a, b, c;
double f(double x)
{
	return a * x*x + b * x + c;
}

double dis(point p1, point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

double trisearch(double left, double right)
{
	
	double lm = left + (right - left) / 3;
	double rm = right - (right - left) / 3;
	point p1, p2;
	p1.x = lm;
	p2.x = rm;
	p1.y = f(lm);
	p2.y = f(rm);
	if (fabs(right - left) < 10e-6)
	{
		return dis(p1, p);

	}
	if (dis(p1, p) <= dis(p2, p))
	{
		return trisearch(left, rm);

	}
	else
	{
		return trisearch(lm, right);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	double t,ret;
	cin >> a >> b >> c;
	cin >> p.x >> p.y;
	t = -1.0*b / 2 / a;
	if (p.x >= t)
	{
		ret=trisearch(t, UP);
	}
	else
	{
		ret=trisearch(-UP, t);
	}
	cout << ret << endl;
	return 0;
}

