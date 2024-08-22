// partially correct
// incorrect output for aaabbbccc

#include <bits/stdc++.h>
using namespace std;

string rearrange(string s) {
    int n = s.size();

    if (n == 1)
        return s;

    sort(s.begin(), s.end());

    int maxCnt = 0, cnt = 0;
    char maxC = s[0], currC = s[0];

    for (int i = 0; i < n; i++) {
        if (s[i] == maxC) {
            cnt++;
        } else {
            currC = s[i];
            cnt = 1;
        }

        if (cnt > maxCnt) {
            maxCnt = cnt;
            maxC = currC;
        }
    }

    // cout << maxC << " " << maxCnt << endl;

    string ans = "";

    if (maxCnt > (n + 1) / 2)
        return ans;

    for (int i = 0; i < n; i++)
        ans += "#";

    for (int i = 0, pos = 0; i < maxCnt; i++, pos += 2) {
        ans[pos] = maxC;
    }

    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == '#') {
            while (s[temp] == maxC)
                temp++;

            ans[i] = s[temp++];
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << rearrange(s) << endl;

    return 0;
}