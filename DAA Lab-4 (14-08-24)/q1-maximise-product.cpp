#include <bits/stdc++.h>
using namespace std;

// int findProd(int ind, int cnt, vector<int> &a){
//     if(cnt <= 0) return 1;
//     if(ind < 0) return 0;

//     int notTake = findProd(ind-1, cnt, a);
//     int take = a[ind]*findProd(ind-1, cnt-1, a);

//     return max(take, notTake);
// }

int main(){
    int n;
    cin >> n;
    
    if(n < 3){
        cout << "Array must contain atleast 3 elements" << endl;
        return 0;
    }

    vector<int> a(n);
    for(auto &it:a) 
        cin >> it;
    
    // if(n == 3){
    //     cout << a[0]*a[1]*a[2] << endl;
    // }

    // cout << findProd(n-1, 3, a) << endl;

    sort(a.begin(), a.end());
    cout << a[n-1]*a[n-2]*a[n-3] << endl;

    return 0;
}