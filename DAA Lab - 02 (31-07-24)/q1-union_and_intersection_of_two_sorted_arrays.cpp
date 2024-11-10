/* Find the union and intersection of two sorted arrays */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    int m; cin >> m;
    vector<int> b(m); for(int i=0; i<m; i++) cin >> b[i];

    int p=0, q=0;
    vector<int> u,i;

    while(p<n && q<m){
        if(a[p]==b[q]){
            i.push_back(a[p]);
            u.push_back(b[p]);
            p++; q++;
        }
        else if(a[p] > b[q]){
            u.push_back(b[q]);
            q++;
        }
        else {
            u.push_back(a[p]);
            p++;
        }
    }

    while(p<n) u.push_back(a[p]);
    while(q<m) u.push_back(b[q]);

    cout << "u : ";
    for(auto it:u) cout << it << " ";
    cout << endl;

    cout << "i : ";
    for(auto it:i) cout << it << " ";
    cout << endl;

    return 0;
}