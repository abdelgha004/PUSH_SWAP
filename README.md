*This project has been created as part of the 42 curriculum by aakourya.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum that challenges you to sort a list of integers using only **two stacks** and a **limited set of operations**. The primary goal is not merely to sort the numbers, but to do so **efficiently**—minimizing the total number of moves required.

### Project Goal

The project enforces strict constraints:
- **Stack A** initially contains all unique integers to be sorted in ascending order
- **Stack B** starts empty and serves as a temporary workspace
- Only a predefined set of stack operations are allowed
- The challenge is to sort Stack A using the **fewest possible instructions**

This project reinforces understanding of:
- Stack data structures and linked lists
- Algorithm design under constraints
- Optimization techniques (greedy algorithms, chunking strategies)
- Complexity analysis and efficiency
- Memory management in C

---

## Allowed Operations

The following operations are available for stack manipulation:

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

## Project Structure

```
push_swap/
├── main.c                    # Main entry point
├── push_swap.h               # Header file with function prototypes
├── Makefile                  # Build configuration
├── operations/               # Stack operation implementations
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   └── rev_rotate.c
├── sort/                     # Sorting algorithms
│   ├── sort.c               # Main sorting dispatcher
│   ├── sort_small.c         # Optimized sort for 3-5 elements
│   ├── sort_medium.c        # Sort for 6-100 elements
│   ├── sort_large.c         # Efficient sort for 100+ elements
│   └── sort_helpers.c       # Helper functions for sorting
├── stack/                    # Stack initialization and utilities
│   ├── init_stack.c
│   └── stack_utils.c
├── utils/                    # Utility functions
│   ├── ft_atol.c
│   ├── ft_split.c
│   ├── ft_substr.c
│   ├── ft_lstadd_back.c
│   ├── ft_lstnew.c
│   ├── ft_lstclear.c
│   └── helpers.c
├── CHECKER/                  # Bonus: Checker program to verify sorting
│   ├── checker.c
│   ├── checker_utils.c
│   └── get_next_line/        # Utilities for reading input
└── README.md                 # This file
```

---

## Instructions

### Compilation

**Main Program:**
```bash
make
```

This compiles the `push_swap` executable. The program will read a list of integers and output the necessary operations to sort them.

**Bonus - Checker Program:**
```bash
make bonus
```

This compiles the `checker` program, which verifies whether a sequence of operations correctly sorts the provided numbers.

### Execution

**push_swap:**
```bash
./push_swap [number1] [number2] [number3] ...
```

Example:
```bash
./push_swap 4 2 7 1 3
```

The program outputs each operation on a separate line, which represents the steps to sort the stack.

**checker (bonus):**
```bash
./checker [number1] [number2] [number3] ...
```

Then provide a list of operations (one per line). End input with `Ctrl+D`. The checker will verify if the operations correctly sort the stack and output "OK" or "KO".

Example:
```bash
./checker 4 2 7 1 3
pb
pb
pb
ra
pa
pa
pa
Ctrl+D
```

### Input Validation

- All arguments must be valid integers (within `int` range)
- Duplicate numbers are **not allowed**
- Numbers can be provided as separate arguments or within a quoted string
- Error handling for invalid input: the program exits with no output for invalid input

### Cleanup

Remove compiled objects and executables:
```bash
make clean      # Remove object files
make fclean     # Remove object files and executables
make re         # Rebuild everything
```

---

## Algorithm Approach

The project uses a **chunking and rotation strategy** optimized for different input sizes:

1. **Small Stacks (≤5 elements):** Direct hardcoded optimal sorts
2. **Medium Stacks (6-100 elements):** Chunking strategy with push-back optimization
3. **Large Stacks (100+ elements):** Advanced chunking with efficient rotation and indexing

The algorithm prioritizes **minimizing operation count** by:
- Grouping numbers into chunks
- Strategically rotating stacks to reduce push/pop operations
- Using index-based sorting to reduce complexity

---

## Key Features

- **Efficient sorting** for various input sizes
- **Memory-safe** C implementation with proper linked list management
- **Comprehensive error handling** for invalid input
- **Bonus checker program** to verify sorting correctness
- **Makefile-based compilation** for easy building
- **Modular design** with separated concerns (operations, sorting, utilities)

---

## Resources

### Official References
- [42 School](https://42.fr/) - The 42 curriculum
- [C Standard Library Documentation](https://en.cppreference.com/w/c) - Reference for C functions
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) - General concepts
- [Sorting Algorithms Overview](https://www.geeksforgeeks.org/sorting-algorithms/) - Algorithm concepts

### Helpful Tutorials
- [Linked Lists in C](https://www.geeksforgeeks.org/data-structures/linked-list/) - Implementation guide
- [Algorithm Optimization](https://www.khanacademy.org/computing/computer-science/algorithms/) - General algorithm concepts
- [Memory Management in C](https://www.geeksforgeeks.org/malloc-vs-calloc/) - Dynamic memory best practices

### Recommended Reading
- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262033848/) - Classic algorithm reference
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language) - Definitive C guide

---

## AI Usage

AI was used to assist with the following aspects of this project:

### Tasks Where AI Was Used:
1. **Code Review & Debugging** - Identifying logical errors and edge cases in sorting algorithms
2. **Optimization Suggestions** - Recommending algorithmic improvements for large stacks
3. **Function Implementation** - Assisting with utility function implementations (string parsing, linked list operations)
4. **Documentation** - Writing code comments and explaining complex sections
5. **Memory Management** - Guidance on preventing memory leaks and proper cleanup

### Parts of the Project Assisted by AI:
- **Operations module** - Verification and optimization of stack manipulation functions
- **Sort module** - Strategy refinement for chunking and rotation algorithms
- **Utils module** - Efficient implementations of helper functions (atol, split, substr, list operations)
- **Error handling** - Comprehensive input validation and error reporting
- **General architecture** - Project structure and modular organization recommendations

---

## Contact & Support

For questions or issues related to this project, refer to the 42 curriculum documentation or seek help from fellow students and mentors at 42.

---

**Last Updated:** January 2026
