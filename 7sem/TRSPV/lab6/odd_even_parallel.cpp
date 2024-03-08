#include <iostream>
#include <chrono>
#include <unistd.h>

#include "mpi.h"

using namespace std;

#define SIZE 15
#define ROOT 0

void show_vector(int vector[], int size);
int *get_half_vector(int vector[], int size, bool mode);
int partition(int vector[], int start, int end);
void quicksort(int vector[], int start, int end);
int *mergesort(int first_vector[], int second_vector[], int f_size, int s_size);

MPI_Status status;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int vector[SIZE];
    int *sorted_vector = new int[SIZE];
    int block_size = SIZE / size;
    int *block_vector = new int[block_size];
    srand(time(0));
    auto t_start = chrono::high_resolution_clock::now();

    if (rank == ROOT)
    {
        for (int i = 0; i < SIZE; i++)
        {
            vector[i] = 0 + rand() % 100;
        }
        cout << "Unsorted vector\n";
        show_vector(vector, SIZE);
    }

    MPI_Scatter(vector, block_size, MPI_INT, block_vector, block_size, MPI_INT, ROOT, MPI_COMM_WORLD);

#pragma region DEBUG
    cout << "Process #" << rank << " unsorted: ";
    show_vector(block_vector, block_size);
    MPI_Barrier(MPI_COMM_WORLD);
#pragma endregion

    quicksort(block_vector, 0, block_size - 1);

#pragma region DEBUG
    cout << "Process #" << rank << " sorted: ";
    show_vector(block_vector, block_size);
#pragma endregion

    MPI_Barrier(MPI_COMM_WORLD);

    for (int i = 0; i < size - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (rank % 2 == 0)
            {
                if (rank != size - 1)
                {
                    int *block_vector_next = new int[block_size];
                    MPI_Send(block_vector, block_size, MPI_INT, rank + 1, 99, MPI_COMM_WORLD);
                    MPI_Recv(block_vector_next, block_size, MPI_INT, rank + 1, 99, MPI_COMM_WORLD, &status);
                    int *merged = mergesort(block_vector, block_vector_next, block_size, block_size);
                    block_vector = get_half_vector(merged, block_size * 2, 0);

#pragma region DEBUG
                    cout << "Process #" << rank << " merged-sorted: ";
                    show_vector(merged, block_size * 2);
                    cout << "Process #" << rank << " half: ";
                    show_vector(block_vector, block_size);
#pragma endregion
                    delete[] block_vector_next;
                    delete[] merged;
                }
            }
            else
            {
                int *block_vector_prev = new int[block_size];
                MPI_Send(block_vector, block_size, MPI_INT, rank - 1, 99, MPI_COMM_WORLD);
                MPI_Recv(block_vector_prev, block_size, MPI_INT, rank - 1, 99, MPI_COMM_WORLD, &status);
                int *merged = mergesort(block_vector, block_vector_prev, block_size, block_size);
                block_vector = get_half_vector(merged, block_size * 2, 1);
#pragma region DEBUG
                cout << "Process #" << rank << " merged-sorted: ";
                show_vector(merged, block_size * 2);
                cout << "Process #" << rank << " half: ";
                show_vector(block_vector, block_size);
#pragma endregion
                delete[] block_vector_prev;
                delete[] merged;
            }
        }
        else
        {
            if (rank % 2 == 0)
            {
                if (rank != 0)
                {
                    int *block_vector_prev = new int[block_size];
                    MPI_Send(block_vector, block_size, MPI_INT, rank - 1, 99, MPI_COMM_WORLD);
                    MPI_Recv(block_vector_prev, block_size, MPI_INT, rank - 1, 99, MPI_COMM_WORLD, &status);
                    int *merged = mergesort(block_vector, block_vector_prev, block_size, block_size);
                    block_vector = get_half_vector(merged, block_size * 2, 1);
#pragma region DEBUG
                    cout << "Process #" << rank << " merged-sorted: ";
                    show_vector(merged, block_size * 2);
                    cout << "Process #" << rank << " half: ";
                    show_vector(block_vector, block_size);
#pragma endregion
                    delete[] block_vector_prev;
                    delete[] merged;
                }
            }
            else
            {
                int *block_vector_next = new int[block_size];
                MPI_Send(block_vector, block_size, MPI_INT, rank + 1, 99, MPI_COMM_WORLD);
                MPI_Recv(block_vector_next, block_size, MPI_INT, rank + 1, 99, MPI_COMM_WORLD, &status);
                int *merged = mergesort(block_vector, block_vector_next, block_size, block_size);
                block_vector = get_half_vector(merged, block_size * 2, 0);

#pragma region DEBUG
                cout << "Process #" << rank << " merged-sorted: ";
                show_vector(merged, block_size * 2);
                cout << "Process #" << rank << " half: ";
                show_vector(block_vector, block_size);
#pragma endregion
                delete[] block_vector_next;
                delete[] merged;
            }
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Gather(block_vector, block_size, MPI_INT, sorted_vector, block_size, MPI_INT, ROOT, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    if (rank == ROOT)
    {
        cout << "\nSorted vector: ";
        show_vector(sorted_vector, SIZE);
    }


    auto t_end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

    if (rank == ROOT)
    {
        cout << "\nParallel Odd-even sort elapsed time = " << elapsed_time_ms << " ms\n";
    }

    MPI_Finalize();
}

void show_vector(int vector[], int size)
{
    for (int i = 0; i < size; i++)
        cout << vector[i] << ' ';
    cout << '\n';
    return;
}

void quicksort(int vector[], int start, int end)
{
    int *stack = (int *)malloc((end - start + 1) * sizeof(int));
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0)
    {
        end = stack[top--];
        start = stack[top--];
        int pivot_index = partition(vector, start, end);

        if (pivot_index - 1 > start)
        {
            stack[++top] = start;
            stack[++top] = pivot_index - 1;
        }
        if (pivot_index + 1 < end)
        {
            stack[++top] = pivot_index + 1;
            stack[++top] = end;
        }
    }
}

int partition(int vector[], int start, int end)
{
    int pivot = vector[end];
    int pIndex = start;

    for (int i = start; i < end; ++i)
    {
        if (vector[i] < pivot)
        {
            swap(vector[i], vector[pIndex]);
            pIndex++;
        }
    }
    swap(vector[pIndex], vector[end]);

    return pIndex;
}

int *get_half_vector(int vector[], int size, bool mode)
{
    int *result = new int[size / 2];
    if (mode)
    {
        copy(vector + size / 2, vector + size, result);
    }
    else
    {
        copy(vector, vector + size / 2, result);
    }
    return result;
}

int *mergesort(int first_vector[], int second_vector[], int f_size, int s_size)
{
    int i = 0, j = 0, index = 0;
    int *result = new int[f_size + s_size];

    while (i < f_size && j < s_size)
    {
        if (first_vector[i] < second_vector[j])
        {
            result[index] = first_vector[i];
            i++;
        }
        else
        {
            result[index] = second_vector[j];
            j++;
        }
        index++;
    }

    while (i < f_size)
    {
        result[index] = first_vector[i];
        index++;
        i++;
    }

    while (j < s_size)
    {
        result[index] = second_vector[j];
        index++;
        j++;
    }
    return result;
}