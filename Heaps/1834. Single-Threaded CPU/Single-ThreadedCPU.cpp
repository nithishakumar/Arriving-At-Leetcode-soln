#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
   vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        int taskIndex = 0;
        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        long long int time = tasks[taskIndex][0];
        long long int taskCompletionTime = -1;
        bool taskOngoing = false;
        while(!pq.empty() || taskIndex < tasks.size()) {
            // get all available tasks
            while(taskIndex < tasks.size() && time == tasks[taskIndex][0]) {
                pq.push({tasks[taskIndex][1], tasks[taskIndex][2]});
                taskIndex++;
            }
            if(!taskOngoing && !pq.empty()) {
            ans.push_back(pq.top()[1]);
            taskCompletionTime = time + pq.top()[0];
            pq.pop();
            }
            // if there are no available tasks and 
            // the task completion time is less than the start of the next task
            if(taskIndex < tasks.size() && taskCompletionTime < tasks[taskIndex][0] && pq.empty()) {
                time = tasks[taskIndex][0];
                taskOngoing = false;
            }
            // if the task completion time is more than the start of the next task, have to add the next task
            // to the pq but the prev task is still ongoing
            else if (taskIndex < tasks.size() && taskCompletionTime > tasks[taskIndex][0]) {
                time = tasks[taskIndex][0];
                taskOngoing = true;
            }
            // If there is no next task, just set time to taskCompletionTime
            else {
                time = taskCompletionTime;
                taskOngoing = false;
            }

        }
        return ans;
    }