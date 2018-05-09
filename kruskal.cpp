#include<bits/stdc++.h>
using namespace std;
#define mx 1000
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii adjList[mx];
struct edge{
    int u,v,w;
    bool operator<(const edge& p)const{
        return w<p.w;
    }
};
vector <edge> e;
int parent[mx];
int findParent(int r)
{
    if(r==parent[r])
        return r;
    parent[r]=findParent(parent[r]);
    return parent[r];
}
int kruskal(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int cost=0,cnt=0;
    sort(e.begin(),e.end());
    for(int i=0;i<(int)e.size();i++)
    {
        int u=findParent(e[i].u);
        int v=findParent(e[i].v);
        if(u!=v)
        {
            parent[u]=v;
            cost+=e[i].w;
            cnt++;
        }
    }
    return cost;
}
int main()
{
    int node,ed;
    cout<<"Enter node and edge : ";
    cin>>node>>ed;

    for(int i=0;i<ed;i++)
    {
        int u,v,w;
        edge get;
        cout<<endl<<"Enter the node , adjasent node and cost : ";
        cin>>u>>v>>w;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);

    }
    cout<<endl<<"the cost of the minimum spanning tree is "<<kruskal(node)<<endl;

}
