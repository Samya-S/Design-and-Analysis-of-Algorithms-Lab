#include <bits/stdc++.h>
using namespace std;

string minimumWindow(string &s, string &t) {
    int m = s.length();
    int n = t.length();

    if (m < n)
        return "";

    unordered_map<char, int> hashS, hashT;

    for (auto &it : t) {
        hashT[it]++;
    }

    int start = 0, start_ind = -1, min_len = INT_MAX;

    int count = 0;

    for (int i = 0; i < m; i++) {
        hashS[s[i]]++;

        if (hashT[s[i]] != 0 && hashS[s[i]] <= hashT[s[i]])
            count++;

        if (count == n) {
            while (hashS[s[start]] > hashT[s[start]] || hashT[s[start]] == 0) {
                if (hashS[s[start]] > hashT[s[start]])
                    hashS[s[start]]--;
                start++;
            }

            int len = i - start + 1;

            if (min_len > len) {
                min_len = len;
                start_ind = start;
            }
        }
    }

    if (start_ind == -1)
        return "";

    return s.substr(start_ind, min_len);
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << minimumWindow(s, t) << endl;

    return 0;
}