#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ans;
vector<int> curr;
void recursion(vector<int>& nums, vector<bool>& visited) {
    if (curr.size() == nums.size()) {
        ans.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            curr.push_back(nums[i]);
            recursion(nums, visited);
            visited[i] = false;
            curr.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    recursion(nums, visited);
    return ans;
}