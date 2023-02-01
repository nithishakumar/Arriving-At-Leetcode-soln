# 417. Pacific Atlantic Waterflow 🌊
> View the problem at: https://leetcode.com/problems/pacific-atlantic-water-flow/

The brute-force solution is to iterate through each cell, and check if it can reach the Pacific and Atlantic ocean.

However, we know that the cells at the bottom row and right column can definitely reach the Atlantic ocean
since they're near it. We can travel from these row and columns to see which ones can reach the Pacific.

Similarly, the cells in the first column and row are already at the Pacific ocean so we can see how many
can reach the Atlantic ocean. 

To find how many can reach a specific ocean from a row/column, we just have to keep travelling and storing
the cells until we cannot anymore: that is, until we have exhausted the cells or until the height condition doesn't
hold anymore.

Then, to find the cells that can travel to both the Atlantic and Pacific ocean, we have to just take the intersection
of the data structures that store the values for Atlantic and Pacific.

Important thing to note about the height condition: if we were travelling from each cell to the Pacific/Atlantic
ocean, we would check if the neighbor's height <= current cell's height.

But, if we are going the other way around, that is, from the Pacific/Atlantic ocean to the other end, we have
to check if neighbor's height >= current cell's height.

