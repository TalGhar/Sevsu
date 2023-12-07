#include <iostream>
#include "mpi.h"

using namespace std;

#define ROOT 0
#define matr_size 4

void print_iteration(int rank, int cur_column, int block_a[matr_size], int block_b[matr_size]);

MPI_Comm comm_cart;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    int dims[1] = {0};
    int periods[1] = {1};

    int A[matr_size][matr_size];
    int B[matr_size][matr_size];
    int C[matr_size][matr_size] = {0};

    int values_A[matr_size][matr_size] = {{1, 2, 3, 4},
                                          {5, 6, 7, 8},
                                          {9, 10, 11, 12},
                                          {13, 14, 15, 16}};

    int values_B[matr_size][matr_size] = {{1, 2, 3, 4},
                                          {5, 6, 7, 8},
                                          {9, 10, 11, 12},
                                          {13, 14, 15, 16}};

    MPI_Dims_create(size, 1, dims);
    MPI_Cart_create(MPI_COMM_WORLD, 1, dims, periods, 0, &comm_cart);

    int cur_column = rank;

    int prev, next;
    MPI_Cart_shift(comm_cart, 0, 1, &prev, &next);

    if (rank == ROOT)
    {
        for (int i = 0; i < matr_size; i++)
        {
            for (int j = 0; j < matr_size; j++)
            {
                A[i][j] = values_A[i][j];
                B[i][j] = values_B[i][j];
            }
        }
    }

    int block_a[matr_size], block_b[matr_size], block_c[matr_size];

    MPI_Scatter(A, matr_size, MPI_INT, block_a, matr_size, MPI_INT, ROOT, MPI_COMM_WORLD);
    MPI_Bcast(B, matr_size * matr_size, MPI_INT, ROOT, MPI_COMM_WORLD);

    for (int i = 0; i < matr_size; i++)
    {
        int tmp[matr_size] = {0};
        int cur_element = 0;
        for (int j = 0; j < matr_size; j++)
        {
            tmp[j] = B[j][cur_column];
            cur_element += block_a[j] * tmp[j];
        }

        print_iteration(rank, cur_column, block_a, tmp);

        if (rank == ROOT)
        {
            C[rank][cur_column] = cur_element;
            MPI_Send(C, matr_size * matr_size, MPI_INT, (rank + 1), 0, MPI_COMM_WORLD);
            MPI_Recv(C, matr_size * matr_size, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        else if (rank == size - 1)
        {
            MPI_Recv(C, matr_size * matr_size, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            C[rank][cur_column] = cur_element;
            MPI_Send(C, matr_size * matr_size, MPI_INT, ROOT, 0, MPI_COMM_WORLD);
        }

        else
        {
            MPI_Recv(C, matr_size * matr_size, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            C[rank][cur_column] = cur_element;
            MPI_Send(C, matr_size * matr_size, MPI_INT, (rank + 1), 0, MPI_COMM_WORLD);
        }

        MPI_Send(&cur_column, 1, MPI_INT, prev, 12, comm_cart);
        MPI_Recv(&cur_column, 1, MPI_INT, next, 12, comm_cart, &status);
    }

    if (rank == ROOT)
    {
        for (int i = 0; i < matr_size; i++)
        {
            for (int j = 0; j < matr_size; j++)
            {
                cout << C[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    MPI_Comm_free(&comm_cart);
    MPI_Finalize();
}

void print_iteration(int rank, int cur_column, int block_a[matr_size], int block_b[matr_size])
{

    string str_a = "";
    string str_b = "";

    for (int i = 0; i < matr_size; i++)
    {
        str_a += to_string(block_a[i]);
        str_a += ' ';
        str_b += to_string(block_b[i]);
        str_b += ' ';
    }

    cout << "Process: " << rank << " Row A * Col B " << str_a << "* " << str_b << rank << ':' << cur_column << '\n';
}