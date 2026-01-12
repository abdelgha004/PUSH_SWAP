*This project has been created as part of the 42 curriculum by aakourya.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.
The goal is to sort a list of integers in ascending order using **two stacks** and a **limited set of operations**, while keeping the number of operations as low as possible.

At the start:

* **Stack A** contains all the numbers to sort
* **Stack B** is empty
* Only specific stack operations are allowed

The difficulty of the project is not sorting itself, but **choosing the right operations efficiently**.

---

## Allowed Operations

The following operations can be used:

| Operation | Description |
|-----------|-------------|
| **sa** | Swap the first two elements of stack A |
| **sb** | Swap the first two elements of stack B |
| **ss** | Swap both stacks simultaneously (sa + sb) |
| **pa** | Push the top element from stack B to stack A |
| **pb** | Push the top element from stack A to stack B |
| **ra** | Rotate stack A upwards (first element becomes last) |
| **rb** | Rotate stack B upwards (first element becomes last) |
| **rr** | Rotate both stacks upwards simultaneously |
| **rra** | Reverse rotate stack A (last element becomes first) |
| **rrb** | Reverse rotate stack B (last element becomes first) |
| **rrr** | Reverse rotate both stacks simultaneously |
---

## Instructions

### Compilation

Compile the main program:

```bash
make
```

Compile the bonus checker:

```bash
make bonus
```

### Execution

Run `push_swap` with numbers as arguments:

```bash
./push_swap 4 2 7 1 3
```

Or as a single string:

```bash
./push_swap "4 2 7 1 3"
```

The program prints the operations needed to sort the stack.

### Checker (Bonus)

To verify the result:

```bash
./push_swap 4 2 7 1 3 | ./checker 4 2 7 1 3
```

* `OK` → stack is sorted correctly
* `KO` → stack is not sorted

### Input Rules

* Only valid integers are accepted
* No duplicates
* Values must fit in `int` range
* Invalid input stops the program and prints `Error`

---

## Algorithm Approach

The project uses a **chunking and rotation strategy** optimized for different input sizes:

1. **Small Stacks (≤5 elements):** Direct hardcoded optimal sorts
2. **Medium Stacks (6-100 elements):** Fixed block chunk strategy with push-back optimization
3. **Large Stacks (100+ elements):** Incremental/sliding chunk strategy with efficient rotation and index-based sorting

The algorithm prioritizes **minimizing operation count** by:

* Grouping numbers into chunks
* Strategically rotating stacks to reduce push/pop operations
* Using index-based sorting to reduce complexity

---

## Resources

### References

* 42 Network — *push_swap* subject
* Sorting algorithms overview:
  [https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* Stack data structure (GeeksforGeeks):
  [https://www.geeksforgeeks.org/dsa/stack-data-structure/](https://www.geeksforgeeks.org/dsa/stack-data-structure/)
* Push_swap visualizer:
  [https://saadloukili.github.io/Push-Swap-Visualizer/](https://saadloukili.github.io/Push-Swap-Visualizer/)
* Push_swap algorithm article:
  [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI Usage

AI tools (ChatGPT) were used only as a **learning and explanation aid**, mainly for:

* Understand and clarify algorithm concepts (chunks, indexing)
* Help organize ideas and explain the logic in a clear way
* Assist in writing and structuring this README file
* Suggest test cases and help verify the program behavior during testing