#include <bits/stdc++.h>
using namespace std;

int countSubStrings(string &s) {
    int ans = 0;

    map<pair<int, int>, int> mpp;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    mpp[{0, 0}] = 1;

    for (auto it : s) {
        if (it == '0') cnt0++;
        if (it == '1') cnt1++;
        if (it == '2') cnt2++;

        ans += mpp[{cnt0 - cnt1, cnt1 - cnt2}];

        mpp[{cnt0 - cnt1, cnt1 - cnt2}]++;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << countSubStrings(s) << endl;

    return 0;
}
