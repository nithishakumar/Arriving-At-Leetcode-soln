# Count pairs with sum divisble by K 👯 
> View the problem at: https://practice.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1

The Two-sum approach is the first thing I think of. We know how to find pairs with sum = K.

### An important thing to notice is that pairs with sum divisible by K will have remainders that add up to K and 0.

Now, we can store the number of elements along with their % K value in an unordered map.

Now find all keys in the hash map that add up to K using the two sum method in linear time.

For each key pair, we will add the product of their values to the ans variable. Why? This is because
if K = 4, and there are 3 values that have remainder 1 and 2 values that have remainder 3, then we can form 3 * 2 = 6 pairs.
Think of it like each value with remainder 1 can form a pair with each value with remainder 3.

<p align="center">
  <img src="https://github.com/nithishakumar/arriving-at-DSA-solns/blob/main/42.%20Trapping%20Rain%20Water/img/rainwatertrap.png" /> 
 </p>

We can then find the number of pairs that can be formed with the number of values that have remainder 0
using the nC2 formula.

If K is even (we need to check this because integer division would result in K/2 being present in the map
even if K is odd), then we wouldn't have accounted for the number of pairs that can be formed with the elements
that have a remainder = K/2 because K/2 only occurs once in the map.

So we have to use the nC2 formula with the number of values that have remainder = K/2 as well.







