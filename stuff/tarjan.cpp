#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        int id = 0;
        vector<int> ids;
        vector<int> low;
        vector<bool> visited;
        
        unordered_map<int, vector<int>> graph;
    
        void convert(vector<vector<int>> connections) {
            for (vector<int> conn: connections) {
                if (graph.find(conn[0]) == graph.end()) {
                graph.insert({conn[0],{conn[1]}});
                } else {
                    graph[conn[0]].push_back(conn[1]);
                }
            }
        }
    
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            // Convert connections
            convert(connections);
            ids = vector<int>(n, 0);
            low = vector<int>(n, 0);
            visited = vector<bool>(n, false);
            
            vector<vector<int>> bridges;
            
            for (int i=0; i<=n; i++) {
                if (!visited[i]) {
                    dfs(i, -1, &bridges);
                }
            }
            return bridges;
        }
    
        void dfs(int at, int parent, vector<vector<int>> *bridges) {
            visited[at] = true;
            id++;
            low[at] = ids[at] = id;
            
            for (auto to: graph[at]) {
                if (to == parent) {
                    continue;
                }
                if (!visited[to]) {
                    dfs(to, at, bridges);
                    low[at] = min(low[at], low[to]);
                    if (ids[at] < low[to]) {
                        bridges->push_back({at, to});
                    }
                } else {
                    low[at] = min(low[at], ids[to]);
                }
            }
            return;
        }
};

int main() {
    int n = 5;
    vector<vector<int>> connections = {{1,0},{2,0},{3,2},{4,2},{4,3},{3,0},{4,0}};
    Solution solution;

    vector<vector<int>> bridges = solution.criticalConnections(n, connections);
    for (int i=0; i<bridges.size(); i++) {
        cout << "Bridges: " << bridges[i][0] << " - " << bridges[i][1] << endl;
    }

}