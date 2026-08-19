#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

struct AdjEdge
{
    int to;
    int weight;
};

struct WeightedAdjList
{
    int V;
    int E;
    vector<vector<AdjEdge>> adj;
};

struct WeightedCSR
{
    int V;
    int E;
    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

struct Edge
{
    int u;
    int v;
    int weight;
};

// Previous-assignment style helpers.
bool readWeightedAdjList(const string &filename,
                         WeightedAdjList &graph,
                         int &source);

void convertToCSR(const WeightedAdjList &adjGraph,
                  WeightedCSR &csrGraph);

bool readWeightedCSR(const string &filename,
                     WeightedCSR &graph,
                     int &source);

vector<Edge> getEdgeList(const WeightedCSR &graph);

#endif
