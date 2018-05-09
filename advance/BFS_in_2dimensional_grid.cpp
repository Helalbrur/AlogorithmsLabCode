//BFS in two dimensional grid 4 possible moves
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 100
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};
int cell[mx][mx];
int d[mx][mx],vis[mx][mx];
int row,col;
bool isValid(int x,int y)
{
    if(x>=0 && x<row && y>=0  && y<col && vis[x][y]==0)
        return true;
    return false;
}
void BFS(int sx,int sy)
{
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(isValid(tx,ty) && cell[tx][ty]!=-1 )
            {
                vis[tx][ty]=1;
                d[tx][ty]=d[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    cin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>cell[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    BFS(x,y);
    cout<<d[1][2]<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<d[i][j]<<" ";
        }
    }
}
