# 42. Trapping Rain Water 🌧️
> View the problem at: https://leetcode.com/problems/trapping-rain-water/

Looking at the first example, my instant thought is that we can trap water between 2 blocks.

<p align="center">
  <img src="/img/rainwatertrap.png" /> 
 </p>

For the second position (idx = 1), we would take the minimum of the height of its neighbors and that would be the 
amount of water it can trap since every block has a width of 1.

However, what if you had a block at the second position (idx = 1), that is, it wasn't empty? Then the amount of
water it can trap with the previous approach would no longer be valid.

Our current answer now for the amount of water each block can trap is min(neighbor heights) - height of curr block 
to account for this case.

Look at position 5 (idx = 4). There is no block here. If we were to use our previous approach, min(neighbor heights) - 1,
we would say it can trap 1 unit of water. But that's not the case since the block at position 3 (idx = 2) can help
it hold more water. Thus, we have to consider the maximum until the current position from the left side over just the neighbor. 
We have to do the same for the right side.

Soln:
1. Maintain leftMax and rightMax array - each idx will store max up till the current idx from left and right.
2. Iterate through the array, for each idx, take min of of leftMax and rightMax value at that position, 
and subtract the current height from it.
3. Return the sum of all the calculated values to give the final amount of water that can be trapped.

TODO: understand how to reduce O(n) memory complexity.
