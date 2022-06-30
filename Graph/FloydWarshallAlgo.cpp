// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

vector<vector<int>> floydWarshallAlgo(vector<vector<int>> &graph){
    int v = graph.size();
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(graph[i][j] == -1)
            graph[i][j] = INT_MAX;
         }
       }
    // Phases, in kth phase we include vertices (1,2,3...k) as intermediate vertices.
    for(int k=0;k<v;k++){
        // Iterate over entire 2D Matrix.
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                continue;
                // If vertex k is included, and can we minimise the graph?
                if(graph[i][j] > graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
    return graph;
}

int main() {


    return 0;
}

