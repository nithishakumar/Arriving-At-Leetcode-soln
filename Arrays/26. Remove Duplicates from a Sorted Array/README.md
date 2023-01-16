# 26. Remove Duplicates from a Sorted Array ✌️ -> ☝️
> View the problem at: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

My first thought is to have a pointer point to an element, another pointer point to the next element. Keep incrementing
the next pointer until its not equal to the first element anymore.
Then increment the first pointer and give it the value of whatever the second pointer is pointing to. 

We have to keep note of a few things regarding incrementing pointers for this logic to properly happen. 
Think of the first pointer as the index counter for building a new array. It keeps track of new indices
while add new elements to an array. 
So, it actually has to start from 1. This is because we are still preserving one element from each duplicate group, 
so even if the first element had a duplicate, we will preserve the first element with the duplicated value and only 
change the second with the next unique value.
Every time a new value is added to the position the index counter points too, we increment it. At the end,
the index counter would be equal to the size of the new array with only unique values.
