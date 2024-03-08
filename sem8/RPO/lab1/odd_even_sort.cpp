#include <iostream>
#include <chrono>
#include <unistd.h>

#define SIZE 15

using namespace std;

void odd_even_sort(int *vector, int size);
void show_vector(int vector[], int size);

int main()
{
    int vector[SIZE] = {5, 53, 23, 34, 75, 12, 4, 50, 32, 11, 99, 112, 1, 0, 63};

    show_vector(vector, SIZE);
    auto t_start = chrono::high_resolution_clock::now();
    odd_even_sort(vector, SIZE);
    auto t_end = chrono::high_resolution_clock::now();
    show_vector(vector, SIZE);
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << "\nNon-parallel Odd-even sort elapsed time = " << elapsed_time_ms << " ms\n";

    return 0;
}

void odd_even_sort(int *vector, int size)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < SIZE; j += 2)
            {
                if (j < SIZE - 1)
                {
                    if (vector[j] > vector[j + 1])
                    {
                        int temp = vector[j];
                        vector[j] = vector[j + 1];
                        vector[j + 1] = temp;
                    }
                }
            }
        }
        else
        {
            for (int j = 1; j < SIZE; j += 2)
            {
                if (j < SIZE - 1)
                {
                    if (vector[j] > vector[j + 1])
                    {
                        int temp = vector[j];
                        vector[j] = vector[j + 1];
                        vector[j + 1] = temp;
                    }
                }
            }
        }
    }
    return;
}

void show_vector(int vector[], int size)
{
    for (int i = 0; i < SIZE; i++)
        cout << vector[i] << ' ';
    cout << '\n';
    return;
}