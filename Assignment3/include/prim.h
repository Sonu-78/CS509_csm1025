#ifndef PRIM_H
#define PRIM_H

#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

vector<Edge> primMST(const WeightedCSR &graph,
                     long long &totalWeight);

#endif
