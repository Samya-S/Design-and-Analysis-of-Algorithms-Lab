#include <bits/stdc++.h>
using namespace std;

int at_most_k_diff_elements(vector<int> &a, int k) {
    int n = a.size();

    int count = 0, left = 0, right = 0;

    unordered_map<int, int> mpp;

    while (right < n) {
        if (mpp.find(a[right]) == mpp.end())
            mpp[a[right]] = 0;

        mpp[a[right]]++;

        while (mpp.size() > k) {
            mpp[a[left]]--;

            if (mpp[a[left]] == 0)
                mpp.erase(a[left]);

            left++;
        }

        count += (right - left);

        right++;
    }

    return count;
}

int count_good_subarrays(vector<int> &a, int k) {
    return at_most_k_diff_elements(a, k) - at_most_k_diff_elements(a, k - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;

    cout << count_good_subarrays(a, k) << endl;

    return 0;
}