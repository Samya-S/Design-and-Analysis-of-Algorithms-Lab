#include <iostream>
using namespace std;

void findAndPrint(int a[], int n){
    int cnt1 = 0, cnt2 = 0;
    int e1 = -1e9, e2 = -1e9;

    for(int i=0; i<n; i++){
        if(cnt1 == 0 && e2 != a[i]){
            cnt1 = 1;
            e1 = a[i];
        }
        else if(cnt2 == 0 && e1 != a[i]){
            cnt2 = 1;
            e2 = a[i];
        }
        else if(a[i] == e1) cnt1++;
        else if(a[i] == e2) cnt2++;
        else{
            cnt1--; cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        if(a[i]==e1) cnt1++;
        if(a[i]==e2) cnt2++;
    }

    if(cnt1 > n/3) cout << e1 << " ";
    if(cnt2 > n/3) cout << e2 << endl;

    return;
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    // int arr[] = {0, 1, 1, 2, 0, 2, 1, 0};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    // print(arr, n);
    findAndPrint(arr, n);
    return 0;
}