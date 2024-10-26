#include <bits/stdc++.h>
using namespace std;

void findMST(int v, vector<vector<int>> adj[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(v, 0);
    vector<vector<int>> mst;

    pq.push({0, {0, -1}});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;

        // cout << node << " " << parent << " " << wt << endl;

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;

        if (parent != -1)
            mst.push_back({node, parent});

        for (auto it : adj[node]) {
            int adjN = it[0];
            int edgW = it[1];

            if (!vis[adjN])
                pq.push({edgW, {adjN, node}});
        }
    }

    cout << "The sum of the edge weights of the MST is " << sum << endl;

    cout << "MST = {";
    for (auto it : mst) {
        cout << "{" << it[0] << ", " << it[1] << "}, ";
    }
    cout << "}" << endl;

    return;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    findMST(v, adj);

    return 0;
}