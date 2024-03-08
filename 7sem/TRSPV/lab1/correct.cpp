#include "mpi.h"
#include <cstring>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

MPI_Status status;

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {

        // Read matrix from file
        std::ifstream file("input.txt");
        int n, m, k;
        file >> n >> m >> k;

        int matrix1[n][m];
        int matrix2[m][k];
        int result[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                file >> matrix1[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
            {
                file >> matrix2[i][j];
            }
        }

        file.close();

        // Sending rows and matrixes to other processes

        for (int r = 1; r < size; r++)
        {
            MPI_Send(&matrix1[r - 1], 4, MPI_INT, r, 13, MPI_COMM_WORLD);
            MPI_Send(&matrix2, 12, MPI_INT, r, 13, MPI_COMM_WORLD);
        }

        // Receive result

        bool finished[3] = {false, false, false};
        int in_work = n;
        int count = 1;
        while (count <= in_work)
        {
            for (int i = 0; i < n; i++)
            {
                if (!finished[i])
                {
                    int flag = false;
                    MPI_Iprobe((i + 1), 13, MPI_COMM_WORLD, &flag, &status);
                    if (flag)
                    {
                        MPI_Recv(result[i], m, MPI_INT, i + 1, 13, MPI_COMM_WORLD, &status);
                        count++;
                        finished[i] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << result[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    // Other processes

    else
    {
        int row[4];
        int mult[4][3];
        MPI_Recv(&row, 4, MPI_INT, MPI_ANY_SOURCE, 13, MPI_COMM_WORLD, &status);
        MPI_Recv(&mult, 12, MPI_INT, MPI_ANY_SOURCE, 13, MPI_COMM_WORLD, &status);

        printf("Process: %d received row: ", rank);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", row[i]);
        }
        printf("\n");

        int result[3];

        for (int i = 0; i < 3; i++)
        {
            result[i] = 0;
            for (int j = 0; j < 4; j++)
            {
                result[i] += row[j] * mult[j][i];
            }   
        }
        MPI_Send(result, 3, MPI_INT, 0, 13, MPI_COMM_WORLD);

        printf("Process: %d result of multiplication: ", rank);

        for (int i = 0; i < 3; i++)
            printf("%d ", result[i]);
        printf("\n");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}