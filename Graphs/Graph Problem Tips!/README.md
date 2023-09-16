# Graph Problem Tips!

## Time Complexity - BFS & DFS 

PLEASE DON'T MEMORIZE THIS - Think exactly how many edges you're visiting and if you're visiting any nodes without edges. That's primarily how you will determine time complexity for these graph questions.

#### Grid problems with m x n matrices: 
in the worst case, you visit every cell from the starting point in the grid. This will result in O(m x n) time complexity. If you do a dfs from every cell, you'll end up with a time complexity of O((mn)^2).

For problems where you start from the edge the matrix and go up to the other end (like Pacific Atlantic Water Flow and Surrounded Regions) you'll only visit every cell once from the row or column you start from so you'll end up with a time complexity of O(mn).

#### Graph Problems: 
Count the number of possible edges. If you have n nodes, you can have n choose 2 edges in the worst case - everything is connected. So you can get a time complexity of O(n^2) - for every node, you have to check every edge it's connected to in the worst case.

Be careful, for problems like Course Schedule, our dfs only takes O(n + p) time (n -> #courses, p -> #prerequisites or edges). This is because, we iterate through every node and check every prerequisite it has. Once we know a course can be completed, we set its prerequisites to be empty. So we never revisit a node. If we do revisit a node, it would be O(np) because we go through every prerequisite a node has from a given node.

## Finding a cycle in a directed or undirected graph
Union find - works in O(n) time where n is the number of edges, mathematically proved.

## Need to find some minimum quantity? Please think BFS first!
Usually, if you need to minimize some quantity, BFS works best since it finds the shortest path quicker than dfs. Multisource bfs works best - think Rotting Oranges, Walls & Gates, and Word Ladder.