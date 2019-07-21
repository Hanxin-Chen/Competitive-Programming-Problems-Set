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
double r, R, H, V;
double cal(double hei) {
	double l = hei / H * (R - r) + r;
	return PI / 3 * hei*(l*l + r * r + l * r);
}
double find(double left,double right)
{
	double mid = (left + right)/2;
	if (right-left<=10e-7)
		return mid;
	double tmp = cal(mid);
	if (tmp > V)
		return find(left, mid);
	else
		return find(mid, right);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> r >> R >> H >> V;
		double left = 0.0, right = H;
		double h = find(left, right);
		printf("%.6lf\n", h);
	}
	return 0;
}

