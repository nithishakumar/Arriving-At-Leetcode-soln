# 295. Find Median From Data Stream 📊

> View the problem at: https://leetcode.com/problems/find-median-from-data-stream/

Just like every median question, we need to partition the incoming elements from the stream correctly so that we can calculate the median from the top of the partition.

What do we need for the median from the left partition? We need the rightmost element (greatest element) of the left partition, if the total no. of elements are even.

What do we need for the median from the right partition? We need the leftmost element (smallest element) of the right partition, if the total no. of elements are even.

If the total no. of elements are odd, we just need the rightmost element of the left partition if the left partition's size is greater than the right partition or
the leftmost element of the right partition if the right partition's size if greater than the left partition.

How can we order incoming elements so that the greatest element from the left partition and the smallest element from the right partition are easily accessible? Heaps!!!

Soln:
1. Have a maxpq and minpq. Minpq stores the right partition (all elements in the pq are greater than those in the maxpq) so you can get the smallest element from the top of the minpq. Maxpq would store the left partition so you can get the greatest element of the left partition from the top of the maxpq.
2. The size of the left and right partition are allowed to differ by a maximum value of 1 since we cannot make the partitions' size equal if we have an odd no. of elements. However, if they differ by more than 1, we've got to rebalance the heaps! Move the top of the heap with the greater size to the heap with the smaller size.
3. When both pqs are empty, you can add the incoming element from the stream to either pqs. However, if both pqs are not empty, check if the incoming element is less than or equal the top of the maxpq. If it is, add it to the maxpq since it belongs to the left partition. Otherwise, if it's greater than the top of the maxpq, then it's in the right partition. Add it to the minpq. Then if the size differs by more than 1, rebalance the heaps!
4. When you have to get the median and the total no. of elements so far are odd, get the top of the pq with the greater size. Else, get the average of both pqs tops.


> Similar problem: https://leetcode.com/problems/sliding-window-median/ Here, you have to efficiently remove elements from the heaps as well when elements leave the window which is not possible in C++. You can use a multiset instead!
