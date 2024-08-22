#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return;
}

void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }

    return;
}

void buildHeap(vector<int> &a) {
    int n = a.size();

    // last non-leaf node index
    int startInd = (n / 2) - 1;

    for (int i = startInd; i >= 0; i--) {
        heapify(a, n, i);
    }

    return;
}

void heapSort(vector<int> &a) {
    int n = a.size();

    buildHeap(a);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }

    return;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a);

    print(a);

    return 0;
}