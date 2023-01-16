#include<iostream>
#include<vector>
#include<unordered_map>

// O(n) time, O(n) memory
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix2Count;
    int sum = 0;
    int ans = 0;
    prefix2Count[sum] = 1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (prefix2Count.find(sum - k) != prefix2Count.end()) {
            ans += prefix2Count[sum - k];
        }
        prefix2Count[sum]++;
    }
    return ans;
}