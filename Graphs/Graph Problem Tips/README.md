# Graph Problem Tips!

## Time Complexity - BFS & DFS 
Grid problems with m x n matrices: in the worst case, you visit every cell from the starting point in the grid. This will result in O(m x n) time complexity. If you do a dfs from every cell, you'll end up with a time complexity of O((mn)^2).

For problems where you start from the edge the matrix and go up to the other end (like Pacific Atlantic Water Flow and Surrounded Regions) you'll only visit every cell once from the row or column you start from so you'll end up with a time complexity of O(mn).

Graph Problems: Count the number of possible edges. If you have n cells, you can have O(n^2) edges in the worst case.


### Finding a cycle in a directed or undirected graph
Union find - works in O(n) time where n is the number of edges
