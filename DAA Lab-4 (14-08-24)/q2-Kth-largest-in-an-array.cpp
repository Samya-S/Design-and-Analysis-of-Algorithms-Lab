#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];

    int l = left + 1;
    int r = right;

    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) {
            swap(arr[l], arr[r]);
            l++ ;
            r-- ;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }

    swap(arr[left], arr[r]);

    return r;
}

int find_Kth_largest(vector<int> &a, int k){
    int left = 0, right = a.size() - 1;

    while (left <= right) {
        int ind = partition(a, left, right);

        if (ind == k - 1) {
            return a[ind];
        }

        if (ind < k - 1) {
            left = ind + 1;
        } else {
            right = ind - 1;
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &it:a) 
        cin >> it;

    int k; 
    cin >> k;

    cout << find_Kth_largest(a, k) << endl;
    
    return 0;
}