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
#include<queue>
using namespace std;
#define N 22
int dp[N][N*(N - 1) / 2];

int main()
{
	int n;
	cin >> n;
	//string ans=(10,'0');
	for (int i = 0;i <= n;i++)
		dp[i][0] = 1;
	
	for(int i=0;i<=n;i++)
		for (int r = 0;r <= i;r++)  //���¼�ֱ��ƽ�е�����Ϊi-r;
		{
			for (int j = 0;j <= r * (r - 1) / 2;j++) //�б�r��ֱ�����еĽ��������
			{
				if (dp[i][j] == 1)
					dp[i][(i - r)*r + j] = 1;
			}
		}
	for (int i = 0;i <= n * (n - 1);i++)
		if (dp[n][i] == 1)
			cout << i << " ";
	cout << endl;

	return 0;
}
