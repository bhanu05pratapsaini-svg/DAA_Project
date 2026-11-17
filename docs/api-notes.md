# API notes

The public interfaces are declared in include/parking.h, include/algorithms.h and include/graph.h.

Parking functions return 1 for accepted inserts/reservations and 0 for rejected operations. Nearest allocation returns a space ID or -1. Reservation intervals use integer minutes and half-open overlap logic.

Graph distances use INT_MAX/4 as the infinity sentinel. Call graph_init before adding edges. Dijkstra is valid only for non-negative edge weights. Graph routines assume valid node indices and a graph size no greater than GRAPH_MAX.

Algorithm functions accept caller-owned arrays. Sort functions mutate their input. Search functions expect sorted arrays. Knapsack capacity and subset-sum target are non-negative integers.
