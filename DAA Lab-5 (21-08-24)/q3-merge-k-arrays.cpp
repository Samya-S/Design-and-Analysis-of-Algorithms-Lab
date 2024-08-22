#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return;
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();

    vector<int> ans(n + m);

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }

    while (i < n)
        ans[k++] = a[i++];

    while (j < m)
        ans[k++] = b[j++];

    return ans;
}

vector<int> merge_k_arrays(vector<vector<int>> &a, int i, int j) {
    int k = j - i + 1;

    if (k == 1)
        return a[i];

    if (k == 2)
        return merge(a[i], a[j]);

    vector<int> temp1 = merge_k_arrays(a, i, i + k / 2);
    vector<int> temp2 = merge_k_arrays(a, i + k / 2 + 1, j);

    return merge(temp1, temp2);
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> a;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        vector<int> temp(n);
        for (int j = 0; j < n; j++)
            cin >> temp[j];

        a.push_back(temp);
    }

    vector<int> ans = merge_k_arrays(a, 0, k - 1);

    print(ans);

    return 0;
}