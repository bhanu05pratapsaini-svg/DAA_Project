# API notes

The public interfaces are declared in include/parking.h, include/algorithms.h and include/graph.h.

Parking functions return 1 for accepted inserts/reservations and 0 for rejected operations. Nearest allocation returns a space ID or -1. Reservation intervals use integer minutes and half-open overlap logic.

Graph distances use INT_MAX/4 as the infinity sentinel. Call graph_init before adding edges. Dijkstra is valid only for non-negative edge weights. Graph routines assume valid node indices and a graph size no greater than GRAPH_MAX.

Algorithm functions accept caller-owned arrays. Sort functions mutate their input. Search functions expect sorted arrays. Knapsack capacity and subset-sum target are non-negative integers.

## Huffman coding

`huffman_build` accepts a byte buffer and fills a 256-entry code table indexed by byte value. It returns the number of distinct symbols, `0` for empty input and `-1` for invalid arguments. `total_bits` receives the total encoded payload length, excluding any header needed to transmit the frequency table. A one-symbol input is assigned code `0`.

## Interval partitioning

`interval_partition` takes start/end arrays and writes a 1-based room number for each original interval. It returns the minimum room count, `0` for an empty input and `-1` for invalid arguments or an interval with `end <= start`. Intervals are half-open, so a room ending at time t can be reused by one starting at t. The implementation sorts intervals and uses a min-heap keyed by current room end time.
