# 283. Move Zeroes ⓪
> View the problem at: https://leetcode.com/problems/move-zeroes/

Looking at the first example, my instant thought is to iterate through the array, increment a zero counter if you find a zero,
or add non-zero element to the beginning of the array using the insert function.

This is not ideal since the insert function will increase the time complexity to O(n^2).

Why not save the position of the last zero element with a pointer 
and swap it with the current non-zero element's position?

Not the best idea. Look at the array nums = [0, 0, 1, 3, 2]. 
I would end up swapping the second 0 and 1. But, I needed to swap it with the first 0.

Why not count the number of zeroes? Okay. Everytime I encounter a zero element, I increment a variable numZeroes. 
So, when I encounter 1, my numZeroes variable = 2. My goal now is to swap it with the first 0.
To swap it with the first zero, I can get the first zero's position
by subtracting 2 from the idx of 1: swap(nums[2], nums[2 - numZeroes]) and we get
[1, 0, 0, 3, 2].

Should I keep incrementing numZeroes now or should I decrement it since I made a swap?

Say I decrement it. numZeroes = 1 now. Our iterator i is now at pos 3.
If I swap(nums[3], nums[3 - numZeroes]) I end up swapping it with the last zero instead of the first one! We don't 
decrement numZeroes because our first 0 moved 1 position further!

Soln:
1. Iterate through the array. As you iterate, check the value of the current element.
 - If the element is 0, increment a counter numZeroes.
 - If the element is != 0, swap it with array[i - numZeroes].





