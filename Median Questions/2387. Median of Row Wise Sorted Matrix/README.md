# 2387. Median of Row Wise Sorted Matrix 📊

> View the problem at: https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/

> Since it's only available with LeetCode Premium, here's the problem:

> Given an m x n matrix grid containing an odd number of integers where each row is sorted in non-decreasing order, return the median of the matrix. You must solve the problem in less than O(m * n) time complexity.

<p align="center">
  <img src="https://github.com/nithishakumar/arriving-at-DSA-solns/blob/main/Median%20Questions/2387.%20Median%20of%20Row%20Wise%20Sorted%20Matrix/img/Examples.png" /> 
 </p>

In sorted matrix problems when the time complexity has to be less than O(mn), you usually have to do some sort of binary search. 

What do we do binary search on? We could maybe test out different possible values that could be the median and narrow down our search space based on some sort of condition?

How do we know a value is the median? Again, just like any median problem, we have to check if the partition before and after that value is correct by either checking whether all
elements in the left partition is smaller than the right partition and if the size of the left partition and right partition differ by no more than 1.

Say we pick a value 2 and want to check if its the median. We can find how many elements are less than 2 and how many elements are greater than 2 and check if the number of greater/lesser are equal.
That would mean the left and right partitions are equal in size. But things don't always work this way as there could be other elements equal to 2 as well. Well, if we can make up
for the difference between the left and right partitions with the no. of equal elements (other than the current element we are looking at) then we have found the median!

Take an array like 1 2 2 3 5. We picked 2 to be the median. No. of elements less than 2 = 1. No. of elements greater than 2  = 2. No. of elements equal to 2 (other than the current two) = 1.

We can sneak this extra 2 into one of the other partitions (the left partition in this case) and make the partitions correct. Note that the number of elements are odd and that's why this is possible!

What if the number of elements greater than 2 is more than the number of elements less than 2? That means our right partition is larger than our left partition. We've got to increase the size of our left partition or in other words, decrease the size of the right partition.

We can decrease the size of the right partition by picking a larger number so it would have less no.s greater than it. So, we would do first = middle + 1. In the other case, do last = middle - 1 to increase the size of the right partition.

What is first and last though? The median would lie between the largest value and the smallest value in the matrix which we can easily find in less than O(mn) time since the rows are sorted! So first = min value in matrix and last = max value in matrix.

We can find the no. of elements greater or larger than the current element or equal to the current element through binary search (upper_bound and lower_bound in C++) in every row!

