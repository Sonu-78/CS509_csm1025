#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// ============================================================
// ASSIGNMENT 1 - GEMM
// ============================================================

void runGEMMOne()
{
    string test;

    cout << "\nEnter GEMM test file (Example: tests\\gemm_test_01.txt): ";
    cin >> test;

    string cmd = "cd ../assignment1 && gemm.exe " + test;

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute GEMM or test file not found.\n";
}

void runGEMMAll()
{
    cout << "\nRunning all GEMM test files...\n";

    system("cd ../assignment1 && gemm.exe tests\\gemm_test_01.txt");
    system("cd ../assignment1 && gemm.exe tests\\gemm_test_02.txt");
    system("cd ../assignment1 && gemm.exe tests\\gemm_test_03.txt");
}


// ============================================================
// ASSIGNMENT 1 - CSR
// ============================================================

void runCSROne()
{
    string test;

    cout << "\nEnter CSR test file (Example: tests\\csr_10.txt): ";
    cin >> test;

    string cmd = "cd ../assignment1_CSR && csr.exe " + test;

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute CSR or test file not found.\n";
}

void runCSRAll()
{
    cout << "\nRunning all CSR test files...\n";

    system("cd ../assignment1_CSR && csr.exe tests\\csr_10.txt");
    system("cd ../assignment1_CSR && csr.exe tests\\csr_100.txt");
    system("cd ../assignment1_CSR && csr.exe tests\\csr_50000.txt");
}


// ============================================================
// ASSIGNMENT 2 - GRAPH ALGORITHMS
// Bellman-Ford + Floyd-Warshall
// ============================================================

void runAssignment2()
{
    cout << "\nRunning Assignment 2...\n";
    cout << "Bellman-Ford and Floyd-Warshall\n\n";

    string cmd = "cd ../Assignment2 && assignment2.exe";

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute Assignment 2.\n";
}


// ============================================================
// ASSIGNMENT 3 - MST
// Prim + Kruskal
// ============================================================

void runMSTOne()
{
    string algorithm;
    string test;

    cout << "\nEnter MST algorithm (prim / kruskal / both): ";
    cin >> algorithm;

    cout << "Enter MST test file (Example: tests\\mst_10.txt): ";
    cin >> test;

    string cmd =
        "cd ../assignment3 && mst.exe " +
        algorithm + " " + test;

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute MST or test file not found.\n";
}


void runMSTAll()
{
    cout << "\nRunning all MST test files...\n";

    cout << "\n========== mst_10.txt ==========\n";
    system("cd ../assignment3 && mst.exe both tests\\mst_10.txt");

    cout << "\n========== mst_100.txt ==========\n";
    system("cd ../assignment3 && mst.exe both tests\\mst_100.txt");

    cout << "\n========== mst_10000.txt ==========\n";
    system("cd ../assignment3 && mst.exe both tests\\mst_10000.txt");

    cout << "\n========== mst_50000.txt ==========\n";
    system("cd ../assignment3 && mst.exe both tests\\mst_50000.txt");

    cout << "\n========== mst_100000.txt ==========\n";
    system("cd ../assignment3 && mst.exe both tests\\mst_100000.txt");
}


void runMSTPrim()
{
    string test;

    cout << "\nEnter MST test file (Example: tests\\mst_10.txt): ";
    cin >> test;

    string cmd =
        "cd ../assignment3 && mst.exe prim " + test;

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute Prim MST.\n";
}


void runMSTKruskal()
{
    string test;

    cout << "\nEnter MST test file (Example: tests\\mst_10.txt): ";
    cin >> test;

    string cmd =
        "cd ../assignment3 && mst.exe kruskal " + test;

    if (system(cmd.c_str()) != 0)
        cout << "\nError: Unable to execute Kruskal MST.\n";
}


// ============================================================
// RUN ALL ASSIGNMENTS
// ============================================================

void runAllAssignments()
{
    cout << "\n=========================================\n";
    cout << "       RUNNING ALL ASSIGNMENTS\n";
    cout << "=========================================\n";

    cout << "\n========== ASSIGNMENT 1 - GEMM ==========\n";
    runGEMMAll();

    cout << "\n========== ASSIGNMENT 1 - CSR ==========\n";
    runCSRAll();

    cout << "\n========== ASSIGNMENT 2 ==========\n";
    runAssignment2();

    cout << "\n========== ASSIGNMENT 3 - MST ==========\n";
    runMSTAll();
}


// ============================================================
// MAIN MENU
// ============================================================

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "          CS509 COMMON WRAPPER\n";
        cout << "=========================================\n";
        cout << "Assignment 1 - GEMM\n";
        cout << "Assignment 1 - CSR\n";
        cout << "Assignment 2 - Graph Algorithms\n";
        cout << "Assignment 3 - Minimum Spanning Tree\n";
        cout << "=========================================\n";

        cout << "1. Assignment 1 - GEMM (Single Test)\n";
        cout << "2. Assignment 1 - GEMM (All Tests)\n";

        cout << "3. Assignment 1 - CSR (Single Test)\n";
        cout << "4. Assignment 1 - CSR (All Tests)\n";

        cout << "5. Assignment 2 (Bellman-Ford + Floyd-Warshall)\n";

        cout << "6. Assignment 3 - MST (Single Test)\n";
        cout << "7. Assignment 3 - Prim (Single Test)\n";
        cout << "8. Assignment 3 - Kruskal (Single Test)\n";
        cout << "9. Assignment 3 - MST (All Tests)\n";

        cout << "10. Run All Assignments\n";

        cout << "0. Exit\n";
        cout << "=========================================\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                runGEMMOne();
                break;

            case 2:
                runGEMMAll();
                break;

            case 3:
                runCSROne();
                break;

            case 4:
                runCSRAll();
                break;

            case 5:
                runAssignment2();
                break;

            case 6:
                runMSTOne();
                break;

            case 7:
                runMSTPrim();
                break;

            case 8:
                runMSTKruskal();
                break;

            case 9:
                runMSTAll();
                break;

            case 10:
                runAllAssignments();
                break;

            case 0:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}