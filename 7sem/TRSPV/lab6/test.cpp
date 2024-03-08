#include <iostream>

using namespace std;

const int na = 4, nb = 4, nc = na + nb;

int main(int argc, char **argv)
{
    int A[na] = {1, 2, 3, 4};
    int B[nb] = {5, 6, 7, 8};

    int C[nc];

    if (A[na - 1] <= B[0])
    {
        for (int i = 0; i < na - 1; i++)
        {
            C[i] = A[i];
        }
        for (int i = 0; i < nb - 1; i++)
        {
            C[nb + i] = B[i];
        }
    }
    else if (B[nb - 1] <= A[0])
    {
        for (int i = 0; i < nb - 1; i++)
        {
            C[i] = B[i];
        }
        for (int i = 0; i < na - 1; i++)
        {
            C[nb + i] = A[i];
        }
    }
    else
    {
        int k = 0, j = 0;
        for (int i = 0; i < nc; i++)
        {
            if (k > nb)
            {
                C[i] = B[j];
                j++;
            }
            if (j > na)
            {
                C[i] = A[k];
                k++;
            }
            else if (A[k] < B[j])
            {
                C[i] = A[k];
                k++;
            }
            else if (B[j] < A[k])
            {
                C[i] = B[j];
                j++;
            }
        }
    }
}