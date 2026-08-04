#include "../include/gemm.h"
#include <iostream>

using namespace std;

// Simple GEMM
void simpleGEMM(const vector<vector<int>>& A,
                const vector<vector<int>>& B,
                vector<vector<int>>& C)
{
    int M = A.size();
    int K = A[0].size();
    int N = B[0].size();

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < K; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Blocked GEMM
void blockedGEMM(const vector<vector<int>>& A,
                 const vector<vector<int>>& B,
                 vector<vector<int>>& C,
                 int blockSize)
{
    int M = A.size ();
    int K = A[0].size();
    int N = B[0].size();

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = 0;

    for (int ii = 0; ii < M; ii += blockSize)
        for (int jj = 0; jj < N; jj += blockSize)
            for (int kk = 0; kk < K; kk += blockSize)
                for (int i = ii; i < min(ii + blockSize, M); i++)
                    for (int j = jj; j < min(jj + blockSize, N); j++)
                        for (int k = kk; k < min(kk + blockSize, K); k++)
                            C[i][j] += A[i][k] * B[k][j];
}

// Print Matrix
void printMatrix(const vector<vector<int>>& C)
{
    for (const auto &row : C) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

}     
bool compareMatrix(const vector<vector<int>>& A,
                   const vector<vector<int>>& B)
{
    return A == B;
}




