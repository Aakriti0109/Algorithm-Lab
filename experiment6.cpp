//Objective: 
// 

#include <bits/stdc++.h> 

using namespace std; 

  

int Parent[100]; 

  

class Edge { 

public: 

    int u, v, weight; 

}; 

  

int comparator(Edge a, Edge b) { 

    return a.weight < b.weight; 

} 

  

int findParent(int x) { 

    if (Parent[x] == x) { 

        return x; 

    } 

    return findParent(Parent[x]); 

} 

  

void unite(int u, int v) { 

    u = findParent(u); 

    v = findParent(v); 

    Parent[u] = v; 

} 

  

int main() { 

    int V = 4; 

  

    vector<Edge> edges = { 

        {0, 1, 10}, 

        {0, 2, 6}, 

        {0, 3, 5}, 

        {1, 3, 4}, 

        {2, 3, 3} 

    }; 

  

    sort(edges.begin(), edges.end(), comparator); 

  

    for (int i = 0; i < V; i++) { 

        Parent[i] = i; 

    } 

  

    int cost = 0; 

    int count = 0; 

  

    for (Edge e : edges) { 

        if (findParent(e.u) != findParent(e.v)) { 

            cout << e.u << " - " << e.v << " = " << e.weight << endl; 

            cost += e.weight; 

            unite(e.u, e.v); 

            count++; 

  

            if (count == V - 1) { 

                break; 

            } 

        } 

    } 

  

    cout << "Cost: " << cost; 

  

    return 0; 

} 