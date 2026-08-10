/* #include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

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

void runCSROne()
{
    string test;

    cout << "\nEnter CSR test file: ";
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

void runAllAssignments()
{
    cout << "\n========== GEMM ==========\n";
    runGEMMAll();

    cout << "\n========== CSR ==========\n";
    runCSRAll();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "      CS509 COMMON WRAPPER\n";
        cout << "=========================================\n";
        cout << "1. Run GEMM (Single Test)\n";
        cout << "2. Run GEMM (All Tests)\n";
        cout << "3. Run CSR (Single Test)\n";
        cout << "4. Run CSR (All Tests)\n";
        cout << "5. Run All Assignments\n";
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
                runAllAssignments();
                break;

            case 0:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}*/


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
        cout << "=========================================\n";
        cout << "1. Assignment 1 - GEMM (Single Test)\n";
        cout << "2. Assignment 1 - GEMM (All Tests)\n";
        cout << "3. Assignment 1 - CSR (Single Test)\n";
        cout << "4. Assignment 1 - CSR (All Tests)\n";
        cout << "5. Assignment 2 (Bellman-Ford + Floyd-Warshall)\n";
        cout << "6. Run All Assignments\n";
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

