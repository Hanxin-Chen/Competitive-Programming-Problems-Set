#include <cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>     
#include<map>
#include<iomanip>
#include<cctype>
#include<vector>
#include<set>
#include<cstdlib>
#define PI 3.1415926
using namespace std;
struct point
{
	double x, y, z;
}bo[15],u1,rd;
int main()
{
	ios::sync_with_stdio(false);
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int n;
	double ra, dis, ras[15] = { 0.0 }, ret = 0, ret1 = 0;
	cin >> n;
	cin >> rd.x >> rd.y >> rd.z;
	cin >> u1.x >> u1.y >> u1.z;
	for (int i = 0;i < n;i++)
	{
		cin >> bo[i].x >> bo[i].y >> bo[i].z;
	}
	do
	{
		ret1 = 0;
		for (int i = 0;i < n;i++)
		{
			//找出距离边界最小的半径
			ra = min(fabs(rd.x - bo[a[i]].x), fabs(bo[a[i]].x - u1.x));
			ra = min(ra, min(fabs(u1.y - bo[a[i]].y), fabs(bo[a[i]].y - rd.y)));
			ra = min(ra, min(fabs(u1.z - bo[a[i]].z), fabs(bo[a[i]].z - rd.z)));
			for (int j = 0;j < i;j++)
			{
				//找出与之前各点的距离
				dis = sqrt((bo[a[i]].x - bo[a[j]].x)*(bo[a[i]].x - bo[a[j]].x)
					+ (bo[a[i]].y - bo[a[j]].y)*(bo[a[i]].y - bo[a[j]].y)
					+ (bo[a[i]].z - bo[a[j]].z)*(bo[a[i]].z - bo[a[j]].z));
				dis -= ras[j];
				ra =max(0.0, min(ra, dis));
			}
			ras[i] = ra;
			ret1 += 4.0 / 3 * PI*ra*ra*ra;
		}
		ret = max(ret, ret1);
	} while (next_permutation(a,a+n));
	cout << ret << endl;
	return 0;
}