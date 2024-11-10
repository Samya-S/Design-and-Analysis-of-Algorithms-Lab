#include <bits/stdc++.h>
using namespace std;

int findSmallestPositiveAbsent(vector<int> &a){
    int n = a.size();

    for(int i=0; i<n;){
        if(a[i] <= 0 || a[i] > n){
            i++;
            continue;
        }

        int correctInd = a[i]-1;

        if(a[i] != a[correctInd])
            swap(a[i], a[correctInd]);
        else
            i++;
    }

    for (int i=0; i<n; i++){
        if(a[i] != i+1){
            return i+1;
        }
    }
    
    return n+1;
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &it:a) 
        cin >> it;

    cout << findSmallestPositiveAbsent(a) << endl;
    
    return 0;
}