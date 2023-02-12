# 4. Median of 2 Sorted Arrays 🤯
> View the problem at: https://leetcode.com/problems/median-of-two-sorted-arrays/

The easy O(m + n) solution is to just merge the two sorted arrays and then pick the middle element if the size of the array is odd or the average of the middle 2 elements otherwise.

To optimize this, in any median question, we have to figure out how to partition the array correctly so that the elements to the left of the median are all less than the elements to the
right of the median and both partitions's size is about half of the total number of elements.

Say we have two sorted arrays of size m and n where m < n.

To parition the array, say we have a total of K elements. We have to create a partition of size K/2 -> About half of the array's elements would be on its left partition and the other half
would be on the right. So, our partition's size -> half = K/2. 

Let's test our first partition out by taking half of the elements from the smaller array of size m. Now, we will take K/2 - (m/2) from the larger array. Why are we operating on the smaller 
array? Because we know the larger array will have more elements and we would not run out of elements while looking for values in the larger array.

So, we have our left partition with K/2 elements. How do we know if this is correct? Well, in a sorted array, the last elements of the left partition would be <= the first elements
of the right partition. So, we will check exactly that.

Say the end of our left partition is marked by ALeft and BLeft in both arrays. The start of the right partition would be BRight and ARight. Check if ALeft <= BRight and BLeft <= ARight.

If this is true, we've partitioned everything correctly. If the total elements we have is odd, we have to pick the middle element. 

A: 1 1 

B: 2 3 4

The partition here would be Aleft = 1, BRight = 2, BLeft = INT_MIN, ARight = INT_MAX. We will take the minimum of the first two elements of the right partition to see which one occurs first
as if these arrays were combined we'd get 1 1 2 3 4 and 2 is the median.

Consider

A: 1 3

B: 6

The partition here would be ALeft = 1, BRight = 6, BLeft = INT_MIN, ARight = 3. Again, here we will take the minimum of the first two elements of the right partition for the median. Why the right
partition??? Why can't we take the maximum of the two left partitions? This is because we are making the size of our left partition to be K/2 and integer division would round down the size.
If we have 7 elements, 7/2 = 3. So our left partition has 3 and right partition will thus end up having 4 elements and thus, the extra element or the median.


For an even sized array, it's more straight forward. Just take the average of the sum of maximum of the left partition and the minimum of the right partition as these would be the 2 middle elements of the array.

Okay now what if we didn't partition the array correctly? Say if ALeft > BRight where A is the array of size n and B is the array of size m. We have to increase the number of elements in the array of size m or array B so that we can 
reduce the number of elements in the left partition from array A. We can do this by moving the middle element in our B array further to the end. That can be achieved by making first = middle + 1.

In the other case, we would have to increase the number of elements in the A array's left partition. You can do that by making the middle element in array B move further to the start of the array. That can be achieved by making
last = middle - 1 so that when you do (first + last) / 2, you'll get a smaller middle and thus a smaller sized left partition.
