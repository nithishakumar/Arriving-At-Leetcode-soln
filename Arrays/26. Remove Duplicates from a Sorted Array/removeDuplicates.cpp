#include<iostream>
#include<vector>

// O(n) time, O(1) memory
int removeDuplicates(vector<int>& nums) {
    int newIdx = 1;
    int ptr = 0;
    while (ptr < nums.size()) {
        int elt = nums[ptr];
        ptr++;
        while (ptr < nums.size() && nums[ptr] == elt) {
            ptr++;
        }
        if (ptr < nums.size()) {
            nums[newIdx] = nums[ptr];
            newIdx++;
        }
    }
    return newIdx;
}