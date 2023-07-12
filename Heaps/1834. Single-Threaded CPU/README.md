# 1834. Single-Threaded CPU 🖥️
> View the problem at: https://leetcode.com/problems/single-threaded-cpu/description/

In scheduling problems, we first need to order the tasks in a certain way. Here, our first priority is the task with the least enqueue time (when the task is available), then the processing time, and then the index. We know we can sort all tasks to obtain this order.

However, the issue is, we need to only get tasks that are available at a given point of time while choosing a task. 

While completing a task, some other tasks may become available.
After completing a task, some other tasks may become available.
We need to get all these tasks that become available and then re-sort them in order of shortest processing time and index. We can do so by storing tasks in a minpq. As we add tasks to this pq, the tasks with the shortest processing time and index will automatically be on top.

Now, say we have a time variable that is incremented to keep track of time. If we keep incrementing it at every step of the loop, we could waste a lot of time.
Consider [1, 2], [1000, 3].
Task 1 is completed at time 3 but task 2 is only available at 1000. We CANNOT keep incrementing time to 1000. So, we need to figure out a way to update time.
We can have 3 cases:
1. The next task is available at a time after the current task is completed. We just set time to the start time of the next task.
2. The next task is available at a time before the current task is completed. We set time to the start time of the next task so we can add the next task to our pq. The current task is still ongoing.
3. There is no next task or next task's start time == taskCompletionTime. Just set time to the completion time of the current task.

PROBLEM WITH CASE 1: If we just check if currentTime < nextTask's start time and then add the next task to our pq, there is an issue. Say our taskCompletionTime is 17 and the next task is available at 18, so we just add our next task to our minpq. But at 17, when the current task would be completed, there are already tasks in the pq that were added because they were available earlier when the current task was being completed. These tasks need to be finished at 17 before we add the next task at 18. So, we should only set the time to the start time of the next task that's greater than the current time when there are no tasks available already!!!
