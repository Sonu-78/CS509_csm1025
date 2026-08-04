# Assignment 01 – Compressed Sparse Row (CSR) Representation

## Assignment Mode

Individual Assignment

## Objective

Implement the Compressed Sparse Row (CSR) representation for a weighted graph using an adjacency list as input. Store the graph using `row_ptr`, `col_idx`, and `values` arrays and analyze the execution time for different graph sizes.

## Algorithm / Approach

1. Read the weighted graph from the input file.
2. Store the graph as an adjacency list.
3. Traverse each vertex and generate:

   * `row_ptr` – starting index of each vertex's adjacency list.
   * `col_idx` – destination vertices.
   * `values` – edge weights.
4. Print the CSR arrays and execution time.

## Input Format

```
V E
vertex degree neighbor1 weight1 neighbor2 weight2 ...
```

Example:

```
5 6
0 2 1 4 2 1
1 1 3 1
2 2 1 2 3 5
3 1 4 3
4 0
```

## Helper Functions

* `readGraph()` – Reads the weighted graph.
* `convertToCSR()` – Converts the adjacency list to CSR format.
* `printCSR()` – Prints CSR arrays.

## File Structure

```
Assignment1_CSR/
│── driver.cpp
│── README.md
├── include/
│   └── csr.h
├── src/
│   └── csr.cpp
├── tests/
│   ├── csr_10.txt
│   ├── csr_100.txt
│   
│   ├── csr_50000.txt
│   
└── outputs/
    ├── csr_10_output.txt
    ├── csr_100_output.txt
    
    ├── csr_50000_output.txt
    
```

## Compilation

```bash
g++ driver.cpp src/csr.cpp -Iinclude -o csr.exe
```

## Execution

```bash
csr.exe tests/csr_10.txt
```

## Test Cases and Result Table

| Test Case      | Vertices | Edges | Execution Time (ms) | Status |
| -------------- | -------: | ----: | ------------------: | :----: |
| csr_10.txt     |        5 |     6 |              3.7633 | Passed |
| csr_100.txt    |       10 |    15 |              1.1657 | Passed |
| csr_50000.txt  |    50000 | 49999 |              8.2939| Passed |


> **Note:** Execution times were measured on the local system and may vary depending on hardware and compiler.

## Complexity

| Operation      | Time Complexity | Space Complexity |
| -------------- | --------------- | ---------------- |
| Graph Reading  | O(V + E)        | O(V + E)         |
| CSR Conversion | O(V + E)        | O(V + E)         |
| Printing CSR   | O(V + E)        | O(1)             |

## References

1. GeeksforGeeks – Sparse Matrix and CSR Representation.
2. GeeksforGeeks – Graph Representation using Adjacency List.
3. Youtube.