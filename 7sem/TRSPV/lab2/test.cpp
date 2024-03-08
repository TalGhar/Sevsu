#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <unistd.h>

using namespace std;

double **allocate2DArray(int size);
void freeArray(double **matrix, int size);
void displayMatrix(int size, double **matrix);
double getMin(int size, double *vector);
double getMax(int size, double *vector);

int main(int argc, char *argv[])
{
    int rank, size;

    const int ROOT = 0;
    const int elementsForBlock = 25;
    const int matrSize = 10;
    const int blockSize = matrSize * matrSize / elementsForBlock;

    double globalBlocks[blockSize + 1][elementsForBlock];
    double globalMin;
    double globalMax;

    double localVector[elementsForBlock];

    int errCode;

    if ((errCode = MPI_Init(&argc, &argv)) != 0)
    {
        return errCode;
    }

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int min_ranks[blockSize];
    int max_ranks[blockSize];
    int min_c = 0, max_c = 0;

    MPI_Comm min_comm, max_comm;
    MPI_Group group_world, min_group, max_group;

    MPI_Comm_group(MPI_COMM_WORLD, &group_world);

    // Распределение рангов матриц по критерию чётности номера ранга (корневой процесс идёт в оба массива)

    for (int i = 0; i < size; i++)
    {
        if (i == ROOT)
        {
            min_ranks[min_c] = i;
            max_ranks[max_c] = i;
            min_c++;
            max_c++;
        }

        if ((i % 2 != 0) && (i != ROOT))
        {
            min_ranks[min_c] = i;
            min_c++;
        }

        if ((i % 2 == 0) && (i != ROOT))
        {
            max_ranks[max_c] = i;
            max_c++;
        }
    }

    MPI_Group_incl(group_world, min_c, min_ranks, &min_group);
    MPI_Group_incl(group_world, max_c, max_ranks, &max_group);

    MPI_Comm_create(MPI_COMM_WORLD, min_group, &min_comm);
    MPI_Comm_create(MPI_COMM_WORLD, max_group, &max_comm);

    int subrank;

    if (rank == ROOT)
    {
        double **A = allocate2DArray(matrSize);

        for (int i = 0; i < matrSize; i++)
        {
            for (int j = 0; j < matrSize; j++)
            {
                double x = i / 10.0;
                double y = j / 10.0;

                A[i][j] = sin(x) + exp(y);
            }
        }

        cout << "Initial matrix: " << endl
             << endl;
        displayMatrix(matrSize, A);

        // Разделение матрицы на 4 блока по n (25) элементов

        for (int i = 0; i < blockSize; i++)
        {
            if ((i % 2 == 0) && (i == 0))
            {

                for (int j = 0; j < matrSize / 2; j++)
                {
                    for (int k = 0; k < matrSize / 2; k++)
                    {
                        globalBlocks[i + 1][j * (matrSize / 2) + k] = A[j][k];
                    }
                }
            }
            if ((i % 2 == 0) && (i == 2))
            {

                for (int j = matrSize / 2; j < matrSize; j++)
                {
                    for (int k = 0; k < matrSize / 2; k++)
                    {
                        globalBlocks[i + 1][(j - (matrSize / 2)) * (matrSize / 2) + k] = A[j][k];
                    }
                }
            }

            if ((i % 2 != 0) && (i == 1))
            {

                for (int j = 0; j < matrSize / 2; j++)
                {
                    for (int k = matrSize / 2; k < matrSize; k++)
                    {
                        globalBlocks[i + 1][j * (matrSize / 2) + (k - (matrSize / 2))] = A[j][k];
                    }
                }
            }

            if ((i % 2 != 0) && (i == 3))
            {

                for (int j = matrSize / 2; j < matrSize; j++)
                {
                    for (int k = matrSize / 2; k < matrSize; k++)
                    {
                        globalBlocks[i + 1][(j - (matrSize / 2)) * (matrSize / 2) + (k - (matrSize / 2))] = A[j][k];
                    }
                }
            }
        }

        // Чтобы избежать ошибок памяти или неправильного расчёта min / max,
        // присвоим 0 строке globalBlocks его 1 строку

        for (int i = 0; i < elementsForBlock; ++i)
        {
            globalBlocks[0][i] = globalBlocks[1][i];
        }

        for (int l = 1; l < blockSize + 1; l++)
        {
            cout << "Block #" << l << ": ";
            for (int m = 0; m < elementsForBlock; m++)
            {
                if (m % 5 == 0)
                {
                    cout << endl;
                }

                cout << globalBlocks[l][m] << "   ";
            }
            cout << endl
                 << endl;
        }
        cout << endl;

        // база для подсчёта min / max

        globalMax = globalBlocks[0][0];
        globalMin = globalBlocks[0][0];

        freeArray(A, matrSize);
    }

    // Синхронизация всех процессов

    // MPI_Barrier(MPI_COMM_WORLD);

    if (min_comm != MPI_COMM_NULL)
    {

        MPI_Barrier(min_comm);

        cout << "Процесс группы MIN" << endl;

        MPI_Comm_rank(min_comm, &subrank);

        // Раскидать значения globalBlocks[i] по процессам из группы min_group

        MPI_Scatter(globalBlocks, elementsForBlock, MPI_DOUBLE, localVector, elementsForBlock, MPI_DOUBLE, ROOT, min_comm);

        double localMin = getMin(elementsForBlock, localVector);

        cout << "Rank #" << rank << " local min: " << localMin << endl;

        // Отдать локальный минимум корню для расчёта глобального минимума

        MPI_Reduce(&localMin, &globalMin, 1, MPI_DOUBLE, MPI_MIN, ROOT, min_comm);
    }

    if (max_comm != MPI_COMM_NULL)
    {

        MPI_Barrier(max_comm);

        cout << "Процесс группы MAX" << endl;

        MPI_Comm_rank(max_comm, &subrank);

        // Раскидать значения globalBlocks[i] по процессам из группы max_group

        MPI_Scatter(globalBlocks, elementsForBlock, MPI_DOUBLE, localVector, elementsForBlock, MPI_DOUBLE, ROOT, max_comm);

        double localMax = getMax(elementsForBlock, localVector);

        cout << "Rank #" << rank << " local max: " << localMax << endl;

        // Отдать локальный максимум корню для расчёта глобального максимума

        MPI_Reduce(&localMax, &globalMax, 1, MPI_DOUBLE, MPI_MAX, ROOT, max_comm);
    }

    if (rank == ROOT)
    {
        cout << endl
             << "Global min: " << globalMin << endl;
        cout << endl
             << "Global max: " << globalMax << endl;
    }

    MPI_Finalize();

    return 0;
}

double **allocate2DArray(int size)
{
    double **a = new double *[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }

    return a;
}

void freeArray(double **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void displayMatrix(int size, double **matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "       ";
        }
        cout << endl;
    }

    cout << endl;
}

double getMin(int size, double *vector)
{
    double min = vector[0];

    for (int i = 1; i < size; ++i)
    {
        if (vector[i] < min)
        {
            min = vector[i];
        }
    }

    return min;
}

double getMax(int size, double *vector)
{
    double max = vector[0];

    for (int i = 1; i < size; ++i)
    {
        if (vector[i] > max)
        {
            max = vector[i];
        }
    }

    return max;
}