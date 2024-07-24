#include <iostream>
using namespace std;

void sort(int a[], int n){
    int low=0, high=n-1, mid=0;
    
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low], a[mid]);
            low++; mid++;
        }
        else if(a[mid]==2){
            swap(a[mid], a[high]);
            high--;
        }
        else mid++;
    }

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