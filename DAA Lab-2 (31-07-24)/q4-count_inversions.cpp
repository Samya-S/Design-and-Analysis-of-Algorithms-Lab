/* Bonus Q: Count inversions in a array i.e. no, of inversions from being sorted */

#include <bits/stdc++.h>
using namespace std;


// brute force way [TC: O(n*n)]
int inversionCount(vector<int> &a){
    int n = a.size();

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]) cnt++;
        }
    }

    return cnt;
}


// optimal way [TC: O(n*log n)]
// using mergeSort approach
int mergeSortCnt(int i, int j, vector<int> &a){
    int cnt = 0;
    if(i>=j) return cnt;

    int mid = (i+j)/2;

    cnt += mergeSortCnt(i, mid, a);
    cnt += mergeSortCnt(mid+1, j, a);

    vector<int> temp;
    int x=i, y=mid+1;
    while(x <= mid && y <= j){
        if(a[x] <= a[y]){
            temp.push_back(a[x++]);
        }
        else{
            temp.push_back(a[y++]);
            cnt += (mid - x + 1);
        }
    }

    while(x <= mid) temp.push_back(a[x++]);
    while(y <= j) temp.push_back(a[y++]);

    for(int k=i; k<=j; k++){
        a[k] = temp[k-i];
    }

    return cnt;
}

int inversionCount2(vector<int> &a){
    int n = a.size();

    return mergeSortCnt(0, n-1, a);
}


// main function
int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    cout << inversionCount2(a) << endl;

    return 0;
}