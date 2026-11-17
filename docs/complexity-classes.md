# Complexity classes and decision formulation

Consider the decision question: given drivers, compatible spaces, reservation intervals and a cost limit K, does a conflict-free assignment with total cost at most K exist? A certificate lists each assignment. A verifier can check compatibility, interval overlap, capacities and total cost in polynomial time, so this formulation is in NP under standard integer encoding.

A formal NP-hardness claim for the precise model needs a complete polynomial reduction from a known NP-hard problem, including construction and yes/no equivalence. Do not call a program NP-complete merely because it uses backtracking. P contains polynomial-time decision problems; NP contains problems with polynomially verifiable certificates; NP-hard means at least as hard as every problem in NP under the selected reduction; NP-complete means both NP and NP-hard. The current greedy allocator is a heuristic, not an exact optimizer.
