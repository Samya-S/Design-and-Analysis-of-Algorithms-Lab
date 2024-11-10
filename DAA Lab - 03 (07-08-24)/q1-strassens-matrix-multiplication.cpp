#include <bits/stdc++.h>
using namespace std;

// incomplete

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

vector<vector<int>> form(vector<vector<int>> &ae, vector<vector<int>> &bg, vector<vector<int>> &af, 
                        vector<vector<int>> &bh, vector<vector<int>> &ce, vector<vector<int>> &dg,
                        vector<vector<int>> &cf, vector<vector<int>> &dh){
    // int 
}

vector<vector<int>> strassensMultiplication(vector<vector<int>> &a, vector<vector<int>> &b,
                                            int ax1, int axn, int ay1, int ayn, int bx1, int bxn, int by1, int byn){
    // int n1 = a.size();
    // int m1 = a[0].size();
    // int n2 = b.size();
    // int m2 = b[0].size();
    int n1 = axn-ax1+1;
    int m1 = ayn-ay1+1;
    int n2 = bxn-bx1+1;
    int m2 = byn-by1+1;

    vector<vector<int>> ans(n1, vector<int>(m2));

    vector<vector<int>> AE = strassensMultiplication(a, b, ax1, axn/2, ay1, ayn/2, bx1, bxn/2, by1, byn/2);
    vector<vector<int>> BG = strassensMultiplication(a, b, ax1, axn/2, ayn/2+1, ayn, bxn/2+1, bxn, by1, byn/2);
    vector<vector<int>> AF = strassensMultiplication(a, b, ax1, axn/2, ay1, ayn/2, bx1, bxn/2, byn/2+1, byn);
    vector<vector<int>> BH = strassensMultiplication(a, b, ax1, axn/2, ayn/2+1, ayn, bxn/2+1, bxn, byn/2+1, byn);
    vector<vector<int>> CE = strassensMultiplication(a, b, axn/2+1, axn, ay1, ayn/2, bx1, bxn/2, by1, byn/2);
    vector<vector<int>> DG = strassensMultiplication(a, b, axn/2+1, axn, ayn/2+1, ayn, bxn/2+1, bxn, by1, byn/2);
    vector<vector<int>> CF = strassensMultiplication(a, b, axn/2+1, axn, ay1, ayn/2, bx1, bxn/2, byn/2+1, byn);
    vector<vector<int>> DH = strassensMultiplication(a, b, axn/2+1, axn, ayn/2+1, ayn, bxn/2+1, bxn, byn/2+1, byn);

    ans = form(AE, BG, AF, BH, CE, DG, CF, DH);

    return ans;
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
    ans = strassensMultiplication(a, b, 0, m1-1, 0, n1-1, 0, m2-1, 0, n2-1);

    print(ans);
    
    return 0;
}