#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "include/gemm.h"

using namespace std;
using namespace chrono;
int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "Usage: .\\gemm.exe <input_file>\n";
        return 1;
    }

    ifstream fin(argv[1]);

    if (!fin) {
        cout << "Error opening input file!\n";
        return 1;
    }

    int M, K, N;
    fin >> M >> K >> N;

    vector<vector<int>> A(M, vector<int>(K));
    vector<vector<int>> B(K, vector<int>(N));
    vector<vector<int>> C1(M, vector<int>(N));
    vector<vector<int>> C2(M, vector<int>(N));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            fin >> A[i][j];

    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            fin >> B[i][j];

    fin.close();

    auto start = high_resolution_clock::now();
    simpleGEMM(A, B, C1);
    auto end = high_resolution_clock::now();

    cout << "\nAlgorithm : Simple GEMM\n";
    printMatrix(C1);

    cout << "Execution Time : "
         << duration<double, milli>(end - start).count()
         << " ms\n";

    start = high_resolution_clock::now();
    int blockSize = 32;

cout << "Block Size : " << blockSize << endl;
blockedGEMM(A, B, C2, blockSize);
    end = high_resolution_clock::now();
    cout << "\nAlgorithm : Blocked GEMM\n";
    printMatrix(C2);
cout << "Execution Time : "
     << duration<double, milli>(end - start).count()
     << " ms\n";
cout << "\nVerification : "
     << (compareMatrix(C1, C2) ? "PASS" : "FAIL")
     << endl;

return 0;


  
}