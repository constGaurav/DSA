// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

vector<int> bellmanFordSSSPAlgo(int n, int src, vector<vector<int>>&edges){
    // create a vector
    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;

    // relax all edges n-1 times
    for(int i=0;i<n-1;i++){
        bool notUpdate = true;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INT_MAX and dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                notUpdate = false;
            }
        }
        if(notUpdate) break;
    }

    // Negative weight cycle
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(dist[u] != INT_MAX and dist[u]+w < dist[v]){
            cout<<"Negative Weight Cycle is Present.";
            exit(0);
        }
    }

    return dist;
}

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> edges; //(a,b,3),(c,d,2),.......
    
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }



    return 0;
}

