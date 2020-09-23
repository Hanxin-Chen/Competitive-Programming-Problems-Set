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
using namespace std;
int partition(int a[], int left, int right)
{
	int k = left + rand() % (right - left + 1);
	swap(a[k], a[left]);
	int x = a[left], i = left, j = right+1;
	while (1)
	{
		while (a[++i] < x);
		while (a[--j] > x);
		if (i > j)
			break;
		swap(a[i], a[j]);
	}
	a[left] = a[j];
	a[j] = x;
	return j;
}
void qsort(int a[], int left, int right)
{
	int m;
	
	if (left >= right)
		return;
	m = partition(a, left, right);
	qsort(a, left, m );
	qsort(a, m + 1, right);
}


int main()
{
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int a[] = { 2,3,12,4,1,124 };
	qsort(a, 0, 5);
	for (int i = 0;i < 6;i++)
		cout << a[i] << endl;

	return 0;
}