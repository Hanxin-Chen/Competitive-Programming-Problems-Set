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
using namespace std;
int main()
{
	int n;
	while (cin>>n,n)
	{
		cout << "Printing order for " << n << " pages:" << endl;
		int sheet = n / 4;
		if (n % 4 != 0)
			sheet += 1;
		int blank = 4 * sheet-n;
		int flag = 1;
		int page = 1;
		int d = n;
		if (n == 1)
			cout << "Sheet 1, front: Blank, 1" << endl;
		else
		{
			for (int i = 1;i <= sheet;i++)
			{
				cout << "Sheet " << i << ", front: ";     //Blank, " << paper << endl;
				if (page<=blank)
				{
					cout << "Blank, " << page << endl;
					page++;
					
				}
				else
				{
					cout << d << ", " << page << endl;
					page++;
					d--;
				}
				cout << "Sheet " << i << ", back : ";
				if (page<=blank)
				{
					cout << page <<", Blank"<< endl;
					page++;
	
				}
				else
				{
					cout << page << ", " << d << endl;
					page++;
					d--;
				}
			}
		}
	}
	return 0;
}