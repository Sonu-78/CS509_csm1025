# Assignment 3 – Minimum Spanning Tree (MST)

## 1. Objective

Implement and compare **Kruskal's** and **Prim's** Minimum Spanning Tree algorithms on the same weighted, undirected CSR graph.

The adjacency-list input is converted to CSR using the helper from the previous assignment. CSR conversion and file I/O are **not included** in the reported algorithm time.

## 2. Project Structure


Assignment3/
├── driver/
│   └── mst_driver.cpp
├── include/
│   ├── graph.h
│   ├── kruskal.h
│   └── prim.h
├── src/
│   ├── graph.cpp
│   ├── kruskal.cpp
│   └── prim.cpp
├── tests/
│   ├── mst_10.txt
│   ├── mst_100.txt
│   ├── mst_10000.txt
│   ├── mst_50000.txt
│   └── mst_100000.txt
├── generate_mst.cpp
└── README.md
3. Algorithms
Kruskal: Sorts edges by weight and uses  Union-Find/DSU to avoid cycles.
Prim: Starts from vertex 0 and repeatedly selects the minimum-weight edge that adds a new vertex.
Both algorithms should produce the same minimum MST weight.
4. Input Graphs

All graphs are weighted, undirected, connected,and sparse.

| File           |       V |       E | Graph Type          | Property |
| -------------- | ------: | ------: | ------------------- | -------- |
| mst_10.txt     |      10 |      15 | Undirected weighted | Small    |
| mst_100.txt    |     100 |     197 | Undirected weighted | Sparse   |
| mst_10000.txt  |  10,000 |  19,997 | Undirected weighted | Sparse   |
| mst_50000.txt  |  50,000 |  99,997 | Undirected weighted | Sparse   |
| mst_100000.txt | 100,000 | 199,997 | Undirected weighted | Sparse   |

Each undirected edge is counted once in E, although it appears in both adjacency lists.

5. Build and Run

From the Assignment3 directory in Windows PowerShell:
g++ -std=c++17 -Wall -Iinclude driver\mst_driver.cpp src\graph.cpp src\kruskal.cpp src\prim.cpp -o mst.exe

Run Kruskal:
.\mst.exe kruskal tests\mst_10.txt
Run Prim:
.\mst.exe prim tests\mst_10.txt

Run both for comparison:
.\mst.exe both tests\mst_10.txt

6. MST Results

| File           |       V |       E | Exp. Wt. | Kruskal Wt. | Prim Wt. | Kruskal Time | Prim Time | Equal? | Status    |
| -------------- | ------: | ------: | -------: | ----------: | -------: | -----------: | --------: | ------ | --------- |
| mst_10.txt     |      10 |      15 |       23 |         23 |      23   |   0.044300 ms|0.020700ms| Yes | Pass |
| mst_100.txt    |     100 |     197 |     2523 |         2523 |      2523 |     0.108800   ms |  0.308200    ms | Yes/No | Pass/Fail |
| mst_10000.txt  |  10,000 |  19,997 |   260293 |          260293 |       260293 |       8.573100 ms |     40.236500 ms | Yes/No | Pass/Fail |
| mst_50000.txt  |  50,000 |  99,997 |  1301959 |          1301959 |       1301959 |       46.522900 ms |    217.587300 ms | Yes/No | Pass/Fail |
| mst_100000.txt | 100,000 | 199,997 |  2604047 |        2604047  |      2604047 |        85.076400 ms |    459.880100 ms | Yes/No | Pass/Fail |

7. Timing Rule

Only the algorithm execution time is reported.

Excluded:

File reading
Input validation
Adjacency-list construction
CSR conversion
Output printing
Result comparison

For Kruskal, edge extraction and sorting are part of the Kruskal algorithm and should be included in its measured time.

8. Driver Behaviour

The driver supports:
kruskal <input-file>
prim <input-file>
both <input-file>
The both option runs Kruskal and Prim on the same input graph for comparison.

Invalid or missing input files should produce a clear error message.
9. Expected Result

For every valid connected graph:
Kruskal MST Weight == Prim MST Weight
If both weights are equal, the result is marked Pass.