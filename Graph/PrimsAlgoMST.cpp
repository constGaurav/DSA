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

    int primsAlgoLessEfficient(){
        // TC: O(N*N)
        int parent[v];
        int key[v];
        bool mstSet[v];

        for(int i=0;i<v;i++){
            key[i] = INT_MAX,
            mstSet[i] = false,
            parent[i] = -1;
        }

        key[0] = 0;
        parent[0] = -1;

        for(int i=0;i<v-1;i++){
            int mini = INT_MAX, node;

            for(int j=0;j<v;j++){
                if(mstSet[j]==false && key[j]<mini)
                    mini = key[j], node = j;
            }
            
            mstSet[node] = true;
            for(auto it: adj[node]){
                int n = it.first;
                int nWt = it.second;
                if(mstSet[n]==false && nWt < key[n])
                    parent[n] = node, key[n] = nWt;          
            }
        }

        for(int i=1;i<v;i++){
            cout<<parent[i]<<" - "<<i<<endl;
        }

        int sum = 0;
        for(int i=0;i<v;i++){
            sum += key[i];
        }
        return sum;
    }


    int primsAlgoMoreEfficient(){
        // TC: O(NlogN)
        int parent[v];
        int key[v];
        bool mstSet[v];

        for(int i=0;i<v;i++){
            key[i] = INT_MAX,
            mstSet[i] = false,
            parent[i] = -1;
        }

        key[0] = 0;
        parent[0] = -1;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<v-1;i++){
            int node = pq.top().second;
            pq.pop();
            
            mstSet[node] = true;
            
            for(auto it: adj[node]){
                int n = it.first;
                int nWt = it.second;
                if(mstSet[n]==false && nWt < key[n])
                    parent[n] = node;
                    pq.push({key[n],n});
                    key[n] = nWt;          
            }
        }

        for(int i=1;i<v;i++){
            cout<<parent[i]<<" - "<<i<<endl;
        }
        int sum = 0;
        for(int i=0;i<v;i++){
            sum += key[i];
        }
        return sum;
    }

};


int main() {
    Graph g(3);
    g.addEdge(0,1,5);
    g.addEdge(0,2,1);
    g.addEdge(2,1,3);

    cout<<endl<<g.primsAlgoLessEfficient();

    return 0;
}

