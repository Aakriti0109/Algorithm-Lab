#include<bits/stdc++.h>
using namespace std;

void BFS(int stNode, vector<vector<int>> &graph, int V){
    vector<bool> visited(V, false);
    queue<int> q;
    visited[stNode] = true;
    q.push(stNode);
    cout<<"Nodes Reachable \n";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){

    int V, E;
    cout<<"Enter number of Vertices: ";
    cin>>V;

    vector<vector<int>> graph(V);

    cout<<"Enter number of Edge: ";
    cin>>E;

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        //Undirected Graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<endl<<"Graph Representation: "<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<": ";
        for(int neighbor: graph[i]){
            cout<<neighbor<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    int stNode;
    cout<<endl<<"Enter Starting Node: ";
    cin>>stNode;

    cout<<endl;
    BFS(stNode, graph, V);

    return 0;
}