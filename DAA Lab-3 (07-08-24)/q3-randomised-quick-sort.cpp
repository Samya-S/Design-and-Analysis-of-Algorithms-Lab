#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a){
    for(auto it:a)
        cout << it << " ";
    cout << endl;
}

int partition(vector<int> &a, int i, int j){
    int n = j-i+1;
    int pivotInd = rand() % n + i;

    swap(a[i], a[pivotInd]);

    int low = i, high = j;

    while(low < high){
        while(a[low] <= a[i] && low <= j-1)
            low++;
        while(a[high] > a[i] && high >= i+1)
            high--;

        if(low < high) swap(a[low], a[high]);
    }

    swap(a[i], a[high]);
    return high;
}

void randomisedQuickSort(vector<int> &a, int i, int j){
    if(i>=j) return;

    int pivot = partition(a, i, j);

    randomisedQuickSort(a, i, pivot-1);
    randomisedQuickSort(a, pivot+1, j);

    return;
}

int main(){
    int n; cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    randomisedQuickSort(a, 0, n-1);

    print(a);

    return 0;
}