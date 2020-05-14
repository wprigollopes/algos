#include <bits/stdc++.h>

using namespace std;
const int INF = -1;
vector<string> split_string(string);

// Construct a graph
class Graph {
    public:
        // Number of vertices
        int v;
        // Adjacencies pair <dest, weight>
        list<pair<int, int>> *adj;

        // Constructor
        Graph(int v) {
            // Set the size of graph
            this->v = v;
            // Set the set of adjacencies
            adj = new list<pair<int, int>>[v*2];
        }

        void addEdge(int u, int v, int weight) {
            this->adj[u].push_back({v, weight});
        }
};

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    Graph* graph = new Graph(edges.size());
    for (int i=0; i<edges.size(); i++) {
        graph->addEdge(edges[i][0]-1, edges[i][1]-1, edges[i][2]);
        graph->addEdge(edges[i][1]-1, edges[i][0]-1, edges[i][2]);
    }
    // Create a vector of distance;
    vector<int> distances(n, -1);
    
    // Create a set from to nodes to be used on 
    set<pair<int, int>> extract_set;

    // Add to pair, the start from start
    extract_set.insert({s-1, s-1});
    // Distance from the starting point is 0
    distances[s-1] = 0;

    // Now, do BFS
    while (!extract_set.empty()) {
        // Get element from begin 
        pair<int, int> curr = (*extract_set.begin());
        // And erase it
        extract_set.erase(extract_set.begin());

        // Get the vertex end. 
        int u = curr.second;

        // Get the adjacency list from the vertex and traverse it
        // The queue uses BFS concept, so, it's ok to continue
        for (auto edge = graph->adj[u].begin(); edge != graph->adj[u].end(); edge++) {
            // Get the destination
            int v = edge->first;
            // And get the weight
            int weight = edge->second;

            // Check the distances between two points on edge
            if ((distances[v] == -1) || (distances[v] > distances[u] + weight)) {
                
                // Here, remove the current distance if is in the set
                if (distances[v] != -1) {
                    extract_set.erase(extract_set.find({distances[v], v}));
                }

                // Update the distances from a certain point to another point here
                // If INF, so, put from origin to end adding the weight
                distances[v] = distances[u] + weight;
                extract_set.insert({distances[v], v});
            }
            
        }
    }
    // Remove the first distance
    distances.erase(distances.begin()+i-1);
    return distances;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
