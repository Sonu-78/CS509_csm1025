#ifndef GEMM_H
#define GEMM_H

#include <vector>
using namespace std;

void simpleGEMM(const vector<vector<int>>& A,
                const vector<vector<int>>& B,
                vector<vector<int>>& C);

void blockedGEMM(const vector<vector<int>>& A,
                 const vector<vector<int>>& B,
                 vector<vector<int>>& C,
                 int blockSize);

void printMatrix(const vector<vector<int>>& C); 
bool compareMatrix(const vector<vector<int>>& A,
                   const vector<vector<int>>& B);

#endif