#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <vector>
using namespace std;

class CSR {
public:
    int V, E;
    vector<vector<int>> adj;
    //vector<int> row_ptr, col_idx;
    vector<int> row_ptr, col_idx, values;

    void readGraph(const string &file);
    void convertToCSR();
    void printCSR();
};

#endif