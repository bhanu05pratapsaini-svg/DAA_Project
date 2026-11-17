# Testing and demo plan

Run make clean all test with GCC or Clang supporting C17.

Current tests cover sorting, binary-search success/failure, maximum subarray, modular power, N-Queens, knapsack, LCS, subset sum, valid reservation and overlapping-reservation rejection.

Before final submission add empty and duplicate arrays, reverse order, integer boundaries, invalid IDs, adjacent intervals, full capacity, disconnected graphs, negative cycles, flow bottlenecks and stress sizes.

Demo scenarios: (1) normal operation with an available bay; compare nearest and cheapest policies after implementing both. (2) capacity shock by closing a zone or occupying bays; verify no overbooking. (3) generated large-data stress; measure sorting, searching and assignment separately. Fixed-size arrays currently limit scale. Do not claim a benchmark or test was run unless it was actually executed.
