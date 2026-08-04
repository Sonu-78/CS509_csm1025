## Assignment 01 – General Matrix Multiplication (GEMM)

### Assignment Mode
Single

### Objective
Implement and compare two matrix multiplication algorithms:
- Simple GEMM
- Blocking GEMM

Both implementations produce the same result matrix while measuring only the algorithm execution time.

### Algorithm / Approach
- **Simple GEMM:** Uses the standard three nested loops to compute the matrix product.
- **Blocking GEMM:** Divides matrices into fixed-size blocks to improve cache locality and performance.

### Input Format
Each input file contains:
```
M K N
Matrix A (M × K)
Matrix B (K × N)
```
where:
- **A** is of size **M × K**
- **B** is of size **K × N**
- The output matrix **C** is of size **M × N**

### Helper Functions / CSR Conversion (if applicable)
Not applicable. CSR conversion is required only for graph-based assignments.

### File Structure
```
assignment_01/
├── driver.cpp
├── include/
│   └── gemm.h
├── src/
│   └── gemm.cpp
├── tests/
│   ├── gemm_test_01.txt
│   ├── gemm_test_02.txt
│   ├── gemm_test_03.txt
│   ├── gemm_test_04.txt
│   └── gemm_test_05.txt
├── outputs/
│   ├── output_01.txt
│   ├── output_02.txt
│   ├── output_03.txt
│   ├── output_04.txt
│   └── output_05.txt
└── README.md
```

### Compilation
```bash
g++ driver.cpp src/gemm.cpp -Iinclude -o gemm
```

### Execution
```bash
./gemm tests/gemm_test_01.txt
```

### Test Cases and Result Table

| Mode | Test File | Input Type | Matrix Dimensions | Expected Output | Actual Output | Simple Time | Blocking Time | Status |
|------|-----------|------------|-------------------|-----------------|---------------|------------:|--------------:|:------:|
| Single | gemm_test_01.txt | Matrix | M × K, K × N | Matrix Product | Matrix Product | ___ ms | ___ ms | Pass |
| Single | gemm_test_02.txt | Matrix | M × K, K × N | Matrix Product | Matrix Product | ___ ms | ___ ms | Pass |
| Single | gemm_test_03.txt | Matrix | M × K, K × N | Matrix Product | Matrix Product | ___ ms | ___ ms | Pass |
| Single | gemm_test_04.txt | Matrix | M × K, K × N | Matrix Product | Matrix Product | ___ ms | ___ ms | Pass |
| Single | gemm_test_05.txt | Matrix | M × K, K × N | Matrix Product | Matrix Product | ___ ms | ___ ms | Pass |

### Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Simple GEMM | O(M × K × N) | O(1) (excluding output matrix) |
| Blocking GEMM | O(M × K × N) | O(1) (excluding output matrix) |

### References
1. CS509 Assignment 1 – GEMM Specification.
2. CS509 Lab Work Guidelines.
3. T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, *Introduction to Algorithms*.