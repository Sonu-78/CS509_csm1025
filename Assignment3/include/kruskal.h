#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

vector<Edge> kruskalMST(const WeightedCSR &graph,
                        long long &totalWeight);

#endif
