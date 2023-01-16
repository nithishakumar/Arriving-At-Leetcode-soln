#include<iostream>
#include<vector>
#include<unordered_map>

// O(n) time, O(n) memory
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> rem2Count;
    rem2Count[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int rem = sum % k;
        if (rem < 0) rem += k;  // rem lies between -k and k, to get the positive value of neg remainder, do -k + neg remainder.
        // or you can do divisior = dividend - quotient * remainder. 
        // To find the right quotient, do quotient = floor(double(sum) / k)). Why floor?  
        // floor returns the largest possible integer value which is less than or equal to double(sum) / k.
        if (rem2Count.find(rem) != rem2Count.end()) {
            ans += rem2Count[rem];
        }
        rem2Count[rem]++;
    }
    return ans;
}