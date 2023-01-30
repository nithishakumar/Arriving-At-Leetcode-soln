# 560. Subarray sum equals K 👩🏻‍💻 
> View the problem at: https://leetcode.com/problems/subarray-sum-equals-k/

Let's look at the brute-force approach. You're going through every sub-array and calculating its 
sum to check whether it's equal to K.

Consider [1 2 3 4 5]: <br> <br>
You're doing <br> [1] <br>
             [1 + 2] <br>
             [1 + 2 + 3] <br>
             [1 + 2 + 3 + 4] <br>
             [1 + 2 + 3 + 4 + 5] <br> <br>
And then you'll do <br> [2] <br>
                   [2 + 3] <br>
                   [2 + 3 + 4] <br>
                   [2 + 3 + 4 + 5] <br> <br>
The redundancy here is that you're calculating [2 + 3 + 4] after having calculated [1 + 2 + 3 + 4] already.
We could've just subtracted 1 from [1 + 2 + 3 + 4] to get the value of [2 + 3 + 4].
So, we can try calculating [1 + 2 + 3 + 4 + 5] and as we calculate it, we can store parts of the sum in a map with
the number of ways we can achieve that sum. 

As we build our map, we will check to see if sum - k exists in the map. Why are we doing this?
Let's say k = 6. If we have a subarray like [0 1 -1 1 1 4 2] and we have iterated up till idx 5.
Our sum = 6. If we do map.find(6 - 6) to check if 0 exists in the map, we are checking to
see how many ways exist to chop off a sum of 0 one from our array so that we can get a sum of 6.
In this case, our map would contain the following values until now: <br>
[0] -> 2 <br>
[1] -> 2 <br>
[2] -> 1 <br>
We can chop off 0 in 2 ways ([0], [0, 1, -1]) from our current subarray ([0 1 -1 1 1 4]) to get a sum of 6. 

But is that all? No! We can also chop off nothing to get the subarray [0 1 -1 1 1 4] which also adds up to 6.
So, by default we will set [0] = 1 before iterating so that we can account for the "chop off nothing" case. 

So, we can chop off a sum of 0 in 3 ways: [], [0], [0, 1, -1] to get our subarray of sum 6 so far. Thus, we will
add 3 to our answer for [0 1 -1 1 1 4], [1 -1 1 1 4], and [1 1 4] -> all of which add up to 6. 

To be more clear, here's why we add [0] = 1 to our map before iterating: 
Look at this array [6] when k = 6. <br>
If we iterate through this array and then do map.find(6 - 6) to look for a 0, we get nothing and our ans ends up being 0. But that's wrong!
We do have a subarray that adds up to 6. So, we will add a [0] -> 1 to our array for the empty subarray before iterating.


Soln:
1. Add [0] = 1 to an  unordered_map<int, int> which maps prefix sum to frequency. 
2. Iterate through the array. As you iterate:
 - Check to see if sum - k exists in the map. If it does, add the value it maps to your final ans for how many ways you can chop sub arrays to get this sum.
 - Do map[sum]++

Why are we adding the sum to the map after checking only after checking if sum - targetSum exists in the map already??

Consider k = 0 and the array [1].

In the first iteration, if we add 1 to the map and then check if 1 - 0 exists in the map, we'll end up adding 1 to our answer. But the answer is 0.

We want to know how many previously encountered subarrays can be chopped from the current running sum to get our target sum. We can't chop the current subarray from itself to get an empty subarray that adds up to k.

> Similar problem: https://leetcode.com/problems/path-sum-iii/





