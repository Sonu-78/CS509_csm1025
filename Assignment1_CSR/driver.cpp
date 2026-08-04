#include "include/csr.h"
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Usage: csr.exe <input_file>\n";
        return 1;
    }

    CSR g;

    g.readGraph(argv[1]);

    auto start = chrono::high_resolution_clock::now();

    g.convertToCSR();
    string input = argv[1];

string output = input.substr(input.find_last_of("\\/") + 1);

output = output.substr(0, output.find_last_of('.'));

ofstream fout("outputs/" + output + "_output.txt");

    auto end = chrono::high_resolution_clock::now();

   // g.printCSR();
   cout << "\nrow_ptr:\n";
fout << "row_ptr:\n";

for (int x : g.row_ptr) {
    cout << x << " ";
    fout << x << " ";
}

cout << "\n\ncol_idx:\n";
fout << "\n\ncol_idx:\n";

for (int x : g.col_idx) {
    cout << x << " ";
    fout << x << " ";
}

cout << "\n\nvalues:\n";
fout << "\n\nvalues:\n";

for (int x : g.values) {
    cout << x << " ";
    fout << x << " ";
}

    auto t = chrono::duration<double, milli>(end - start);

    cout << "\n\nExecution Time: " << t.count() << " ms\n";

fout << "\n\nExecution Time: " << t.count() << " ms\n";

fout.close();

    return 0;
}

