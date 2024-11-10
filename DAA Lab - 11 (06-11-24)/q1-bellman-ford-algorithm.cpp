#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFordAlgorithm(int v, vector<vector<int>>& edges, int s) {
    vector<int> dist(v, 1e9);
    dist[s] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }

    return dist;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int u1, u2, wt;
        cin >> u1 >> u2 >> wt;
        edges.push_back({u1, u2, wt});
    }

    vector<int> dist = bellmanFordAlgorithm(v, edges, 0);

    for (auto it : dist) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}