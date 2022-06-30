// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int findParent(int x){
        if(parent[x] == -1){
            return x;
        } 
        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y){
        int p1 = findParent(x);
        int p2 = findParent(y);

        if(p1 != p2){
            if(rank[p1] < rank[p2]){
                parent[p1] = p2;
                rank[p2] += rank[p1];
            } else {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
        }
    }
};

class Graph{
    int v;
    vector<vector<int>> edgeList;
public:
    Graph(int v){
        this->v = v;
    }
    void addEdge(int x, int y, int w){
        edgeList.push_back({w,x,y});
    }

    // Kruskal's Algorithm
    int kruskalsAlgo(){
        // sort the edge list acc. to weight of the edges.
        sort(edgeList.begin(), edgeList.end());

        DSU dsu(v);
        int ans = 0;
        for(auto edge: edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(dsu.findParent(x) != dsu.findParent(y)){
                dsu.unite(x,y);
                ans += w;
            }
        }
        return ans;
    }

};


int main() {
    // Graph g(4);
    // g.addEdge(0,1,1);
    // g.addEdge(1,3,3);
    // g.addEdge(3,2,4);
    // g.addEdge(2,0,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);
    int n,m; cin>>n>>m;
    Graph g(n);
    for(int i=0;i<n;i++){
        int x,y,w; cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }

    cout<<g.kruskalsAlgo()<<endl;
    return 0;
}

