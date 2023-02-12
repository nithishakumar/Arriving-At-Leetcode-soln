#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<int, int> task2Count;
    for (int i = 0; i < tasks.size(); i++) {
        task2Count[tasks[i]]++;
    }
    priority_queue<int, vector<int>> pq;
    for (auto it = task2Count.begin(); it != task2Count.end(); it++) {
        pq.push(it->second);
    }
    int time = 0;
    queue<pair<int, int>> tasksRemaining;
    while (!pq.empty() || !tasksRemaining.empty()) {

        while (!tasksRemaining.empty() && tasksRemaining.front().first <= time) {
            pq.push(tasksRemaining.front().second);
            tasksRemaining.pop();
        }

        if (!pq.empty()) {
            int task = pq.top();
            pq.pop();
            if (task - 1 > 0) {
                tasksRemaining.push({ time + n + 1, task - 1 });
            }
        }

        if (pq.empty() && !tasksRemaining.empty()) {
            time += (tasksRemaining.front().first - time);
        }
        else
            time++;
    }
    return time;
}