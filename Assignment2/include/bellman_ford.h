#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include<vector>
#include "graph.h"
bool bellmanFord(
    const WeightedCSR& graph,
    int source,
    std::vector<long long>&dist
);
#endif