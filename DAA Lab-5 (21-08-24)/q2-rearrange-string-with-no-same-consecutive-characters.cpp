#include <bits/stdc++.h>
using namespace std;

string rearrange(string s) {
    int n = s.size();

    if (n == 1)
        return s;

    unordered_map<char, int> mp;
    for (auto i : s) {
        mp[i]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto it : mp) {
        pq.push({it.second, it.first});
    }

    string ans = "";

    int maxCnt = pq.top().first;
    if (maxCnt > (n + 1) / 2)
        return ans;

    while (!pq.empty()) {
        auto i = pq.top();
        pq.pop();

        if (pq.empty()) {
            ans += i.second;
            break;
        }

        auto j = pq.top();
        pq.pop();

        i.first--;
        j.first--;

        ans += i.second;
        ans += j.second;

        if (i.first > 0)
            pq.push({i.first, i.second});
        if (j.first > 0)
            pq.push({j.first, j.second});
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << rearrange(s) << endl;

    return 0;
}