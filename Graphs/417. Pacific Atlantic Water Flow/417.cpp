#include<iostream>
#include<vector>
#include<set>

void travel(vector<vector<int>>& heights, int r, int c, set<pair<int, int>>& vals) {
    if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() ||
        heights[r][c] == -1 || vals.find({ r, c }) != vals.end()) {
        return;
    }
    int temp = heights[r][c];
    heights[r][c] = -1;
    // down
    vals.insert({ r, c });
    if (r + 1 < heights.size() && heights[r + 1][c] >= temp) {
        travel(heights, r + 1, c, vals);
    }
    if (r - 1 >= 0 && heights[r - 1][c] >= temp) {
        travel(heights, r - 1, c, vals);
    }
    if (c + 1 < heights[0].size() && heights[r][c + 1] >= temp) {
        travel(heights, r, c + 1, vals);
    }
    if (c - 1 >= 0 && heights[r][c - 1] >= temp) {
        travel(heights, r, c - 1, vals);
    }
    heights[r][c] = temp;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    set<pair<int, int>> pacific;
    set<pair<int, int>> atlantic;
    for (int col = 0; col < heights[0].size(); col++) {
        // reach top row from bottom row
        travel(heights, heights.size() - 1, col, pacific);
        // reach bottom row from top row
        travel(heights, 0, col, atlantic);
    }
    for (int row = 0; row < heights.size(); row++) {
        // reach left column from right column
        travel(heights, row, heights[0].size() - 1, pacific);
        // reach bottom row from top row
        travel(heights, row, 0, atlantic);
    }
    for (auto it = pacific.begin(); it != pacific.end(); it++) {
        if (atlantic.find(*it) != atlantic.end()) {
            ans.push_back({ it->first, it->second });
        }
    }
    return ans;
}