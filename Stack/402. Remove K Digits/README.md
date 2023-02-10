# 402. Remove K Digits 🔢
> View the problem at: https://leetcode.com/problems/remove-k-digits/

The brute force solution is to remove every possible group of k digits and check which one gives the least number - can be implemented with recursion.

Let's make a few observations to optimize the brute force solution. Given any number, we always remove the greatest digits from the left (or the first instance)
to get the smallest number.

Consider 34849 with k = 1

We could remove 3, we would get 4849

We could remove 4, we would get 3849

We could remove 8, we would get 3449

We could remove 9, we would get 3484

Removing 8 is the best. That is, we're removing the greatest number from the left.

Consider 123456 with k = 3

We would remove 4, 5, and 6 here to get 123. We can see that we're removing the first instance of the k greatest digits.

Consider 654321 with k = 3

We would remove 6, 5, 4 to get 321. Again, we're remove the first instance of the k greatest digits.

How can we remove the first k greatest digits from the left? Every time we encounter a digit smaller than the greatest digit so far, we remove the greatest digit so far.

3, 4, 8, 4, 9

When we hit the second 4, we remove 8. Remember that we only do this while k > 0.

If we have 123456, then we never have a number that's smaller than the previous one. This means that the greatest k digits are at the very end of the string. So, just remove
the last k numbers.

So, since you want to remove the first instances of the greatest k digits, you can use a monotonically increasing stack. That way, 
when you hit a smaller digit than the greatest digit so far, you can pop the greatest digits.




