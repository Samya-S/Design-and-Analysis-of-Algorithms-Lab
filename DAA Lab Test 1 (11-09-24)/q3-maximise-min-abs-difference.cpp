#include <bits/stdc++.h>
using namespace std;

int minAbsDiff(vector<int> &a) {
    int n = a.size();

    sort(a.begin(), a.end());

    int minn = INT_MAX;

    for (int i = 1; i < n; i++) {
        minn = min(minn, a[i] - a[i - 1]);
    }

    return minn;
}

int maxScore(vector<int> &a, int d) {
    int n = a.size();

    if (n == 1)
        return 0;

    sort(a.begin(), a.end());

    int idealGap = (a[n - 1] + d - a[0]) / (n - 1);

    for (int i = 1; i < n; i++) {
        int val = a[i - 1] + idealGap;

        if (val > a[i] + d)
            val = a[i] + d;
        else if (val < a[i])
            val = a[i];

        a[i] = val;
    }

    int ans = minAbsDiff(a);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int d;
    cin >> d;

    cout << maxScore(a, d) << endl;

    return 0;
}