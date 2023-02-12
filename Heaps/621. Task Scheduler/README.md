# 621. Task Scheduler 🕒  
> View the problem at: https://leetcode.com/problems/task-scheduler/

Intuitively, to minimize idle time and perfom tasks as fast as possible, we want to spread out the tasks present in the largest amount after perfoming them first so that we can
perform other tasks in between.

Okay, so we need to keep a count of all tasks - a hashmap is good for that. I think we can pick the task with highest priority through a priority queue that orders tasks
based on their count (high count = high priority) and also the time their available (low time = high priority). We have to make sure a task is available first, so in our priority 
queue's comparator, we will check for time first then we will check for count of tasks.

So now I'll put the first task that's available and has highest count at time = 0 in our pq and start the loop. I'll pick the first task out of the priority queue, decrement it's count
and then if it's not 0 after decrementing, I'll put it back in the priority queue with the time it's next available at. I also have the other data structure that has tasks sorted
by count order in descending order. If I only put one tasks from this data structure into my priority queue when I all my priority queue tasks are over, it will be wrong since
I'm not choosing between all tasks available at a given moment.

Let's say I have the following tasks with their count:

A 3

B 3

C 3

D 2

E 1

When I've completed 2 of A, B, and C and their count has reduced to 1, my priority queue is not empty yet so I don't look at D. When In reality, I should be doing D first since it's the
task which is high priority right now since it's present in the greatest number and is also available right now. So checking count data structure only when priority queue is empty is a no-no.

We need to make sure all tasks that are available at any given moment are in the priority queue at that time. Okay then, I'll store the count of all tasks available at time = 0 in the priority
queue. Then, I'll have a separate data structure that stores the tasks with their count and the time they're next available at. So that, when I reach that time, I'll just add those tasks
back into the priority queue and choose between all tasks that are available at any given moment based on their count.

What's a good data structure for storing all the tasks remaining? All tasks that are completed are waiting in a queue until it's their turn to be available for completion. A queue would 
make a lot of sense because the task that was first added to it is guaranteed to have a lesser value for the time it's next available at compared to later tasks that are added to it.

Soln:
1. Count the freq of all tasks
2. Put all task counts in a pq (these are tasks available at time t = 0).
3. Have a queue would store all tasks remaining in the future -> each task would be stored with their count and the time they're next available at.
4. Start a while loop that runs as long as there are no tasks in the priority queue OR no tasks remaining in the queue.
5. First, take all the tasks remaining in the queue that are available now and put them in the pq.
6. Pick the task with the highest count from the pq (top of pq) and decrement its count. If the count is > 0, then put it into the tasks remaining queue along with the time it'll next be available at.
7. Increment time by 1 unit or if there are no tasks in the pq and the tasksRemaining queue's first task is greater than the time, change the time to the time the next task is available at
so that you can prevent iterations of the while loop during idle time.
 
