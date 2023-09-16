# 1462. Course Schedule IV 📖
> View the problem at: https://leetcode.com/problems/course-schedule-iv/

The brute-force solution I first thought of was iterate through all the queries, then for each query, try to check if you can reach the 2nd node in the query from the first node. The time complexity of this solution is O(Q * P) where Q is the no. of queries and P is the no. of prerequisites because dfs' time complexity is attributed to the no. of edges, which in this case is P. Since there are nodes that have no prereqs that we will visit, the time complexity is more accurately O(Q * (P + N)) where N is the number of courses.

Since the number of queries is much larger than the number of courses, we should try to only iterate through the queries while performing constant time operations.

One thought I had was as follows. Say we have query [crs1, crs5]. As we perform dfs to reach crs5 from crs1, I thought we could add all the descendants of crs1 to crs1's spot in the adjList.

Like if we had crs1 -> crs2 -> crs3 -> crs4 -> crs5, as I traverse through this graph, I will add crs2 to adjList[crs1] (if it doesn't exist already) and crs3 to adjList[crs1] and so on. That way, by the end of processing this query, our adjList[crs1] will be {crs2, crs3, crs4, crs5}. This will make processing any other queries where the first node is crs1 much faster.

But, this is not fast enough. We want to do this for all nodes before we process all queries. To do that, we will recursively make a node return a set with all it's descendants and itself to the previous node.

For instance, crs5 returns {crs5} to crs4. crs4 returns {crs4, crs5} to crs3. crs3 returns {crs3, crs4, crs5} to crs2 and crs2 returns {crs1, crs2, crs3, crs4, crs5}.

We should do this for every course before processing the queries so that all our courses have all their descendants in a hashmap. Then, we can process all our queries in O(Q) time!

This brings our time complexity to O(Q) + O((P + N) * N) -> * N since we run the dfs on all courses.