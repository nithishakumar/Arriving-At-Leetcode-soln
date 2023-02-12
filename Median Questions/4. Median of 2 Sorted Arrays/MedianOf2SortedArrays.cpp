#include<iostream>
#include<vector>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() < nums1.size()) swap(nums1, nums2);
    int first = 0, last = nums1.size() - 1;
    int i = 0, j = 0;
    int half = (nums1.size() + nums2.size()) / 2;
    while (true) {
        if (last < 0) i = -1; else i = (first + last) / 2;
        j = (half - (i + 1)) - 1;
        int ALeft = INT_MIN, BLeft = INT_MIN, ARight = INT_MAX, BRight = INT_MAX;
        if (i >= 0) {
            ALeft = nums1[i];
        }
        if (i + 1 >= 0 && i + 1 < nums1.size()) {
            ARight = nums1[i + 1];
        }
        if (j >= 0) {
            BLeft = nums2[j];
        }
        if (j + 1 >= 0 && j + 1 < nums2.size()) {
            BRight = nums2[j + 1];
        }
        if (ALeft <= BRight && BLeft <= ARight) {
            if ((nums1.size() + nums2.size()) % 2 != 0) {
                return min(ARight, BRight);
            }
            else {
                return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }
        }
        else if (BLeft > ARight) {
            first = i + 1;
        }
        else {
            last = i - 1;
        }
    }
    return -1;
}
