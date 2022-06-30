// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *adj;
public:
    Graph(int v){
        this->v = v;
        adj = new list<pair<int,int>>[v];
    }
    void addEdge(int x, int y, int w){
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    void dijkstraAlgo(int src){
        // Single source shorted Path.
        vector<int> dist(v,1e9);
        dist[src] = 0;

             // dist node
        set<pair<int,int>> s;
        s.insert({0,src});

        while(!s.empty()){
            auto p = *(s.begin());
            int nodeDist = p.first;
            int node = p.second;
            s.erase(s.begin());

            for(auto nbr: adj[node]){
                if(nodeDist + nbr.second < dist[nbr.first]){
                    auto f = s.find({dist[nbr.first], nbr.first});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr.first] = nodeDist + nbr.second;
                    s.insert({dist[nbr.first], nbr.first});
                }
            }
        }

        for(int i=0;i<v;i++){
            cout<<"Distance of "<<i<<" from "<<src<<" : "<<dist[i]<<endl;
        }

    }

};


int main() {
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,3,1);
    g.addEdge(1,2,4);
    g.addEdge(3,2,3);
    g.addEdge(1,4,5);
    g.addEdge(2,4,1);

    g.dijkstraAlgo(0);

    return 0;
}

