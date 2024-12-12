#include <iostream>
#include <climits>
using namespace std;

void printShortestPaths(int dist[], int V) {
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int findMinDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[6][6], int src, int V) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printShortestPaths(dist, V);
}

int main() {
    int graph[6][6] = {
        {0, 10, 0, 0, 15, 0},
        {10, 0, 20, 0, 0, 25},
        {0, 20, 0, 30, 0, 0},
        {0, 0, 30, 0, 5, 10},
        {15, 0, 0, 5, 0, 0},
        {0, 25, 0, 10, 0, 0}
    };

    int V = 6;
    int src = 0;

    dijkstra(graph, src, V);

    return 0;
}