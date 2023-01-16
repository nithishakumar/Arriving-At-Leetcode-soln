# 380. Insert Delete GetRandom O(1): random access in a set 👩🏻‍💻  
> View the problem at: https://leetcode.com/problems/insert-delete-getrandom-o1/

The first 2 functions (insert and delete) can easily be done in O(1) time with an unordered_set.

What about the last function? We know how to get a random element from an array with a random function
using random access. But there's no random access in a set! We need to find a way to keep track of 
elements' idx as they're removed. So that we can have a separate vector that stores the element at each index 
and use the randomly generated index to return an element.

Maybe we could store the index of each element along with it in an unordered_map.
After removing an element, however, there would be a gap in the indices: say we remove the 3rd element,
our map would have:
{elt, 0} {elt, 1} {elt, 2} {elt, 4}. We cannot update all the elements after the 3rd element since that
would increase our time complexity to O(n).
But, we can use the last element to fill in the gap, since the pop_back() operation is O(1).

Say we have the elements {0, 1, 2, 3, 4, 5}. We remove 3. We get {0, 1, 2, _, 4, 5}. We can replace the element 
at the index we removed with the last index and pop_back the last element to get {0, 1, 2, 5, 4} .
Now we remove {3, 4} from the map (3 was present at idx 4) and update {5, 5} in the map (5 was present at idx 5) 
to {5, 4} as 5 is now present in 3's old position. 

This way, our gap is filled and we can easily do random access in the vector to return a random element.

Soln (insert just uses basic set operations so it's not described):
1. Keep an unordered_map that maps elements to their indices and a vector that stores the element at each index.
2. Remove: after removing an element that's present from the set and vector:
  - put the last element in the vector at the position of the removed element in the vector
  - update the index of the last element in the set to be the index of the element removed
3. Random: use the random function and % the value it returns with the size of the vector

  





