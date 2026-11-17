# Architecture

- include/: public domain records and algorithm interfaces.
- src/parking.c: domain validation and reservation conflict checks.
- src/algorithms.c: sorting, searching, divide-and-conquer and DP exercises.
- src/graph.c: road graph, shortest paths, spanning tree, flow and matching.
- src/benchmark.c: deterministic timing entry point.
- src/main.c: menu-driven CLI.
- tests/: small deterministic assertions.

The CLI keeps sample records in memory. Persistence, CSV/JSON export, generated datasets, road-network loading and a desktop interface are future work.
