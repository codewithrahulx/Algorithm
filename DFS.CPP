#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
vector<bool>visited;

void DFS(int node){
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            DFS(neighbor);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    graph.resize(n);
    visited.resize(n , false);
    for(int i =0;i<m ;i++){
        int u , v;
        cin>>u>>v;

         graph[u].push_back(v);
         graph[v].push_back(u);
    }
    DFS(0);
}
