#include <bits/stdc++.h>
using namespace std;

int maxSpeed(int v, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>> pq;

    vector<int> maxSp(v, 0);

    maxSp[0] = 1e9;
    pq.push({1e9, 0});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int currSp = it.first;

        if(node == v-1)
            return currSp;

        for(auto it:adj[node]) {
            int v = it[0];
            int speedLimit = it[1];
            int pathSpeed = min(currSp, speedLimit);

            if(pathSpeed > maxSp[v]) {
                maxSp[v] = pathSpeed;
                pq.push({pathSpeed, v});
            }
        }
    }

    return 0;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];

    for(int i=0; i<e; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adj[v1-1].push_back({v2-1, wt});
        adj[v2-1].push_back({v1-1, wt});
    }

    cout << maxSpeed(v, adj) << endl;

    return 0;
}