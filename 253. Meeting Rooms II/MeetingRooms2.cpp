#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct comp {
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
        // false == higher priority, write opposite condition for heap
        return lhs[1] > rhs[1];
    }
};
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    for (int i = 0; i < intervals.size(); i++) {
        if (!pq.empty() && intervals[i][0] >= pq.top()[1]) {
            pq.pop();
        }
        pq.push(intervals[i]);
    }
    return pq.size();
}