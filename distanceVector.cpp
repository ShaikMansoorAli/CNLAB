#include <iostream>
using namespace std;

#define INF 999
#define MAX 10

int main() {
    int cost[MAX][MAX];    
    int dist[MAX][MAX];    
    int nextHop[MAX][MAX]; 
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the cost matrix (use 999 for no direct link):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
            nextHop[i][j] = j;  
        }
    }

    
    for (int k = 0; k < n; k++) {        
        for (int i = 0; i < n; i++) {    
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        cout << "\nRouting table for Node " << i << ":\n";
        cout << "Destination\tNext Hop\tDistance\n";
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << j << "\t\t-\t\tINF\n";
            else
                cout << j << "\t\t" << nextHop[i][j] << "\t\t" << dist[i][j] << "\n";
        }
    }

    return 0;
}
