#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph {
     // Number of vertices
    int V;
    // Pointer to adjacent vertices
    list<int> *adj;
    
    public:
        Graph(int n) {
            // Set number of vertices
            V = n;
            // Set the list with number of vertices
            adj = new list<int>[n];
        }
    
        void add_edge(int u, int v) {
            // Add from vertice u a path to v;
            adj[u].push_back(v);
        }
    
        vector<int> shortest_reach(int start) {
            // Created an array of booleans to mark if visited
            // ir not
            vector<int> distances;
            bool *visited = new bool[V];
            
            for (int i=0; i<V; i++) {
                visited[i] = false;
                distances.push_back(-1);
            }

            list<int> queue;

            visited[start] = true;
            queue.push_back(start);

            while (!queue.empty()) {
                // Get the front of queue
                start = queue.front();
                // Remove it from list
                queue.pop_front();

                cout << "Vertex " << start;
                // Get all adjacent vertices to traverse
                for (auto i = adj[start].begin(); i != adj[start].end(); i++) {
                    if (!visited[*i] ) {
                        cout << " - check - " << *i << " ";
                        // Mark as visited
                        cout << "Visit and enqueue" << *i << endl;
                        visited[*i] = true;
                        // Push back to check this vertex vertices
                        queue.push_back(*i);
                        
                    }
                }
            }
            cout << endl;
            return distances;

        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

