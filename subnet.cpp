#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& key, vector<bool>& mstSet, int n) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void primMST(vector<vector<int>>& graph, int n) {
    vector<int> parent(n), key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMin(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Broadcast Tree (Minimum Spanning Tree):\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}

int main() {
    int n;
    cout << "Enter number of hosts: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    primMST(graph, n);
    return 0;
}
