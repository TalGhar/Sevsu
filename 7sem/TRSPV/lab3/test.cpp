#include <iostream>
#include "mpi.h"
#include <unistd.h>

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

  

    for (int i = 0; i < matr_size; i++)
    {
        cout << "Iteration: " << i << " Rank: " << rank << '\n';
        sleep(1);
        MPI_Barrier(MPI_COMM_WORLD);      
    }


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