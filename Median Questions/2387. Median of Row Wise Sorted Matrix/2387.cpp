#include<iostream>
#include<vector>


int checkCondition(int num, vector<vector<int>>& grid) {
    int numEq = 0, numGreater = 0, numLess = 0;
    for (int i = 0; i < grid.size(); i++) {
        auto ub = upper_bound(grid[i].begin(), grid[i].end(), num);
        auto lb = lower_bound(grid[i].begin(), grid[i].end(), num);
        if (lb != grid[i].end() && *lb == num) {
            numEq += int(ub - lb);
        }
        numLess += (lb - grid[i].begin());
        numGreater += (grid[i].end() - ub);
    }
    if (numEq != 0) numEq--;
    if (fabs(numGreater - numLess) == numEq) return 1;
    if (numGreater > numLess) return 0;
    return 2;
}

int matrixMedian(vector<vector<int>>& grid) {
    int minElt = INT_MAX;
    int maxElt = INT_MIN;
    for (int i = 0; i < grid.size(); i++) {
        minElt = min(minElt, grid[i].front());
        maxElt = max(maxElt, grid[i].back());
    }
    if (minElt == maxElt) return minElt;
    int first = minElt, last = maxElt;
    while (first <= last) {
        int middle = (first + last) / 2;
        int val = checkCondition(middle, grid);
        if (val == 1) return middle;
        if (val == 0) first = middle + 1;
        else last = middle - 1;
    }
    return -1;

}