#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a) {
    for (auto &it : a) {
        cout << it << " ";
    }
    cout << endl;
}

void relativeSort(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();

    unordered_map<int, int> freq;

    for (auto &it : a) {
        freq[it]++;
    }

    int ind = 0;

    for (auto &it : b) {
        while (freq[it]) {
            a[ind++] = it;
            freq[it]--;
        }
        freq.erase(it);
    }

    vector<int> leftover;

    for (auto &pair : freq) {
        while (pair.second--) {
            leftover.push_back(pair.first);
        }
    }

    sort(leftover.begin(), leftover.end());

    for (auto &it : leftover) {
        a[ind++] = it;
    }

    return;
}

int main() {
    int m;
    cin >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    relativeSort(a, b);

    print(a);

    return 0;
}