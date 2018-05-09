#include<bits/stdc++.h>
using namespace std;
#define mx 1000
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii adjList[mx];
int taken[mx];
priority_queue<ii> pq;
int cost;
void process(int s)
{
    taken[s]=1;
    for(int i=0;i<adjList[s].size();i++)
    {
        ii f=adjList[s][i];
        if(!taken[f.first])
        {
            pq.push(ii(-f.second,f.first));
        }
    }
}
int prim()
{
    while(!pq.empty())
    {
        ii f=pq.top();
        pq.pop();
        int u=f.second;
        int w=-f.first;
        if(!taken[u])
        {
            cost+=w;
            process(u);
        }
    }
    return cost;
}
int main()
{

    int node,edge;
    cout<<"Enter node and edge : ";
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cout<<endl<<"Enter the node , adjasent node and cost : ";
        cin>>u>>v>>w;
        adjList[u].push_back(ii(v,w));
        adjList[v].push_back(ii(u,w));
    }
    memset(taken,0,sizeof taken);
    int source;
    cout<<endl<<"Enter the source node : ";
    cin>>source;
    cost=0;
    process(source);
    cout<<endl<<"the cost of the minimum spanning tree is "<<prim()<<endl;
}
