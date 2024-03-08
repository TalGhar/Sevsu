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