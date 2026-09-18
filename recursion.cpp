#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &visited, vector<vector<int>> &graph){
    visited[node] = true;
    cout<<node<<" ";
    for(int neighbor: graph[node]){
        if(!visited[neighbor]){
            DFS(neighbor, visited, graph);
        }
        
    }
}

int main(){

    int V, E;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    
    vector<vector<int>> graph(V);

    cout<<"Enter number of Edges: ";
    cin>>E;

    cout<<"Enter the edges (u v): "<<endl;

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    cout<<"Graph representation (Adjacency List): "<<endl;

    for(int i=0; i<V; i++){
        cout<<i<<" -> ";
        for(int neighbor: graph[i]){
            cout<<neighbor<<" ";
        }
        cout<<endl;
    }

    vector<bool> visited(V, false);

    int stNode;
    cout<<"Enter the starting node for DFS: ";
    cin>>stNode;

    DFS(stNode, visited, graph);

    bool connected = true;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            connected = false;
            break;
        }
    }
    cout<<endl;
    if(connected){
        cout<<"Graph is connected";
    }else{
        cout<<"Graph is not connected";
    }

    return 0;
}