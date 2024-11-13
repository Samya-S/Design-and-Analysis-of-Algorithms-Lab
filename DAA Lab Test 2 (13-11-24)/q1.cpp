#include <bits/stdc++.h>
using namespace std;

int l, r;

int get(int a[], int i, int j) {
    if (i > j)
        return 0;

    int b1[j - i + 2], b2[j - i + 2];

    for (int k = 0; k < j - i + 2; k++) {
        b1[k] = INT_MAX, b2[k] = INT_MAX;
    }

    for (int k = j - i; k >= 0; k--) {
        if (a[k + i] == r)
            b1[k] = k;
        else
            b1[k] = b1[k + 1];
        if (a[k + i] == l)
            b2[k] = k;
        else
            b2[k] = b2[k + 1];
    }

    int ans = 0;

    for (int k = 0; k < j - i + 1; k++) {
        if (max(b1[k], b2[k]) == INT_MAX)
            break;
        ans += (j - i + 1) - (max(b1[k], b2[k]));
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> l >> r;

    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > r || a[i] < l) {
            ans += get(a, cur, i - 1);
            cur = i + 1;
        }
    }

    ans += get(a, cur, n - 1);
    cout << ans << endl;

    return 0;
}
