# Push_swap - 42 Project

## 📋 Overview

Push_swap is an algorithmic project at 42 School. The goal is to sort
data on a stack, with a limited set of instructions, using the lowest
possible number of actions.

This implementation (v1.1) features an **Adaptive Router** that
dynamically selects the most efficient sorting algorithm based on the
stack size and the calculated "disorder" level of the input.

------------------------------------------------------------------------

## 👥 Team & Work Breakdown

This project was developed collaboratively by:

### **aravakia**

-   **Core Algorithms:** Implemented the `Complex` strategy using
    **Radix Sort** (bitwise operations) for large datasets.
-   **Stack Operations:** Developed and tested all core stack
    manipulations (`sa`, `pb`, `ra`, `rra`, etc.).
-   **Optimization:** Handled the indexing logic required for the Radix
    Sort to function with negative numbers and large integers.

### **msanoaya**

-   **Architecture & Parsing:** Built the robust argument parser, error
    management, and memory leak prevention (valgrind/leaks tested).
-   **Micro-sort & Router:** Designed the hardcoded logic for small
    stacks (\<= 5 elements) and the `Adaptive` strategy router.
-   **Benchmarking:** Implemented the custom `--bench` flag to calculate
    disorder percentages and track operation counts.

------------------------------------------------------------------------

## 🛠️ Sorting Strategies

The program analyzes the input and routes it to one of four strategies:

1.  **Micro-sort (N \<= 5)**\
    Hardcoded logic for small inputs. Guarantees \< 12 operations.

2.  **Simple O(n²)**\
    Selection-style sorting for nearly sorted inputs.

3.  **Medium (fallback strategy)**\
    Used when input is partially sorted.

4.  **Complex O(n log n)**\
    **Radix Sort** using indexed values and bitwise operations.

------------------------------------------------------------------------

## 📊 Performance Benchmarks

  Elements   Average Operations   42 Limits
  ---------- -------------------- -----------------------------------
  3          1 - 2                \<= 3
  5          9 - 11               \<= 12
  100        \~1080               \< 700 (5 pts) / \< 1100 (3 pts)
  500        \~6780               \< 5500 (5 pts) / \< 7000 (4 pts)

------------------------------------------------------------------------

## 🚀 How to Run

### Compilation

``` bash
make
```

### Usage

``` bash
./push_swap 3 2 5 1 4
```

### 📊 Benchmark Mode

``` bash
./push_swap --bench 9 1 8 2 7 3 6 4 5
```

Outputs: - disorder percentage - selected strategy - operation counts
(stderr)

------------------------------------------------------------------------

## 🔄 Valid Instructions

-   `sa`, `sb`, `ss` --- swap top elements\
-   `pa`, `pb` --- push between stacks\
-   `ra`, `rb`, `rr` --- rotate up\
-   `rra`, `rrb`, `rrr` --- reverse rotate

------------------------------------------------------------------------

## 🧪 Testing with Checker

``` bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```
