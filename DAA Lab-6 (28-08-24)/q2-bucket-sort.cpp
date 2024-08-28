#include <bits/stdc++.h>
using namespace std;

void print(vector<double> &a) {
    for (auto &it : a)
        cout << it << " ";
    cout << endl;
    return;
}

void bucket_sort(vector<double> &a) {
    int n = a.size();

    vector<vector<double>> bucket(n);

    for (int i = 0; i < n; i++) {
        int hash = n * a[i];
        bucket[hash].push_back(a[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int ind = 0;
    for (int i = 0; i < n; i++) {
        for (auto &it : bucket[i]) {
            a[ind++] = it;
        }
    }

    return;
}

int main() {
    int n;
    cin >> n;

    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bucket_sort(a);

    print(a);

    return 0;
}