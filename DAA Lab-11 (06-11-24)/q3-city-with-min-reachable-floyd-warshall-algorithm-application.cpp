#include <bits/stdc++.h>
using namespace std;

void floydWarshallAlgorithm(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }

    return;
}

int findAns(vector<vector<int>>& dist, int distThreshHold) {
    int n = dist.size();

    int minReachable = n;
    int cityWithMinReachable = -1;

    for (int i = 0; i < n; i++) {
        int reachableCities = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distThreshHold) {
                reachableCities++;
            }
        }

        if (reachableCities < minReachable || (reachableCities == minReachable && i > cityWithMinReachable)) {
            minReachable = reachableCities;
            cityWithMinReachable = i;
        }
    }

    return cityWithMinReachable;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> matrix(v, vector<int>(v, -1));

    for (int i = 0; i < e; i++) {
        int u1, u2, wt;
        cin >> u1 >> u2 >> wt;
        matrix[u1][u2] = wt;
        matrix[u2][u1] = wt;
    }

    int distThreshHold;
    cin >> distThreshHold;

    floydWarshallAlgorithm(matrix);

    cout << "Ans: " << findAns(matrix, distThreshHold) << endl;

    return 0;
}