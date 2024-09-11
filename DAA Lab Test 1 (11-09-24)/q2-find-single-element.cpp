#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &a) {
    int n = a.size();

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid & 1) {
            if (mid + 1 < n && a[mid] == a[mid + 1]) {
                high = mid - 1;
            } else if (mid - 1 >= 0 && a[mid] == a[mid - 1]) {
                low = mid + 1;
            } else {
                return a[mid];
            }
        } else {
            if (mid + 1 < n && a[mid] == a[mid + 1]) {
                low = mid + 2;
            } else if (mid - 1 >= 0 && a[mid] == a[mid - 1]) {
                high = mid - 2;
            } else {
                return a[mid];
            }
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << singleElement(a) << endl;

    return 0;
}