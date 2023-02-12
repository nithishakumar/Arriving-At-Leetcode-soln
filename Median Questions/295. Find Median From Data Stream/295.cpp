#include<iostream>
#include<vector>
#include<priority_queue>

class MedianFinder {
public:
    priority_queue<int, vector<int>> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {

    }
    void balanceHeaps() {
        if (minpq.size() > maxpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
        else {
            minpq.push(maxpq.top());
            maxpq.pop();
        }

    }
    void addNum(int num) {
        if (minpq.empty() && maxpq.empty()) {
            minpq.push(num);
        }
        else if (!minpq.empty()) {
            if (num >= minpq.top()) {
                minpq.push(num);
            }
            else {
                maxpq.push(num);
            }
        }
        else if (!maxpq.empty()) {
            if (num <= maxpq.top()) {
                maxpq.push(num);
            }
            else {
                minpq.push(num);
            }
        }
        if (fabs(minpq.size() - maxpq.size()) > 1) {
            balanceHeaps();
        }
    }

    double findMedian() {
        if (minpq.size() == maxpq.size()) {
            return (maxpq.top() + minpq.top()) / 2.0;
        }
        else if (minpq.size() > maxpq.size()) {
            return minpq.top();
        }
        return maxpq.top();
    }
};

