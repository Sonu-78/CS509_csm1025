# Assignment 2 – Graph Algorithms

## 1. Objective

Implement and evaluate graph algorithms using **Compressed Sparse Row (CSR)** representation:

* Bellman-Ford for Single-Source Shortest Path (SSSP)
* Floyd-Warshall for All-Pairs Shortest Path (APSP)

The execution time is measured for different graph sizes.

## 2. Project Structure

```text
assignment_02/
├── driver/
│   └── driver.cpp
├── include/
│   ├── graph.h
│   ├── bellman_ford.h
│   └── floyd_warshall.h
├── src/
│   ├── graph.cpp
│   ├── bellman_ford.cpp
│   └── floyd_warshall.cpp
└── tests/
    ├── bf_10.txt
    ├── bf_100.txt
    ├── bf_10000.txt
    ├── bf_50000.txt
    ├── bf_100000.txt
    └── floyd_warshall/
        ├── fw_10.txt
        ├── fw_100.txt
        ├── fw_500.txt
        ├── fw_1000.txt
        └── fw_2000.txt
```

## 3. Input Format

Each weighted graph file contains:

V E
vertex degree neighbor weight ...
...
SOURCE source_vertex
```

Example:

```text
10 15
0 2 1 6 2 7
1 2 2 5 3 8
2 2 3 -2 4 4
3 1 4 3
4 2 5 -1 6 2
5 2 6 3 7 4
6 1 8 -2
7 2 8 1 9 5
8 1 9 2
9 0
SOURCE 0
```

## 4. Algorithms

### Bellman-Ford

Computes shortest-path distances from a given source vertex and detects negative-weight cycles.

**Time Complexity:** `O(VE)`

### Floyd-Warshall

Computes shortest paths between every pair of vertices and detects negative cycles.

**Time Complexity:** `O(V³)`

## 5. Bellman-Ford Results

| Test Case     | Vertices (V) | Edges (E) | Time (ms) | Negative Cycle |
| ------------- | -----------: | --------: | --------: | -------------- |
| bf_10.txt     |           10 |        15 |    0.0051 | None           |
| bf_100.txt    |          100 |       195 |    0.0261 | None           |
| bf_10000.txt  |       10,000 |    19,997 |    1.8934 | None           |
| bf_50000.txt  |       50,000 |    99,997 |    5.9844 | None           |
| bf_100000.txt |      100,000 |   199,997 |   11.1791 | None           |

For `bf_10.txt`, the computed distances from source `0` were:

```text
0  0
1  6
2  7
3  5
4  8
5  7
6  10
7  11
8  8
9  10
```

For `bf_100.txt`, the distances were:

```text
0 1 2 3 4 5 6 7 8 9
...
99 99
```

No negative cycle was detected in any Bellman-Ford test.

## 6. Floyd-Warshall Results

| Test Case   | Vertices (V) | Edges (E) | Time (ms) | Negative Cycle |
| ----------- | -----------: | --------: | --------: | -------------- |
| fw_10.txt   |           10 |        17 |    0.0127 | None           |
| fw_100.txt  |          100 |       197 |    5.4289 | None           |
| fw_500.txt  |          500 |       997 |   300.205 | None           |
| fw_1000.txt |        1,000 |     1,997 |  2,335.43 | None           |
| fw_2000.txt |        2,000 |     3,997 |    19,235 | None           |

The complete distance matrix was printed for `fw_10.txt`. Larger matrices were not printed to avoid excessive output.

## 7. Comparison

| Algorithm      | Problem                     | Complexity | Largest Tested Graph |
| -------------- | --------------------------- | ---------- | -------------------: |
| Bellman-Ford   | Single-source shortest path | O(VE)      |     100,000 vertices |
| Floyd-Warshall | All-pairs shortest path     | O(V³)      |       2,000 vertices |

Floyd-Warshall becomes significantly more expensive as the number of vertices increases because its running time is cubic in `V`. Bellman-Ford handled much larger graphs in the tested cases.

## 8. Compilation

From the assignment directory:

```powershell
g++ -std=c++17 driver\driver.cpp src\graph.cpp src\bellman_ford.cpp src\floyd_warshall.cpp -Iinclude -o assignment2.exe
```

## 9. Execution

```powershell
.\assignment2.exe
```

## 10. Conclusion

Both Bellman-Ford and Floyd-Warshall were implemented using the weighted CSR graph representation. The tests successfully loaded the graphs, computed shortest paths, measured execution time, and checked for negative cycles. The measured results also demonstrate the expected higher computational cost of Floyd-Warshall for larger graphs.
