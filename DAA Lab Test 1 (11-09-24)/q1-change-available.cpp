#include <bits/stdc++.h>
using namespace std;

bool changeAvailable(vector<int> &a) {
    int n = a.size();

    int cnt5 = 0, cnt10 = 0;

    for (auto &it : a) {
        if (it == 10) {
            cnt10++;
            cnt5--;
            if (cnt5 < 0)
                return false;
        } else if (it == 20) {
            cnt5--;
            if (cnt10)
                cnt10--;
            else
                cnt5 -= 2;
            if (cnt5 < 0 || cnt10 < 0)
                return false;
        } else {
            cnt5++;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (changeAvailable(a))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}