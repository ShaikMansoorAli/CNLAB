#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int n, int src, vector<vector<int>>& cost) {
    vector<int> dist(n, INT_MAX);      
    vector<bool> visited(n, false);    
    vector<int> parent(n, -1);         

    dist[src] = 0; 

    for (int count = 0; count < n - 1; ++count) {
        
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        
        for (int v = 0; v < n; ++v) {
            if (cost[u][v] && !visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "To " << i << " : " << dist[i] << endl;

    
    cout << "\nShortest Paths:\n";
    for (int i = 0; i < n; ++i) {
        if (i == src) continue;
        cout << "Path to " << i << ": " << i;
        int j = i;
        while (parent[j] != -1) {
            cout << " <- " << parent[j];
            j = parent[j];
        }
        cout << endl;
    }
}

int main() {
    int n, src;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter cost adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    cout << "Enter source vertex (0-based index): ";
    cin >> src;

    dijkstra(n, src, cost);
    return 0;
}
