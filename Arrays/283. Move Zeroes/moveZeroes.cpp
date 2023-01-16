#include<iostream>
#include<vector>

// O(n) time, O(1) memory
void moveZeroes(vector<int>& nums) {
    int numZeroes = 0;
    int ptr = 0;
    // [0,0,0,3,12]
    while (ptr < nums.size()) {
        if (nums[ptr] == 0) {
            numZeroes++;
        }
        else {
            swap(nums[ptr - numZeroes], nums[ptr]);
        }
        ptr++;
    }
}
