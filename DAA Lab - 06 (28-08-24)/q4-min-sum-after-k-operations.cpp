#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int binary_exponentiation(int x, int n) {
    int ans = 1, k = x;

    while (n) {
        if (n % 2)
            ans = ans * (k % MOD) % MOD;

        k = ((k % MOD) * (k % MOD)) % MOD;

        n /= 2;
    }

    return ans;
}

int min_sum(vector<int> &a, int k, int m) {
    int n = a.size();

    multiset<int> ms;

    for (auto &it : a)
        ms.insert(it);

    while (k > 0 && (*ms.begin() * m < *ms.rbegin())) {
        int it = *ms.begin();
        ms.erase(ms.find(it));
        ms.insert(it * m);
        k--;
    }

    auto x = ms.begin();
    for (auto &it : a) {
        it = *(x++);
    }

    for (auto &it : a) {
        it = (it * binary_exponentiation(m, k / n)) % MOD;
    }

    for (int i = 0; i < k % n; i++) {
        a[i] = (a[i] * m) % MOD;
    }

    int sum = 0;
    for (auto &it : a) {
        sum = (sum + it) % MOD;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k, m;
    cin >> k >> m;

    cout << min_sum(a, k, m) << endl;

    return 0;
}