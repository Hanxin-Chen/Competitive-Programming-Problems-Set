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
#include<ctime>
#define N 100005
using namespace std;
const int MAXN = 1e5 + 10;
struct point {
	double x, y;
};

int n;
point a[MAXN];
vector<point> lp, rp;

bool cmpx(point a, point b) {
	return a.x < b.x;
}

bool cmpy(point a, point b) {
	return a.y < b.y;
}

double dis(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double findClosestPair(int l, int r) {
	if (l + 1 == r) return dis(a[l], a[r]);       //只剩两个点时，返回两个点距离
	if (l == r) return 9999999;                   //一个点返回一个无穷大，舍弃
	int mid = (l + r) >> 1;                       
	double d1 = min(findClosestPair(l, mid), findClosestPair(mid + 1, r));   //两边递归
	lp.clear(); rp.clear();

	//考虑中间情况（mid两边）

	for (int i = l;i <= mid; ++i)                 //对左边筛查，小于d1保留
		if (fabs(a[i].x - a[mid].x) < d1)
			lp.push_back(a[i]);

	for (int i = mid + 1; i <= r; ++i)           //对右边筛查
		if (fabs(a[i].x - a[mid].x) < d1)
			rp.push_back(a[i]);

	sort(rp.begin(), rp.end(), cmpy);             //对左右两边保留的元素按照y排序
	sort(lp.begin(), lp.end(), cmpy);
	int pos = 0;
	for (int i = 0; i < lp.size(); ++i)              //按照y值两个容器中的元素，从下到上遍历（优化版本）
		for (int j = pos; j < rp.size(); ++j) {      //为减少运算，先从y的差值考虑
			if (lp[i].y - rp[j].y > d1) pos = j + 1;    //left的点在right上方，并且y差值大于d1，右边的点废弃（left越往上，差值越大，没必要考虑）
			if (fabs(lp[i].y - rp[j].y) < d1) d1 = min(d1, dis(lp[i], rp[j]));  //y差值小于d1再进行判断
			if (lp[i].y - rp[j].y < -d1) break;                          //left的y值比right的小，并且已经大于d1，则其他情况必然不符合，跳出循环  
		}
	return d1;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin>>n,n) 
	{
		for (int i = 1; i <= n; ++i) 
			cin>>a[i].x>>a[i].y;
		sort(a + 1, a + 1 + n, cmpx);
		double ans = findClosestPair(1, n) / 2;
		printf("%.2lf\n", ans);

	}
	return 0;
}
