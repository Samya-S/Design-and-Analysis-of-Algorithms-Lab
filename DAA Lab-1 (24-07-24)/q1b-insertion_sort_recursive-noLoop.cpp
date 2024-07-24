#include <iostream>
using namespace std;

int bk;

void recursion(int a[], int i, int j, int key){
    if(j>=0 && a[j]>key){
        a[j+1] = a[j];
        j--;
        bk = j;
        recursion(a,i,j,key);
    }
    return;
}

void insertionSort(int ind, int a[], int n){
    if(ind==0) return;

    insertionSort(ind-1, a, n);

    int key = a[ind];
    int j = ind-1;

    // while(j>=0 && a[j] > key){
    //     a[j+1] = a[j];
    //     j--;
    // }
    recursion(a,ind,j,key);
    j = bk;
    a[j+1] = key;

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
    insertionSort(n-1, arr, n);
    print(arr, n);
    return 0;
}