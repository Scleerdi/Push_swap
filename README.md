*This project has been created as part of the 42 curriculum by gshabait, sicleerd.*

# push_swap

## Description

`push_swap` is a C project that sorts distinct signed integers in ascending order using two stacks and eleven permitted operations. Instead of printing sorted numbers, the program prints a sequence of stack instructions, one per line, to standard output. The goal is to produce correct sequences with as few operations as possible.

This implementation includes three explicit sorting strategies, a disorder-based adaptive selector, benchmarking, and a checker.

## Instructions

Build from the project root:

```sh
make
```

The default `make` (or `make all`) builds only `push_swap`. To compile the bonus checker, run `make bonus`. The Makefile also provides `clean`, `fclean`, and `re`.

```sh
./push_swap 4 2 3 1
./push_swap --simple 4 2 3 1
./push_swap --medium 4 2 3 1
./push_swap --complex 4 2 3 1
./push_swap --adaptive 4 2 3 1
./push_swap --bench 4 2 3 1
```

`--adaptive` is the default when no strategy is specified. Integers must be unique and fit within the signed 32-bit range. This implementation expects individual integer arguments, not a single quoted list. Invalid input prints `Error` to standard error. No arguments produce no output. The operation stream is written to standard output; `--bench` writes diagnostics to standard error.

## Allowed stack operations

| Operation | Meaning |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two elements of A, B, or both |
| `pa`, `pb` | Push the top element from B to A, or A to B |
| `ra`, `rb`, `rr` | Rotate A, B, or both (top becomes bottom) |
| `rra`, `rrb`, `rrr` | Reverse rotate A, B, or both (bottom becomes top) |

## Algorithms and technical choices

**Simple (`--simple`):** Finds the smallest value, rotates it to the top of A, and pushes it to B until three values remain. It sorts those three and pushes values back. Repeated minimum extraction and rotation can require O(n²) stack operations. It is straightforward and useful for small inputs.

**Medium (`--medium`):** Normalizes input values into sorted ranks, groups ranks into chunks, pushes chunks from A to B, and rotates B to recover values in descending rank order. The implementation uses a chunk width of approximately twice the integer square root of n. Its intended operation-count class is O(n√n); this bound should be demonstrated with measurements and an argument specific to the implementation.

**Complex (`--complex`):** Normalizes values to ranks and uses least-significant-bit binary radix passes. Each pass moves values between A and B using permitted operations. With O(log n) bits and O(n) operations per pass, its operation count is O(n log n).

**Adaptive (`--adaptive`):** Measures the fraction of inverted pairs before sorting.The subject defines three regimes: low disorder (< 0.20), medium disorder (0.20 to < 0.50), and high disorder (≥ 0.50), with operation-count targets of O(n), O(n√n), and O(n log n), respectively. The adaptive implementation is being aligned with these boundaries and targets.

**Disorder metric:** For every pair of positions i < j, count an inversion if the earlier value exceeds the later value. Divide the inversion count by n(n−1)/2. Disorder ranges from 0 for sorted input to 1 for reverse-sorted input. The subject requires measuring this before any operations.

**Space considerations:** The implementation stores input in linked-list nodes and allocates additional bookkeeping for benchmarking and rank normalization. The stack representation uses O(n) space. The disorder computation examines pairs of values, taking O(n²) comparison time; this is distinct from the subject's *operation-count* complexity model for sorting strategies.

## Benchmark mode

```sh
./push_swap --bench 4 2 3 1 > operations.txt 2> benchmark.txt
```

Benchmark output includes disorder percentage, selected strategy and complexity, total operation count, and counts by instruction type. The output is sent to standard error so it does not contaminate the instruction stream.

## Checker (bonus)

Build the checker separately:

```sh
make bonus
```

The included checker reads stack operations from standard input and prints `OK` when A is sorted and B is empty, `KO` when the final state is not correct, and `Error` to standard error for invalid input or instructions.

```sh
ARG="4 2 3 1"
./push_swap $ARG | ./checker $ARG
```

## Performance targets from subject v1.0

| Input size | Minimum passing target | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 random integers | < 2000 operations | < 1500 | < 700 |
| 500 random integers | < 12000 operations | < 8000 | < 5500 |

These are evaluation thresholds, **not claimed measured results** for this repository.

## Contributors

This project was developed collaboratively by two 42 learners, with responsibilities divided between input handling and sorting logic.

- **sicleerd — Parsing and input validation:** Implemented the argument-parsing logic, including processing input values and checking that the provided integers are valid before sorting begins.
- **gshabait — Sorting algorithms:** Implemented the sorting strategies and the logic used to generate stack operations and select an algorithm.

Both contributors worked together on integrating and testing the project.

## Resources

- **42 Push_swap subject, version 1.0:** Primary source for operations, strategy requirements, complexity model, benchmark thresholds, README requirements, and checker rules.
- **C language documentation:** `man 3 malloc`, `man 3 free`, `man 2 read`, `man 2 write`.
- **Algorithm references:** Standard explanations of insertion/selection sorting, chunk-based sorting, binary radix sorting, asymptotic notation, and inversion counts. 

**AI use disclosure:** AI assistance was used to review source comments for spelling and clarity, inspect potential defects and memory-management paths, compare the implementation with the subject, and draft this README. The team reviewed the generated documentation and remains responsible for the final code and project submission.