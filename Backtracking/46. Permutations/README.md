# 46. Permutations 😅😂🤣 -> 🤣😂😅
> View the problem at: https://leetcode.com/problems/permutations/

We need to generate all possible arrangements of a set of DISTINCT numbers. 

Video explanation of recursive code with stack frames: https://www.youtube.com/watch?v=4hUopgoOAS4

Soln:
1. Keep a visited bool array to track which elements of nums have been visited
2. Keep a curr vector to store the permutation that is currently being generated
3. Base case: when to stop adding elements to curr? when the size of curr = size of nums since that means all elements of nums have been added to curr.
3. In a for loop, iterate through each element of nums, if it has not been visited, visit it, add it to curr, and then start generating all permutations with nums[i] added to curr.
4. After returning back to a stack frame, unvisit the current element, remove it from curr, and then move on to the next iteration where we visit the next element and get all permutations that include it.





