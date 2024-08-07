#include <bits/stdc++.h>
using namespace std;

int cntStd(int maxpg, vector<int> &a){
    int cnt = 1, pgs = 0;

    for(int i=0; i<a.size(); i++){
        if(pgs + a[i] <= maxpg){
            pgs += a[i];
        }
        else{
            pgs = a[i];
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n; cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int m; cin >> m;

    int low = *min_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while(low <= high){
        int mid = (low+high)/2;

        if(cntStd(mid, a) > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << low << endl;

    return 0;
}