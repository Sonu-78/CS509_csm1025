#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>

// ============================================================
// Weighted CSR Graph
// ============================================================

struct WeightedCSR
{
    int V;
    int E;
    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

// ============================================================
// Graph Input Function
// ============================================================

bool readWeightedCSR(
    const std::string& filename,
    WeightedCSR& graph,
    int& source
);

#endif