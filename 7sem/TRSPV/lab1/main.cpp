#include "mpi.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

void master();
void slave();
void send(int **matrix1, int **matrix2, int n, int cor, int i, int j, int comm);

MPI_Status status;

int main(int argc, char **argv)
{
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    rank ? slave() : master();

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    return 0;
}

void master()
{
    // Check if there is a multiple threads
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size == 1)
    {
        cout << "You can't exec without slaves, you need at least 1 to go" << endl;
        return;
    }

    // Read matrixes

    ifstream file("input.txt");

    int n, m, k;
    file >> n >> m >> k;

    int **matrix1 = new int *[n];
    int **matrix2 = new int *[m];

    for (int i = 0; i < n; i++)
    {
        matrix1[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            file >> matrix1[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        matrix2[i] = new int[k];
        for (int j = 0; j < k; j++)
        {
            file >> matrix2[i][j];
        }
    }

    file.close();

    bool finished[size];
    memset(finished, 0, sizeof(finished));
    finished[0] = true;
    long long result[n][k];
    int length = n * k;
    int j = 0;
    int in_work = 0;
    for (int i = 1; i < size && j < length; i++)
    {
        send(matrix1, matrix2, m, j, j / k, j % k, i);
        finished[i] = true;
        in_work++;
        j++;
    }

    long message[2];
    while (j < length || in_work > 0)
    {
        MPI_Recv(message, 2, MPI_LONG_LONG, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
        result[message[0] / k][message[0] % k] = message[1];
        finished[status.MPI_SOURCE] = false;
        in_work--;

        if (j < length)
        {
            send(matrix1, matrix2, m, j, j / k, j % k, status.MPI_SOURCE);
            finished[status.MPI_SOURCE] = true;
            in_work++;
            j++;
        }
    }

    // Sending tag 2 to stop slaves
    for (int i = 1; i < size; i++)
    {
        int buffer[1];
        MPI_Send(buffer, 0, MPI_LONG_LONG, i, 2, MPI_COMM_WORLD);
    }

    // Result printing
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}

void slave()
{
    int rank, message[100];
    long long result[2];

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    bool working = true;

    while (working)
    {
        MPI_Recv(message, 100, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        if (status.MPI_TAG == 2)
        {
            working = false;
        }
        else
        {
            int n = message[0];
            long long result[2] = {message[1], 0};

            for (int i = 0; i < n; i++)
            {
                result[1] += message[2 + i] * message[2 + n + i];
            }
            printf("| Process: %d Result of multi: %d |\n", rank, result[1]);

            MPI_Send(result, 2, MPI_LONG_LONG, 0, 1, MPI_COMM_WORLD);
        }
    }
}

void send(int **matrix1, int **matrix2, int n, int cor, int i, int j, int comm)
{
    int buffer[100];
    buffer[0] = n;
    buffer[1] = cor;
    for (int l = 0; l < n; l++)
        buffer[2 + l] = matrix1[i][l];
    for (int l = 0; l < n; l++)
        buffer[2 + n + l] = matrix2[l][j];
    MPI_Send(buffer, 2 * n + 2, MPI_INT, comm, 1, MPI_COMM_WORLD);
}
