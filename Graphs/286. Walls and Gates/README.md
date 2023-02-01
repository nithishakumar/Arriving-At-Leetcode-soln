# 286. Walls and Gates ⛩️
> View the problem at: https://leetcode.com/problems/walls-and-gates/

> Free version: https://www.lintcode.com/problem/663/

The first brute force solution I can think of is to iterate through every room, do a dfs until you reach a gate/obstacle/exhaust cells
and put the minimum distance to get to these regions in your room cells.

Let's say we want to find the minimum distance for (1, 0). We can go up, down, left right and take the min of these values and store this
at (1, 0).

We have to do that for every room, because if we just do one room, we want end up filling the answer for everything - resulting in the time complexity of this to be O((m x n)^2). 

Okay, not great. How about we just do a BFS from the rooms then? Start at (1, 0) - we will say it has a distance of 0. Add its neighbors from all
four directions into the queue and mark them as visited. All it's neighbors have a distance of 1. Once we mark a node as visited, we will never visit it again,
and we will never update it's value after getting to the gate!!!


<p align="center">
  <img src="https://github.com/nithishakumar/arriving-at-DSA-solns/blob/main/Graphs/130.%20Surrounded%20Regions/img/FlipXOs.png" /> 
 </p>


So, (0, 0) will never be updated - it will be 1! Another issue is, (1, 0)'s value is not supposed to be 0. It's supposed to be 2!!! So, the distance we're marking as
we do a BFS is wrong since we're starting from the rooms. What if we start from the gates then? We can clearly say that the distance of every adjacent node
from the gates always increase by 1 as we get further and further away unlike we had with the rooms.

A BFS from each room it is! You can check whether both multisource/singlesource bfs work to convince yourself. 

Both do!