#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100],reverseGraph[100];
bool vis[100];
void dfs(int s,int t){
    vis[s]=1;
    if(t==1){
        for(int i=0;i<graph[s].size();i++){
            int v=graph[s][i];
            if(!vis[v]){
                dfs(v,1);
            }
        }
    }
    else if(t==2){
        for(int i=0;i<reverseGraph[s].size();i++){
            int v=reverseGraph[s][i];
            if(!vis[v]){
                dfs(v,2);
            }
        }
    }

}
int main(){

    int node,edge,u,v;
    //freopen("input.txt","r+",stdin);
    freopen("kosaraju.txt","r+",stdin);
    cout<<"Enter the number of nodes and edge : ";
    cin>>node>>edge;
    cout<<endl;
    for(int i=0;i<edge;i++){

        cout<<"Enter edge between node u to v : ";
        cin>>u>>v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
        cout<<endl;
    }
    memset(vis,0,sizeof(vis));
    int s;
    cout<<"Enter the source node : ";
    cin>>s;
    cout<<endl;
    dfs(s,1);
    int flag=0;
    for(int i=0;i<node;i++){
        if(vis[i]==0){
            flag=1;
        }
    }
    if(flag==0){
        memset(vis,0,sizeof(vis));
        dfs(s,2);
        for(int i=0;i<node;i++){
            if(vis[i]==0){
                flag=1;
            }
        }
        if(flag==0){
            cout<<"The graph is strongly connected ."<<endl;
        }
        else{
            cout<<"The graph is not strongly connected."<<endl;
        }

    }
    else{
        cout<<"The graph is not strongly connected."<<endl;
    }
}
