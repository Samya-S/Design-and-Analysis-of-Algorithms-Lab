#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int txnFee) {
    int n = prices.size();

    if (n == 0)
        return 0;

    vector<int> next(2, 0), curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;
            if (buy == 0)
                profit = max(0 + next[0], -prices[ind] + next[1]);
            if (buy == 1)
                profit = max(0 + next[1], prices[ind] - txnFee + next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }

    return curr[0];
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto &it : prices) {
        cin >> it;
    }

    int txnFee;
    cin >> txnFee;

    cout << "Max profit: " << maxProfit(prices, txnFee) << endl;

    return 0;
}