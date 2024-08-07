#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n1,m1;
    cin >> m1 >> n1;

    vector<vector<int>> a(m1, vector<int>(n1));
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            cin >> a[i][j];
        }
    }

    int n2,m2;
    cin >> m2 >> n2;

    vector<vector<int>> b(m2, vector<int>(n2)); 
    for(int i=0; i<m2; i++){
        for(int j=0; j<n2; j++){
            cin >> b[i][j];
        }
    }

    if(n1 != m2){
        cout << "Matrix multipication not possible!" << endl;
        return 0;
    }

    vector<vector<int>> ans(m1, vector<int>(n2));

    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            int val=0;
            for(int x=0; x<n1; x++) 
                val += a[i][x]*b[x][j];
            ans[i][j] = val;
        }
    }

    print(ans);
    
    return 0;
}