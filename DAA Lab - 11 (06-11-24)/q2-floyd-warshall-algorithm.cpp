#include <bits/stdc++.h>
using namespace std;

void floydWarshallAlgorithm(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
            if(i==j) matrix[i][j] = 0;
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }

    return;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> matrix(v, vector<int> (v, -1));

    for(int i=0; i<e; i++) {
        int u1, u2, wt;
        cin >> u1 >> u2 >> wt;
        matrix[u1][u2] = wt;
        matrix[u2][u1] = wt;
    }

    floydWarshallAlgorithm(matrix);

    for(auto row:matrix){
        for(auto cell:row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}