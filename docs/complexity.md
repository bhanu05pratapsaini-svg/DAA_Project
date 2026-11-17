# Complexity and recurrence notes

| Algorithm | Time | Extra space |
|---|---:|---:|
| Merge sort | O(n log n) | O(n) |
| Quick sort | Average O(n log n), worst O(n^2) | O(log n) average stack |
| Binary search | O(log n) | O(1) iterative; O(log n) recursive |
| Maximum subarray | O(n log n) | O(log n) stack |
| Fast power | O(log exponent) | O(1) |
| Celebrity | O(n) | O(1) |
| Activity selection implementation | O(n^2) | O(n) |
| 0/1 knapsack | O(nW) | O(W) |
| LCS | O(nm) | O(m) |
| Subset sum | O(nT) | O(T) |
| N-Queens count | O(n!) upper bound | O(n) recursion |
| Dijkstra matrix | O(V^2) | O(V) |
| Bellman-Ford matrix | O(V^3) | O(V) |
| Floyd-Warshall | O(V^3) | O(V^2) |
| Prim matrix | O(V^2) | O(V) |
| Edmonds-Karp matrix | O(V^2 E) | O(V^2) |
| Bipartite matching DFS | O(VE) | O(V) |

Merge sort and maximum subarray use T(n)=2T(n/2)+Theta(n), so the Master Theorem gives Theta(n log n). Fast power uses T(n)=T(n/2)+Theta(1), giving Theta(log n). Quick sort has balanced recurrence 2T(n/2)+Theta(n), but extreme partitions produce Theta(n^2). Benchmark numbers depend on compiler and hardware; current runner measures only merge sort.
