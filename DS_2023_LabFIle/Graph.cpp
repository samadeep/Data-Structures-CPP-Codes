#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;
    vector<int>* adj;

    // Helper function for DFS traversal
    void DFSUtil(int v, vector<bool>& visited, vector<int>& trans_adj) {
        visited[v] = true;
        trans_adj.push_back(v);

        for (int i = 0; i < adj[v].size(); i++) {
            int neighbor = adj[v][i];
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited, trans_adj);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to get the transpose of the graph
    Graph getTranspose() {
        Graph transposed(V);

        // Traverse the original graph and add edges to transposed graph
        for (int v = 0; v < V; v++) {
            for (int i = 0; i < adj[v].size(); i++) {
                int neighbor = adj[v][i];
                transposed.addEdge(neighbor, v);
            }
        }

        return transposed;
    }

    // Function to perform Depth First Search traversal of the graph
    void DFS() {
        vector<bool> visited(V, false);

        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                vector<int> trans_adj;
                DFSUtil(v, visited, trans_adj);

                sort(trans_adj.begin(), trans_adj.end());
                cout << "Transposed adjacency list of vertex " << trans_adj[0] << ": ";

                for (int i = 0; i < trans_adj.size(); i++) {
                    cout << trans_adj[i] << " ";
                }

                cout << endl;
            }
        }
    }
};

int main() {

    int n; cin>>n;
    int a,b;
    Graph g(n);

    while(n--)
    {
        cin>>a>>b;
        g.addEdge(a,b);
    }

    
    // Graph g(4);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    cout << "Original adjacency list of the graph: " << endl;
    for (int v = 0; v < g.V; v++) {
        cout << "Vertex " << v << ": ";
        for (int i = 0; i < g.adj[v].size(); i++) {
            cout << g.adj[v][i] << " ";
        }
        cout << endl;
    }

    Graph transposed = g.getTranspose();
    cout << "Transpose of the graph: " << endl;
    for (int v = 0; v < transposed.V; v++) {
        cout << "Vertex " << v << ": ";
        for (int i = 0; i < transposed.adj[v].size(); i++) {
            cout << transposed.adj[v][i] << " ";
        }
        cout << endl;
    }

    cout << "Depth First Search traversal of the graph: " << endl;
    g.DFS();

    return 0;
}

