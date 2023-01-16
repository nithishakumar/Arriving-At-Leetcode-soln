# 974. Subarray sum divisible by K 👩🏻‍💻 
> View the problem at: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Use the same approach described in subarray sum equals to k: https://github.com/nithishakumar/arriving-at-DSA-solns/tree/main/Arrays/560.%20Subarray%20sum%20equals%20K

The only thing different is, the key would be sum % k to chop off subarrays with the remainder required so 
that we can get a subarray that is perfectly divisible by k.

The main problem is finding sum % k when sum is negative. C++ allows negative remainders which doesn't obey
Euclidean division which is what make sense for our algorithm - we want to chop off the positive remainder because
we are doing usual Euclidean division.

How to get the positive remainder from the negative remainder? add k to it.
Or you can do sum - (k * floor(double(sum) / k)). Why? 
- double(sum) / k returns the right quotient in double. 
- We do floor to get the smallest integer less than the quotient. 
- sum - quotient * divisor = remainder, divisor here is k.

LeetCode's official solution recommends: (dividend % divisor + divisor) % divisor for positive remainder.
