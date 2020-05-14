#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph {
    int vertices; // Vertices
    list<int> *adjacencies; // Edges
    public:
        Graph(int n) {
            // 
            this->vertices = n; // Set number of vertices
            this->adjacencies = new list<int>[this->vertices]; // Create an adjacency list
        }
    
        void add_edge(int u, int v) {
            cout << "Adding " << u << " to " << v << endl;
            this->adjacencies[u].push_back(v);
        }
    
        vector<int> shortest_reach(int start) {
            // BFS implementation with track
            // Create a visited boolean track
            vector<int> distances;
            for (int i = 0; i<this->vertices; i++) {
                distances.push_back(-1);
            }
            // Create a queue
            list<int> queue;
            // Put the start on queue
            queue.push_back(start);
            distances[start] = 0;
            // and mark as visited
            while (!queue.empty()) {
                int s = queue.front();
                queue.pop_front();
                //cout << "s" << endl;
                // From the start vertice, get all vertices on adjacencies
                for (auto i: this->adjacencies[s]) {
                    if (distances[i] == -1) {
                        distances[i] = distances[s] + 6;
                        queue.push_back(i);
                    }
                }
            }
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
