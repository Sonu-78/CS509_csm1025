# Assignment 01 – GEMM (General Matrix Multiplication)

## Assignment Mode
Single

## Objective
Implement and compare two matrix multiplication algorithms:
- Simple GEMM
- Blocking GEMM

Both algorithms compute the same output matrix while comparing execution time.

## Language & Environment
- Language: C++
- Compiler: g++
- Driver: `driver.cpp`

## Directory Structure
```
assignment_01/
├── src/
├── driver/
│   └── driver.cpp
├── tests/
│   ├── gemm_test_01.txt
│   ├── gemm_test_02.txt
│   └── ...
├── outputs/
└── README.md
```

## Algorithm
- **Simple GEMM:** Standard triple nested-loop matrix multiplication.
- **Blocking GEMM:** Matrix multiplication using block (tile) decomposition to improve cache utilization.

## Input Format
```
M K N
Matrix A (M × K)
Matrix B (K × N)
```

## Compilation
```bash
g++ driver/driver.cpp src/*.cpp -o gemm
```

## Execution
```bash
./gemm tests/gemm_test_01.txt
```

## Output
The program prints:
- Result matrix (Simple GEMM)
- Execution time
- Result matrix (Blocking GEMM)
- Execution time

> Only algorithm execution time is measured.

## Result Table

| Mode | Test File | Input Type | Matrix Size | Expected Output | Actual Output | Simple Time | Blocking Time | Status |
|------|-----------|------------|-------------|-----------------|---------------|-------------|---------------|--------|
| Single | gemm_test_01.txt | Matrix | M×K, K×N | Matrix Product | Matrix Product | ____ ms | ____ ms | Pass |
| Single | gemm_test_02.txt | Matrix | M×K, K×N | Matrix Product | Matrix Product | ____ ms | ____ ms | Pass |

## Complexity

| Algorithm | Time | Space |
|-----------|------|-------|
| Simple GEMM | O(M×K×N) | O(1) (excluding output matrix) |
| Blocking GEMM | O(M×K×N) | O(1) (excluding output matrix) |

## Notes
- Both implementations produce identical output.
- Timing excludes file reading, parsing, and output printing.
- `driver.cpp` is responsible for reading input, invoking the algorithms, and reporting execution time.