#include <iostream>
#include "mpi.h"
#include <unistd.h>

using namespace std;

#define ROOT 0
#define matr_size 4

void print_iteration(int rank, int cur_column, int block_a[matr_size], int block_b[matr_size], int i);

MPI_Comm comm_cart;

int calculate_cur_column(int rank, int i);

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

    int source, destination;

    MPI_Cart_shift(comm_cart, 0, 1, &source, &destination);
    cout << "···\n";
    // cout << "rank: " << rank << "source:" << source << "destination: " << destination << '\n';
    // sleep(1);
    // MPI_Barrier(MPI_COMM_WORLD);
    // MPI_Barrier(comm_cart);

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
        int cur_element = 0, cur_column = 0;

        cur_column = calculate_cur_column(rank, i);

        for (int j = 0; j < matr_size; j++)
        {
            tmp[j] = B[j][cur_column];
            cur_element += block_a[j] * tmp[j];
        }

        print_iteration(rank, cur_column, block_a, tmp, i);
        sleep(1);
        MPI_Barrier(comm_cart);
        MPI_Barrier(MPI_COMM_WORLD);

        if (rank == ROOT)
        {
            C[rank][cur_column] = cur_element;
            MPI_Send(C, matr_size * matr_size, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
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
            MPI_Send(C, matr_size * matr_size, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }

        // cout << "i: " << i << "source: " << source << "destination: " << destination << "cur column: " << cur_column << '\n';
        // sleep(1);
        // MPI_Barrier(MPI_COMM_WORLD);
        // MPI_Barrier(comm_cart);
        MPI_Send(&cur_column, 1, MPI_INT, destination, 12, comm_cart);
        MPI_Recv(&cur_column, 1, MPI_INT, source, 12, comm_cart, &status);
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

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Barrier(comm_cart);

    MPI_Comm_free(&comm_cart);
    MPI_Finalize();
}

void print_iteration(int rank, int cur_column, int block_a[matr_size], int block_b[matr_size], int i)
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

    cout << "Iteration: " << i << " Rank: " << rank << " Column:" << cur_column << " Row A * Col B -> (" << str_a << ") * (" << str_b << ")(RANK : COLUMN) -> " << rank << ":" << cur_column << '\n';
    MPI_Barrier(comm_cart);
    MPI_Barrier(MPI_COMM_WORLD);
}

int calculate_cur_column(int rank, int i)
{
    int cur_column = (4 - i + rank) % 4;
    return cur_column;
}