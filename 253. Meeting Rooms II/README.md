# 253. Meeting Rooms II 💼  
> View the problem at: https://leetcode.com/problems/meeting-rooms-ii/

Mentioning the question below as it's only available with LeetCode Premium.

> Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
  return the minimum number of conference rooms required.

> Input: intervals = [[0,30],[5,10],[15,20]] Output: 2

> Input: intervals = [[7,10],[2,4]] Output: 1

> Input: intervals [[1, 13], [13, 15]] Output: 1 -> meetings with same end time are considered non-overlapping in this problem.

We need to find how many meetings occur simultaneously. This is because, we have no choice but to assign simultaneous
meetings separate rooms. Thus, the minimum no. of meeting rooms required is the maximum number of overlapping meetings at any given time.

The usual step in interval problems is to first start by sorting them by start time. Now, that we've done that, what
next?

We have to find overlapping meetings. Every time we find two meetings that overlap, we need to keep track of
meetings that occur simultaneously.

[0, 30] and [5, 10] overlap (5 is less than 30). The next meeting is [15, 20]. We need to find which meeting ends
before [15, 20] so that [15, 20] can use that meeting's room. You know that the meeting with the smallest end time
will end first. So, we will add meetings to a data structure that sorts them by smallest end time. What's the best
data structure that pops elements with a condition? a heap!

So this is how things would look (leftmost element is the elt at the top of the heap): <br>
i = 0: [0, 30] 

i = 1: [5, 10], [0, 30]

i = 2: [15, 20], [0, 30] 

Whatever's left in the heap is the maximum no. of meetings that are occuring simulataneously -> aka our answer! 

Side note: I often wonder if I should use a while loop to pop-off all non-overlapping meetings or just an if condition
to pop off only the first non-overlapping meeting. So, I came up with the below example to convince myself to use an
if condition and only pop-off the first overlapping meeting:

Ex: [0, 30] [1, 15] [2, 9] [16, 30]

i = 0: [0, 30]

i = 1: [1, 15] [0, 30]

i = 2: [2, 9] [1, 15] [0, 30]

// pop off [2, 9] since it ends before [16, 30]

// If I pop off [1, 15] as well since it ends before [16, 30], then the answer results to be 2 when the correct answer

// is 3. We don't use a while loop because we are using one room that has become vacant for the meeting. We can't use

// two rooms for a single meeting! 

i = 3: [1, 15] [16, 30] [0, 30]

ans = 3 :)

Soln:
1. Sort intervals according to start time.
2. Declare a heap with comparator that sorts intervals in ascending order based on end time.
3. Iterate through the sorted array.
4. Pop from heap if heap isn't empty and topmost interval in the heap doesn't overlap with currently encountered meeting.
5. Push current interval into heap.
6. Return the size of the heap -> max num of simultaneous meetings :)
  





