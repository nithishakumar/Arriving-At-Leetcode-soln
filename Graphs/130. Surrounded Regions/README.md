# 130. Surrounded Regions ⓧⓞ
> View the problem at: https://leetcode.com/problems/surrounded-regions/

The brute-force solution is to iterate through each cell and check if it's four directionally surrounded by X. This
is a bit complicated as if we flip each cell after check if it's not surrounded by 4 Xs repeatedly, we could end
up getting the wrong answer because the cell could end up being connected to a cell in the border row/column, that
is, it could be connected to an unsurrounded cell. 

Okay then, maybe we could start recursing from the border cells then, to see which cells are connected to Os in 
these rows and columns. But, that's not what we want! We would end up capturing all the unsurrounded regions.

Well, if we capture all the unsurrounded regions, mark them with some symbol temporarily, then we can differentiate
them from the surrounded O cells. So after that, all we have to do, is flip all the surrounded Os to Xs and then finally
flip all the unsurrounded cells with temporary symbols back to Os!!!


<p align="center">
  <img src="https://github.com/nithishakumar/arriving-at-DSA-solns/blob/main/Trees/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal/img/preorder.png](https://github.com/nithishakumar/arriving-at-DSA-solns/blob/main/Graphs/130.%20Surrounded%20Regions/img/FlipXOs.png" /> 
 </p>

Soln:

1. Find unsurrounded regions from border rows and columns and mark them with a temporary symbol that is not O
2. Flip all the leftover surrounded O cells to X
3. Flip all the temporary symbol cells back to O
