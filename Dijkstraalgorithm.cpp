#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin>>n>>m;

    vector<vector<pair<int , int >>>graph(n);

    for(int i =0;i<m;i++){
        int u , v , w;
        cin>>u>>v>>w;

        graph[u].push_back({v , w});
        graph[v].push_back({u, w});

    }
    int source;
    cin>>source;
    vector<int>dist(n , INT_MAX);
    vector<bool>visited(n , false);
    dist[source]=0;
    for(int i =0;i<n;i++){
       int u=-1;
        for(int j=0;j<n;j++){
            if(!visited[j] && (u==-1 || dist[j] < dist[u])) u=j;
        }
        if(dist[u] == INT_MAX) break;
        visited[u]= true;

    for(auto edge : graph[u]){
        int v=edge.first;
        int w=edge.second;
        if(dist[u]+w<dist[v]){
            dist[v]=dist[u]+w;
        }
    }
    }
    for(int i =0;i<n;i++){
        if(dist[i] == INT_MAX) cout<<"INF";
        else cout<<dist[i]<<" ";
    }
}
