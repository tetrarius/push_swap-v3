# Push_swap - 42 Project

## 📋 Overview
Push_swap is an algorithmic project at 42 School. The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

This implementation (v1.1) features an **Adaptive Router** that dynamically selects the most efficient sorting algorithm based on the stack size and the calculated "disorder" level of the input.

### 👥 Team & Work Breakdown
This project was developed collaboratively by:

- **aravakia**
  - **Core Algorithms:** Implemented the `Complex` strategy using **Radix Sort** (bitwise operations) for large datasets.
  - **Stack Operations:** Developed and tested all core stack manipulations (`sa`, `pb`, `ra`, `rra`, etc.).
  - **Optimization:** Handled the indexing logic required for the Radix Sort to function with negative numbers and large integers.

- **msanoaya**
  - **Architecture & Parsing:** Built the robust argument parser, error management, and memory leak prevention (valgrind/leaks tested).
  - **Micro-sort & Router:** Designed the hardcoded logic for small stacks (<= 5 elements) and the `Adaptive` strategy router to switch between algorithms.
  - **Benchmarking:** Implemented the custom `--bench` flag to calculate disorder percentages and track operation counts in real-time.

---

## 🛠️ Sorting Strategies
The program analyzes the input and routes it to one of four strategies:

1. **Micro-sort (N <= 5):** Hardcoded logic for 3 elements and minimum-pushing for 5 elements. Guarantees < 12 operations.
2. **Simple O(n²):** Selection-based sort for small or highly sorted sets (Disorder < 20%).
3. **Medium O(n√n):** Chunk sort for medium datasets (Disorder 20% - 49%).
4. **Complex O(n log n):** **Radix Sort**. Evaluates the binary representation of each number's rank (index) to efficiently sort large, highly chaotic stacks (Disorder >= 50%).

## 📊 Performance Benchmarks
| Elements | Average Operations | 42 Subject Limit (Max Score)   |
|----------|--------------------|--------------------------------|
| 3        | 1 - 2              | <= 3                           |
| 5        | 9 - 11             | <= 12                          |
| 100      | ~1080              | < 700 (5 pts) / < 1100 (3 pts) |
| 500      | ~6780              | < 5500 (5 pts) / < 7000 (4 pts)|

---

## 🚀 How to Run

### Compilation
Build the executable using the provided Makefile:
```bash
make

Usage

Run the program with a list of integers:
Bash

./push_swap 3 2 5 1 4

Benchmark Mode (Custom Feature)

Use the --bench flag to see the internal disorder calculation, strategy selected, and operation count output to stderr:
Bash

./push_swap --bench 9 1 8 2 7 3 6 4 5

🔄 Valid Instructions

    sa, sb, ss: Swap the first two elements at the top of the stack.

    pa, pb: Push the top element from one stack to the other.

    ra, rb, rr: Rotate the stack up (the first element becomes the last).

    rra, rrb, rrr: Reverse rotate the stack down (the last element becomes the first).

🧪 Testing with Official Checker

To test the sorting validity and count operations on 100 random numbers (Linux):
Bash

ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l
