//To implement Dijkstra's Algorithm using a Min-Heap Priority Queue in C++ and find the shortest distance from a source vertex to all other vertices in a weighted graph. 

 

#include <iostream> 

#include <vector> 

#include <queue> 

 

using namespace std; 

 

class Solution { 

public: 

    // Function to find the shortest distance of all the vertices 

    // from the source vertex S. 

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) { 

        // 1. Min-Heap Priority Queue to store {distance, node} 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

 

        // 2. Result array to store the shortest distance from source to all other nodes 

        // Initialized with a very large value (infinity) 

        vector<int> result(V, 1e9);  

 

        // 3. Distance from Source to Source is always 0 

        result[S] = 0; 

        pq.push({0, S});  

 

        // 4. Process nodes using BFS-like traversal 

        while (!pq.empty()) { 

            int d = pq.top().first;      // Current shortest distance to 'node' 

            int node = pq.top().second;  // Current node 

            pq.pop(); 

 

            // 5. Check all neighbors of the current node 

            for (auto &vec : adj[node]) { 

                int adjNode = vec[0]; // Neighbor node 

                int dist = vec[1];    // Edge weight between 'node' and 'adjNode' 

 

                // 6. Relaxation Step: If we find a shorter path to adjNode 

                if (d + dist < result[adjNode]) { 

                    result[adjNode] = d + dist;          // Update the shortest distance 

                    pq.push({d + dist, adjNode});        // Push updated distance and node to Min-Heap 

                } 

            } 

        } 

 

        return result; 

    } 

}; 

 

int main() { 

    // Number of vertices (0, 1, 2) 

    int V = 3;  

     

    // Source node (as discussed in the video example) 

    int S = 2;  

 

    // Adjacency list representation 

    // An array of vectors, where each element is a vector representing [neighbor, weight] 

    vector<vector<int>> adj[V]; 

 

    // Building the undirected graph 

     

    // Edge between Node 0 and Node 1 with weight 1 

    adj[0].push_back({1, 1}); 

    adj[1].push_back({0, 1}); 

 

    // Edge between Node 0 and Node 2 with weight 6 

    adj[0].push_back({2, 6}); 

    adj[2].push_back({0, 6}); 

 

    // Edge between Node 1 and Node 2 with weight 3 

    adj[1].push_back({2, 3}); 

    adj[2].push_back({1, 3}); 

 

    // Instantiate the Solution class and call dijkstra 

    Solution obj; 

    vector<int> shortest_distances = obj.dijkstra(V, adj, S); 

 

    // Print the results 

    cout << "Shortest distances from Source Node " << S << ":\n"; 

    cout << "----------------------------------------\n"; 

     

    for (int i = 0; i < V; i++) { 

        cout << "To Node " << i << " -> Distance: "; 

        if (shortest_distances[i] == 1e9) { 

            cout << "Unreachable\n"; 

        } else { 

            cout << shortest_distances[i] << "\n"; 

        } 

    } 

 

    return 0; 

}        