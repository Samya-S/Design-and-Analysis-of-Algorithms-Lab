#include <iostream>
using namespace std;

void insertionSort(int ind, int a[], int n){
    if(ind==n) return;
    int key = a[ind];
    int j = ind-1;

    while(j>=0 && a[j] > key){
        a[j+1] = a[j];
        j--;
    }

    a[j+1] = key;
    insertionSort(ind+1, a, n);
    return;
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    // int arr[] = {4, 5, 3, 7, 1, 2, 6};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    // print(arr, n);
    insertionSort(1, arr, n);
    print(arr, n);
    return 0;
}