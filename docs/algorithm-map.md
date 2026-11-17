# Algorithm mapping and implementation status

This is a student project starter. Implemented means a source routine exists; planned means it is not yet complete or verified.

| Algorithm | Parking-domain use | Status |
|---|---|---|
| Merge sort, quick sort | Sort parking spaces | Implemented |
| Iterative and recursive binary search | Find sorted space IDs | Implemented |
| Maximum subarray | Peak demand window | Implemented |
| Fast power | Modular utility | Implemented |
| Celebrity | Identify a one-way hub | Implemented |
| Activity selection | Non-overlapping reservations | Implemented |
| Interval partitioning | Allocate bays across overlaps | Implemented |
| Huffman | Compress event logs | Implemented |
| Dijkstra | Road routing | Implemented |
| Prim and Kruskal | Infrastructure connection | Prim implemented; Kruskal planned |
| 0/1 knapsack | Upgrade selection under budget | Implemented |
| Matrix chain, LCS, optimal BST | Query planning and sequence comparison | LCS implemented; others planned |
| Bellman-Ford, Floyd-Warshall | Negative-edge audit and all-pairs routing | Implemented |
| Bounded TSP | Inspection route | Planned |
| N-Queens and subset sum | Backtracking exercises | Implemented |
| FIFO/LIFO/least-cost branch and bound | Exact assignment | Planned |
| Ford-Fulkerson and bipartite matching | Capacity flow and driver-bay matching | Max flow and matching implemented |
| Chinese Remainder Theorem | Periodic sensor schedule | Planned |
| Naive, Rabin-Karp, automaton and KMP | Event search | Naive matcher used by all wrappers; optimized algorithms planned |
| Classical and Strassen matrix multiply | Compare multiplication | Classical implemented; Strassen planned |

Reservation windows are half-open: [start,end). Dijkstra requires non-negative weights. Sample allocation uses squared coordinate distance, not road-network travel time.
