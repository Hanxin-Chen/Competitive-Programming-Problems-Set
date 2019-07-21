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
int mp[12]= {1,2,3,4,6,7,8,9,11,12,13,14};
int aa[5],vis[5],sum=0;
int b[4]= {-1,1,-5,+5};
void dfs(int n)
{
    for(int i=0; i<4; i++)
    {
        int t=aa[n]+b[i];
        if(t<1||t>14||t==5||t==10) continue;
        for(int j=0; j<5; j++)
            if(!vis[j]&&aa[j]==t)
            {
                vis[j]=1;
                dfs(j);
            }
    }
}
 
int main()
{
 
   
   do
   {
       for(int i = 0; i< 5; i++)
       {
           aa[i]=mp[i];
       }
       for(int i=0; i<5; i++)
            vis[i]=0;
        vis[0]=1;
        dfs(0);
        int flag=1;;
        for(int i=0; i<5; i++)
       {
        if(vis[i]!=1)
        {
         flag=0;
         break;
        }
       }
        if(flag==0) continue;
      else
        sum++;


       
   } while (next_permutation(mp,mp+12));
   
 
    cout<<sum<<endl;
 
    return 0;
}