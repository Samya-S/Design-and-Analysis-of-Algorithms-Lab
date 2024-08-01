/* Search an element in a rotated sorted array */

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int target){
    int low = 0, high = a.size()-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(a[mid]==target) return mid;

        if(a[low] <= a[mid]){
            if(a[low] <= target && target <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(a[mid] <= target && target <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    int target; cin >> target;

    cout << search(a, target) << endl;

    return 0;
}