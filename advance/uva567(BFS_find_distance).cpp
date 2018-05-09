#include<bits/stdc++.h>
using namespace std;
vector<int > edge[25];
int vis[25],d[25];

int BFS(int source,int destination)
{
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    vis[source]=1;
    d[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0;i<edge[top].size();i++)
        {
            int a=edge[top][i];
            if(!vis[a])
            {
                d[a]=d[top]+1;
                vis[a]=1;
                q.push(a);
            }
        }
    }

    return d[destination];
}
int main()
{
    int t=1;
    int a;
    //freopen("567.txt","r",stdin);
    while(scanf("%d",&a)!=EOF)
    {
        int b;
        for(int j=1;j<=a;j++)
        {

                scanf("%d",&b);
                edge[1].push_back(b);
                edge[b].push_back(1);
        }
        for(int i=2;i<20;i++)
        {

            scanf("%d",&a);
            for(int j=1;j<=a;j++)
            {

                scanf("%d",&b);
                edge[i].push_back(b);
                edge[b].push_back(i);
            }
        }
        int n;
        printf("Test Set #%d\n",t++);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int start,endP;
            scanf("%d %d",&start,&endP);
            printf("%2d to %2d: %d\n",start,endP,BFS(start,endP));
        }
        cout<<endl;
        for(int i=0;i<26;i++)
        edge[i].clear();
    }
}


