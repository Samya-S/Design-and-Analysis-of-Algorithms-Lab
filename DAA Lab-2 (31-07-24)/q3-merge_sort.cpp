/* Implement Merge Sort recursively */

#include <bits/stdc++.h>
using namespace std;

void mergeSort(int i, int j, vector<int> &a){
    if(i==j) return;

    int mid = (i+j)/2;

    mergeSort(i, mid, a);
    mergeSort(mid+1, j, a);

    vector<int> temp;
    int x=i, y=mid+1;
    while(x <= mid && y <= j){
        if(a[x]<a[y]){
            temp.push_back(a[x++]);
        }
        else{
            temp.push_back(a[y++]);
        }
    }

    while(x <= mid) temp.push_back(a[x++]);
    while(y <= j) temp.push_back(a[y++]);

    for(int k=i; k<=j; k++){
        a[k] = temp[k-i];
    }

    return;
}

int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    mergeSort(0, n-1, a);

    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}