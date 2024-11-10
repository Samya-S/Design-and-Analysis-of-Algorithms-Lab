#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(v, 1e9);

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int dis = it.first;

        for (auto it : adj[node]) {
            int v = it[0];
            int wt = it[1];

            if (dis + wt < dist[v]) {
                dist[v] = dis + wt;
                pq.push({dis + wt, v});
            }
        }
    }

    return dist;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for (int i = 0; i < e; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adj[v1].push_back({v2, wt});
        adj[v2].push_back({v1, wt});
    }

    auto ans = dijkstra(v, adj, 0);

    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}