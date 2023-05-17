#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000; // maximum number of vertices

// Graph class using adjacency matrix
class Graph {
private:
    int V; // number of vertices
    int adj[MAX][MAX]; // adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        // initialize all matrix elements to 0
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    // function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u][v] = 1;
    }

    // function to print the adjacency matrix
    void printMatrix() {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // function to get the transpose of the graph
    Graph getTranspose() {
        Graph g(V);

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                g.adj[j][i] = adj[i][j];
            }
        }

        return g;
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


    // print the adjacency matrix of the graph
    cout << "Adjacency matrix of the original graph:" << endl;
    g.printMatrix();

    // get the transpose of the graph
    Graph t = g.getTranspose();

    // print the adjacency matrix of the transpose
    cout << "Adjacency matrix of the transpose:" << endl;
    t.printMatrix();

    return 0;
}
