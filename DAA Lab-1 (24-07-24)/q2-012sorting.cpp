#include <iostream>
using namespace std;

void sort(int a[], int n){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0) cnt0++;
        if(a[i]==1) cnt1++;
        if(a[i]==2) cnt2++;
    }

    int i=0;
    while(cnt0--) a[i++]=0;
    while(cnt1--) a[i++]=1;
    while(cnt2--) a[i++]=2;

    return;
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    // int arr[] = {0, 1, 1, 2, 0, 2, 1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    // print(arr, n);
    sort(arr, n);
    print(arr, n);
    return 0;
}