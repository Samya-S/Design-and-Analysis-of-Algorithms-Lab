#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a) {
    for (auto &it : a)
        cout << it << " ";
    cout << endl;
    return;
}

vector<int> counting_sort(vector<int> &a) {
    int n = a.size();

    int maxx = *max_element(a.begin(), a.end());
    vector<int> count(maxx + 1, 0);

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= maxx; i++) {
        count[i] += count[i - 1];
    }

    vector<int> b(n);
    for (int i = n - 1; i >= 0; i--) {
        b[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    return b;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans = counting_sort(a);

    print(ans);

    return 0;
}