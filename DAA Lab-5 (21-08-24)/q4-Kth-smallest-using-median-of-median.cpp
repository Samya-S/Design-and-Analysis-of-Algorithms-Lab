#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int> &a, int start, int n) {
    sort(a.begin() + start, a.begin() + start + n);
    return a[start + n / 2];
}

int partition(vector<int> &a, int low, int high, int pivot) {
    for (int i = low; i < high; i++) {
        if (a[i] == pivot) {
            swap(a[i], a[high]);
            break;
        }
    }

    int pivotValue = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (a[j] < pivotValue) {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[high]);

    return i;
}

int kthSmallest(vector<int> &a, int low, int high, int k) {
    if (low == high)
        return a[low];

    int n = high - low + 1;
    int numMedians = (n + 4) / 5;

    vector<int> medians(numMedians);

    for (int i = 0; i < numMedians; i++) {
        int groupStart = low + i * 5;
        int groupSize = min(5, n - i * 5);
        medians[i] = findMedian(a, groupStart, groupSize);
    }

    int medianOfMedians = (numMedians == 1) ? medians[0] : kthSmallest(medians, 0, numMedians - 1, numMedians / 2);

    int pivotIndex = partition(a, low, high, medianOfMedians);

    int length = pivotIndex - low + 1;

    if (length == k)
        return a[pivotIndex];
    else if (k < length)
        return kthSmallest(a, low, pivotIndex - 1, k);
    return kthSmallest(a, pivotIndex + 1, high, k - length);
}

int findKthSmallest(vector<int> &a, int k) {
    return kthSmallest(a, 0, a.size() - 1, k);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;

    cout << findKthSmallest(a, k) << endl;

    return 0;
}