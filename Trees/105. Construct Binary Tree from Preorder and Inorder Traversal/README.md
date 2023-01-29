# 105. Construct Binary Tree from Preorder and Inorder Traversal 🌳
> View the problem at: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

First, I'll do a preorder and inorder traversal of a binary tree to make the following observations.

So, we have a recursive function to first create the root of the tree from the first element of the preorder array. 
Now what's the left child of this node? The root of the left subtree - aka the next element of our preorder array.

But when do we know to the left subtree ends? that's where the inorder array helps. 

We will have to take all elements to the left of the root elt in the inorder array to figure out how many left elements
there are. So, we need a way to figure out where the first element of the preorder array is in our inorder array (which 
data structure is useful for this? Hashmap!!!)

Say we have 4 index elements to keep track of where we are in the arrays: pstart = 0, pend = preorder.size() - 1, 
istart = 0, iend = inorder.size() - 1.

root = preorder[pstart] = 3

Now, how to mark the end of the left subtree in preorder? Find num left subtree elts from inorder first:

1. Find the index of the root in inorder using a hashmap
2. Find number of elements to the left of the root by subtracting istart from rootIdx. This is the #left subtree elements.
3. Add num left subtree elements to our pstart to use all these elements to build left subtree.

pstart + num left tree elts = 1 (which makes sense since 3 is the only left subtree elt).

What about the right subtree? pstart for the right would start at pstart + numleftelts + 1 (the next element after the last
leftree elt in preorder). istart would start at the element after the rootIdx!

Similar problems:

> https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/





