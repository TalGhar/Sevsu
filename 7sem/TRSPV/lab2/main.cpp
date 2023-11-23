// #include "mpi.h"
// #include <iostream>
// #include <cstdlib>

// using namespace std;

// #define ROWS_A 8
// #define COLS_A 5
// #define ROWS_B 5
// #define COLS_B 3
// #define BLOCK_SIZE 2

// int main(int argc, char **argv) {
//     int rank, size;
//     MPI_Init(&argc, &argv);
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     MPI_Comm_size(MPI_COMM_WORLD, &size);

//     if (size != 4) {
//         if (rank == 0) {
//             cout << "This program must be run with 4 processes" << endl;
//         }
//         MPI_Finalize();
//         return 1;
//     }

//     int a[ROWS_A][COLS_A], b[ROWS_B][COLS_B], c[ROWS_A][COLS_B];
//     int a_block[BLOCK_SIZE][COLS_A], b_block[ROWS_B][BLOCK_SIZE], c_block[BLOCK_SIZE][BLOCK_SIZE];

//     if (rank == 0) {
//         for (int i = 0; i < ROWS_A; i++) {
//             for (int j = 0; j < COLS_A; j++) {
//                 a[i][j] = rand() % 10;
//             }
//         }
//         for (int i = 0; i < ROWS_B; i++) {
//             for (int j = 0; j < COLS_B; j++) {
//                 b[i][j] = rand() % 10;
//             }
//         }
//     }

//     MPI_Scatter(a, BLOCK_SIZE * COLS_A, MPI_INT, a_block, BLOCK_SIZE * COLS_A, MPI_INT, 0, MPI_COMM_WORLD);

//     MPI_Bcast(b, ROWS_B * COLS_B, MPI_INT, 0, MPI_COMM_WORLD);

//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             c_block[i][j] = 0;
//             for (int k = 0; k < ROWS_B; k++) {
//                 c_block[i][j] += a_block[i][k] * b[k][j];
//             }
//         }
//     }

//     MPI_Gather(c_block, BLOCK_SIZE * BLOCK_SIZE, MPI_INT, c, BLOCK_SIZE * BLOCK_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

//     if (rank == 0) {
//         cout << "Matrix A:" << endl;
//         for (int i = 0; i < ROWS_A; i++) {
//             for (int j = 0; j < COLS_A; j++) {
//                 cout << a[i][j] << " ";
//             }
//             cout << endl;
//         }

//         cout << "Matrix B:" << endl;
//         for (int i = 0; i < ROWS_B; i++) {
//             for (int j = 0; j < COLS_B; j++) {
//                 cout << b[i][j] << " ";
//             }
//             cout << endl;
//         }

//         cout << "Matrix C:" << endl;
//         for (int i = 0; i < ROWS_A; i++) {
//             for (int j = 0; j < COLS_B; j++) {
//                 cout << c[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }

//     MPI_Finalize();
//     return 0;
// }

#include <iostream>
#include "mpi.h"
#include <fstream>
#include <cstring>
#include <iomanip>

#define ROOT 0
#define BLOCK_SIZE 2
#define ROWS_A 8
#define COLS_A 5
#define ROWS_B 5
#define COLS_B 3
#define ROWS_C 8
#define COLS_C 3

using namespace std;

int main(int argc, char **argv)
{
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == ROOT)
    {
        if (size != 5)
        {
            cout << "Program must be run with 4 processes\n";
            MPI_Finalize();
            return 0;
        }

        ifstream inp("input.txt");

        int *A = new int[ROWS_A * COLS_A];
        int *B = new int[ROWS_B * COLS_B];
        for (int i = 0; i < ROWS_A * COLS_A; i++)
        {
            inp >> A[i];
        }
        for (int i = 0; i < ROWS_B * COLS_B; i++)
        {
            inp >> B[i];
        }

        cout << "Matrix A:\n";
        int divider = 0;
        for (int i = 0; i < ROWS_A * COLS_A; i++)
        {
            cout << A[i] << " ";
            divider++;
            if (divider % 5 == 0)
                cout << '\n';
        }

        cout << "\nMatrix B:\n";
        divider = 0;
        for (int i = 0; i < ROWS_B * COLS_B; i++)
        {
            cout << B[i] << " ";
            divider++;
            if (divider % 3 == 0)
                cout << '\n';
        }

        int *blank = new int[BLOCK_SIZE * COLS_A];
        int *buf = new int[(BLOCK_SIZE + ROWS_A) * COLS_A];
        memcpy(buf + (BLOCK_SIZE * COLS_A), A, ROWS_A * COLS_A * sizeof(int));

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Scatter(buf, BLOCK_SIZE * COLS_A, MPI_INT, blank, BLOCK_SIZE * COLS_A, MPI_INT, ROOT, MPI_COMM_WORLD);

        delete[] blank;
        delete[] buf;
        delete[] A;

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Bcast(B, ROWS_B * COLS_B, MPI_INT, ROOT, MPI_COMM_WORLD);
        delete[] B;

        int *c = new int[ROWS_C * COLS_C];
        blank = new int[BLOCK_SIZE * COLS_C];

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Gather(blank, BLOCK_SIZE * COLS_C, MPI_INT, c, BLOCK_SIZE * COLS_C, MPI_INT, ROOT, MPI_COMM_WORLD);

        divider = 0;
        cout << "\nResult of matrix multiplication: \n";
        for (int i = 0; i < ROWS_C; i++)
        {
            for (int j = 0; j < COLS_C; j++)
            {
                cout << c[BLOCK_SIZE * COLS_C + i * COLS_C + j] << "\t";
                divider++;
                if (divider % 3 == 0)
                    cout << '\n';
            }
            cout << '\n';
        }

        delete[] c;
    }

    else
    {
        int blank[0];
        int *a_req = new int[BLOCK_SIZE * COLS_A];

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Scatter(blank, 0, MPI_INT, a_req, BLOCK_SIZE * COLS_A, MPI_INT, ROOT, MPI_COMM_WORLD);
        int divider = 0;
        cout << "\nRank " << rank << " received: \n";
        for (int i = 0; i < BLOCK_SIZE * COLS_A; i++)
        {
            cout << a_req[i] << ' ';
            divider++;
            if (divider % 5 == 0)
                cout << '\n';
        }

        int *b_req = new int[ROWS_B * COLS_B];
        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Bcast(b_req, ROWS_B * COLS_B, MPI_INT, 0, MPI_COMM_WORLD);

        int *c = new int[BLOCK_SIZE * COLS_C];
        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            for (int j = 0; j < COLS_B; j++)
            {
                c[i * COLS_B + j] = 0;
                for (int k = 0; k < COLS_A; k++)
                {
                    c[i * COLS_B + j] += a_req[i * COLS_A + k] * b_req[k * COLS_B + j];
                }
            }
        }

        cout << "Rank " << rank << " result of multiplication: \n";
        for (int i = 0; i < BLOCK_SIZE * COLS_C; i++)
        {
            cout << c[i] << ' ';
            divider++;
            if (divider % 3 == 0)
                cout << '\n';
        }

        delete[] a_req;
        delete[] b_req;

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Gather(c, BLOCK_SIZE * COLS_C, MPI_INT, blank, 0, MPI_INT, ROOT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}