#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cctype>
using namespace std;
struct point {
	int x, y;
	point(int x1, int y1) :x(x1), y(y1) {}
	point() :x(0), y(0) {}

};

struct point_double {
	double x, y;
	point_double(double x1, double y1) :x(x1), y(y1) {}
	point_double() :x(0), y(0) {}

};

double len(point p1, point  p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int mul_sc(point p1, point p2)
{
	return (p1.x*p2.x + p1.y*p2.y);
}

int angle_cos(point p1, point p2)
{
	return mul_sc(p1, p2) / len(p1, point(0, 0)) / len(p2, point(0, 0));

}

int angle(point p1, point p2)
{
	return acos(angle_cos(p1, p2));
}

int mul_across(point p0, point p1, point p2)    //向量外积的值
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p2.y - p0.y);
}

//利用拐向是否一致来判断是否为凸多边形
int dir(point p0, point p1, point p2)  //顺时针与逆时针
{
	int ret = mul_across(p0, p1, p2);
	if (ret > 0)  //顺时针,右拐
		return 1;
	else if (ret == 0) //同向
		return 0;
	else return -1;   //逆时针，左拐
}

//判断p3是否在p1,p2之间
int between(point p1, point p2, point p3)
{
	if (p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x) && p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y))
		return 1;
	return 0;
}

//判断p1,p2与p3,p4是否相交
int intersection(point p1, point p2, point p3, point p4)
{
	if (min(p1.x, p2.x) > max(p3.x, p4.x) ||
		max(p1.x, p2.x) < min(p3.x, p4.x) ||
		min(p1.y, p2.y) > max(p3.y, p4.y) ||
		max(p1.y, p2.y) < min(p3.y, p4.y))
		return 0;
	int d1 = dir(p1, p2, p3), d2 = dir(p1, p2, p3), d3 = dir(p3, p4, p1), d4 = dir(p3, p4, p2);
	if (d1*d2 < 0 && d3*d4 < 0)
		return 1;       //拐向不同则相交）
	else if ((d1 == 0 && between(p1, p2, p3)) ||
		(d2 == 0 && between(p1, p2, p4)) ||
		(d3 == 0 && between(p3, p4, p1)) ||
		(d4 == 0 && between(p3, p4, p2))) {
		return 1;
	}
	return 0;
}
double area(point po1[], int n)
{
	double ret = 0;
	for (int i = 0; i < n-1; i++)
	{
		ret += mul_across(point(0, 0), po1[i], po1[i+1]);
	}
	ret += mul_across(point(0, 0), po1[n-1], po1[0]);
	return ret;
}

point_double center(point po1[], int n)
{
	double A = area(po1, n);
	double retx, rety;
	int cp;
	po1[n] = po1[0];
	for (int i = 0; i < n; i++)
	{
		cp = mul_across(point(0, 0), po1[i], po1[i + 1]);
		retx += (po1[i].x + po1[i + 1].x)*cp;
		rety += (po1[i].y + po1[i + 1].y)*cp;
	}
	retx = retx / A / 6;
	rety = rety / A / 6;
	return point_double(retx, rety);
}
#define N 10000
point ret[N],p0;

bool cmp(const point &p1, const point &p2)
{
	int tmp = mul_across(p0, p1, p2);
	if (tmp>0)
		return true;
	else if (tmp == 0)
	{
		if (len(p0, p1) < len(p0, p2))
			return 1;
	}
    return false;
}

void graham_scan(point po1[], int n)
{
	int min_idx = 0;
	point t0, t1, t2;
	for (int i = 1; i < n; i++)
	{
		if (po1[i].y < po1[min_idx].y || (po1[i].y == po1[min_idx].y && po1[i].x < po1[min_idx].x))
			min_idx = i;

	}
	//将po1[0]变为最左下的点
	swap(po1[0], po1[min_idx]);
	p0 = po1[0];
	sort(po1 + 1, po1 + n,cmp);
	int top = 2;
	ret[0] = po1[0];
	ret[1] = po1[1];
	ret[2] = po1[2];
	for (int i = 3; i < n; i++)
	{
		while (true)
		{
			t0 = ret[top - 1];
			t1 = ret[top];
			t2 = po1[i];
			if (mul_across(t0, t1, t2) > 0)
			{
				break;
			}
			top--;
		}
		ret[++top] = po1[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	point p1(2, 3), p2;
	return 0;
}


