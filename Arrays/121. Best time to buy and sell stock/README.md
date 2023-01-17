# 121. Best time to buy and sell stock 📈 
> View the problem at: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

The basic idea of this problem is to find the maximum increase between an element i and an element j
that occurs after it.

The maximum increase would be between the least element from the left and the greatest element from the right.

So, I immediately think of making a leftMin prefix array that stores the min elt from the left at every 
point in the array. Then, I'll make a rightMax array that stores the max elt from the right (postfix) at 
every point in the array.

The maximum difference between any two corresponding elements of this array (rightMax[i] - leftMin[i]) would 
be the answer.

But, this is an O(n) memory complexity solution. How to reduce the memory complexity?

We are redundantly storing the leftMin value even if it doesn't change. We can have two pointers, one point 
to the leftMin (0 initially), and another rightMax pointer point to the element after leftMin. Now, if the 
value at rightMax is less than leftMin, leftMin = rightMax. Whether or not the value at rightMax is greater 
than leftMin, we will increment rightMax to look at the next available value.

This way, we are not storing the leftMin and rightMax value at every point and are only updating it as it changes.

Soln:
1. leftMin = 0, rightMax = 1
2. while rightMax < prices.size():
 - if(prices[rightMax] < prices[leftMin]): leftMin = rightMax (value @ rightMax is now the new leftMin -> 
   why buy for more money when you can buy for less?)
 - rightMax++
3. Keep track of prices[rightMax] - prices[leftMin] and find the max value of this difference throughout the loop. 
   This is your answer!







