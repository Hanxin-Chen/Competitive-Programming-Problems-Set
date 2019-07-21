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
//此程序有bug！！！
int a[18],cnt=0;
int m[6][6],ans=0;
int vis[20][20];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int bfs(int x,int y){
    queue<pair<int,int> > q;
    vis[x][y]=1;
    pair<int,int> point;
    point=make_pair(x,y);
    q.push(point);
    int x1,y1,dx,dy;
    int cnt2=0;
    while(!q.empty()){
        point =q.front();
        q.pop();
        x1=point.first;
        y1=point.second;
        for(int i = 0; i < 4; i++)
        {
            dx=x1+dir[i][0];
            dy=y1+dir[i][1];
            if(vis[dx][dy])
                continue;
            if(m[dx][dy]==1)
                continue;
            if(dx<0 || dy<0 ||dx>5||dy>5)
                continue;
            q.push(make_pair(dx,dy));
            cnt2++;
            vis[dx][dy]=1;
        }
        
    }
    return cnt==18;
}
void dfs(int dep){
    int x,y;
    if(dep==18){
        cnt++;
        for(int i = 0; i < 18; i++)
        {
            x=i/6;
            y=i%6;
            m[x][y]=a[i];
            m[6-x][6-y]=1-a[i];
        }
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(m[i][j]==0){
                    memset(vis,0,sizeof(vis));
                    ans+=bfs(i,j);
                    return;
                }
            }
        }
        return;
    }
    a[dep]=0;
    dfs(dep+1);
    a[dep]=1;
    dfs(dep+1);
}
int main(){
    ios::sync_with_stdio(false);
    //方法一
    dfs(0);
    cout<<cnt<<endl;
    //方法二
    int x,y;
    for(int i = 0; i < (1<<19)-1; i++)
    {
        for(int j = 0; i < 18; i++)
        {
            x=j%6;
            y=j%6;
            m[x][y]=((i>>j)&1);
            m[6-x][6-y]=1-((i>>j)&1);
        }
        int j;
        for(int k = 0; k < 6; k++)
        {
            for( j = 0; j < 6; j++)
            {
                if(m[i][j]==0){
                    memset(vis,0,sizeof(vis));
                    ans+=bfs(i,j);
                   break;
                }
            }
        }
        if(j<6)
            break;
    }
    system("pause");
}