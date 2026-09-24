#include<bits/stdc++.h>
using namespace std;

int primsAlgo(int V, vector<vector<int>> graph[], int stNode){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    int minCost = 0;
    pq.push({0, stNode});
    while(!pq.empty()){
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        minCost += wt;
        for(auto neighbor: graph[u]){
            int v = neighbor[0];
            int weight = neighbor[1];
            if(!visited[v]){
                pq.push({weight, v});
            }
        }
    }
    return minCost;
}

int main(){

    int V = 4;

    vector<vector<int>> graph[V]; //Array of vectors

    graph[0].push_back({1, 1});
    graph[1].push_back({0, 1});

    graph[1].push_back({2, 4});
    graph[2].push_back({1, 4});

    graph[2].push_back({3, 7});
    graph[3].push_back({2, 7});

    graph[3].push_back({0, 2});
    graph[0].push_back({3, 2});

    int stNode;
    cout<<"Enter starting node: ";
    cin>>stNode;

    cout<<"Minimum cost: "<<primsAlgo(V, graph, stNode);

    return 0;
}