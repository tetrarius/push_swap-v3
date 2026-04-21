*This project has been created as part of the 42 curriculum by aravakia, msanoaya.*

# Push_swap

## Description
Push_swap is a highly efficient C project focused on data sorting using two stacks (**a** and **b**) and a restricted set of instructions. The primary goal is to sort a random sequence of integers with the minimum number of operations.

This implementation features an **Adaptive Router** that analyzes the input's size and "disorder" level to dynamically select the most efficient sorting strategy. By combining bitwise operations, chunk-based sorting, and hardcoded logic for small sets, the program ensures optimal performance across all test cases.

## Instructions

### Compilation
The project includes a Makefile that complies with 42 standards.

```bash
make        # Compiles the push_swap executable
make clean  # Removes object files
make fclean # Removes object files and the executable
make re     # Recompiles the project
```

### Execution
Run the program by passing a list of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

You can also use the custom --bench flag (implemented in benchmark.c) to view technical statistics:

```bash
./push_swap --bench 9 1 8 2 7 3 6 4 5
```

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

## Algorithms: Explanation and Justification

The project implements four distinct strategies to stay within the strict operation limits of the 42 evaluation scale:

### 1. Micro-sort (N ≤ 5)
For very small datasets, we use a specialized hardcoded logic.

**Justification:**  
For 3 elements, we use a maximum of 2 moves. For 5 elements, we push the two smallest values to stack B and sort the remaining 3. This guarantees staying under the 12-operation limit for a maximum score.

### 2. Simple Strategy (Selection Sort)
Used for nearly sorted inputs or small-to-medium stacks where the "disorder" percentage is low.

**Justification:**  
It finds the minimum element and calculates the shortest rotation path (using size / 2 logic to choose between ra and rra). This avoids the overhead of more complex bitwise passes.

### 3. Medium Strategy (Chunk Sort / Butterfly)
Calculates groups based on sqrt(N). Elements are pushed to stack B in "chunks" to maintain a rough order before the final push back to A.

**Justification:**  
It serves as a middle ground between the simple selection sort and the heavy Radix sort, reducing total rotations for specific distributions.

### 4. Complex Strategy (Radix Sort)
A bitwise sorting algorithm that sorts numbers based on their binary representation.

**Justification:**  
Since the instructions only allow us to interact with the top of the stacks, Radix sort is highly effective. It has a time complexity of O(N⋅number of bits). We use indexing to transform any range of integers (including negatives) into a 0 to N−1 range.

## Resources

- Algorithms: "Sorting Algorithms Visualized" and "Bitwise Radix Sort Logic" (General documentation).
- Technical Ref: 42 Project Subject and Unix/Linux Man pages for C standard library functions.

### AI Usage
- **Architecture Design:** AI was used to brainstorm the Adaptive Router logic and the disorder calculation method (disorder.c).
- **Optimization:** AI assisted in refining the sqrt based chunk size calculation for the Medium strategy.
- **Documentation:** AI helped in translating technical concepts and structuring this README to meet specific school requirements.
