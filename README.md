*This project has been created as part of the 42 curriculum by tsirakot, fananrak.*

# push_swap

## Description

push_swap is a sorting algorithm project where a stack of integers must be sorted
using two stacks (a and b) and a limited set of operations, with the minimum
number of moves possible. The project explores algorithmic complexity by requiring
four distinct sorting strategies.

## Instructions

### Compilation
```
make
```

### Usage
```
./push_swap [flags] [integers]
```

### Flags
- ``--simple``    Force O(n²) algorithm
- ``--medium``    Force O(n√n) algorithm
- ``--complex``   Force O(n log n) algorithm
- ``--adaptive``  Force adaptive algorithm (default)
- ``--bench``     Display performance metrics on stderr

### Examples
# Basic usage
```
./push_swap 3 1 2
```

# Force simple sort
```
./push_swap --simple 5 4 3 2 1
```

# Verify with checker
```
./push_swap --simple 3 1 2 | ./checker_linux 3 1 2
```

# Benchmark mode
```
./push_swap --bench --adaptive 3 1 2
```

# Count operations
```
./push_swap --complex 5 4 3 2 1 | wc -l
```

### Error handling
```
./push_swap 1 2 abc     # Error: not a number
./push_swap 1 1 2       # Error: duplicate
./push_swap 99999999999 # Error: overflow
```

## Algorithms

### Simple — O(n²)
Selection sort adaptation.
Find the minimum element, rotate it to the top of stack a,
push to stack b. Repeat until a is empty, then push all back to a.
Best for: nearly sorted inputs (disorder < 0.2)

### Medium — O(n√n)
Chunk sort adaptation.
Divide the values into √n chunks, push each chunk to b,
then push back to a in sorted order by finding max each time.
Best for: moderately disordered inputs (0.2 ≤ disorder < 0.5)

### Complex — O(n log n)
Radix sort LSD adaptation.
Normalize values to indices 0..n-1, then sort bit by bit
from least significant to most significant.
Best for: highly disordered inputs (disorder ≥ 0.5)

### Adaptive
Selects the appropriate algorithm based on the disorder metric:
- disorder < 0.2  → Simple O(n²)
- disorder < 0.5  → Medium O(n√n)
- disorder ≥ 0.5  → Complex O(n log n)

### Disorder metric
Measures how far the stack is from being sorted (0.0 to 1.0).
Computed as the ratio of inverted pairs over total pairs.
disorder = mistakes / total_pairs
Measured before any moves.

## Performance targets
| Input size | Minimum  | Good     | Excellent |
|------------|----------|----------|-----------|
| 100 nums   | < 2000   | < 1500   | < 700     |
| 500 nums   | < 12000  | < 8000   | < 5500    |

## Contributions
- `tsirakot`:
    - **feat:** medium, complex, operations, stack_utils
    - **fix:** norminette
- `fananrak`:
    - **feat**: main, parsing, bench, adaptative, simple, flags, disorder, error_handling
    - **fix:** operations, stack_utils

## Resources
- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
- https://www.w3schools.com/dsa/dsa_algo_selectionsort.php

## AI usage: 
- used to understand algorithm complexity concepts
