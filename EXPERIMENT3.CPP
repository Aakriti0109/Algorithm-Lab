#include <bits/stdc++.h>
using namespace std;

class Un_WeightedGraph
{
    int V, E;

public:

    void un_weighted_directed_matrix()
    {
        cout << "Enter vertices and edges for Directed Graph: ";
        cin >> V >> E;

        vector<vector<int>> Admat(V, vector<int>(V, 0));

        cout << "Enter (u v):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            Admat[u][v] = 1;
        }

        cout << "\nDirected Graph Adjacency Matrix\n";

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                cout << Admat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void un_weighted_undirected_matrix()
    {
        cout << "\nEnter vertices and edges for Undirected Graph: ";
        cin >> V >> E;

        vector<vector<int>> Admat(V, vector<int>(V, 0));

        cout << "Enter (u v):\n";

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            Admat[u][v] = 1;
            Admat[v][u] = 1;
        }

        cout << "\nUndirected Graph Adjacency Matrix\n";

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                cout << Admat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Un_WeightedGraph wg;

    wg.un_weighted_directed_matrix();

    cout << endl;

    wg.un_weighted_undirected_matrix();

    return 0;
}