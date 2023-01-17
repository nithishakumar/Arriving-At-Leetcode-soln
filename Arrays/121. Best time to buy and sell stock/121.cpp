#include<iostream>
#include<vector>

// O(n) time, O(1) memory
int maxProfit(vector<int>& prices) {
    int buy = 0;
    int sell = 1;
    int maxProf = 0;
    while (sell < prices.size()) {
        maxProf = max(maxProf, prices[sell] - prices[buy]);
        if (prices[sell] < prices[buy]) {
            buy = sell;
        }
        sell++;
    }
    return maxProf;

}