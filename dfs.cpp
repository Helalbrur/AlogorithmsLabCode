#include<bits/stdc++.h>
using namespace std;
vector<int> edgeList[100];
bool vis[100];
bool dfs(int source,int d){
    memset(vis,0,sizeof(vis));
    vis[source]=true;
    stack <int> s;
    s.push(source);
    while(!s.empty()){
        int u=s.top();
        s.pop();
        if(u==d){
            return true;
        }
        for(int i=0;i<edgeList[u].size();i++){
            int v=edgeList[u][i];
            if(!vis[v]){
                s.push(v);
                vis[v]=true;
            }
        }
    }
    return false;
}
int main(){
    int node,edge,u,v;
    //freopen("bfs.txt","r+",stdin);
    cout<<"Enter the number of node and edge "<<endl;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
        cout<<"Enter edge u to v : ";
        cin>>u>>v;
        edgeList[u].push_back(v);
        edgeList[v].push_back(u);
        cout<<endl;
    }
    cout<<"Enter the number of query : ";
    int q;
    cin>>q;
    cout<<endl;
    for(int i=0;i<q;i++){
        cout<<"Enter source node and destination node : ";
        cin>>u>>v;
        cout<<endl;
        if(dfs(u,v)){
            cout<<"You can reach from "<<u<<" to "<<v<<endl;
        }
        else{
            cout<<"You can't reach from "<<u<<" to "<<v<<endl;
        }
    }

}
