#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>
#include <algorithm>
#include <mpi.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void shellSort(vector<int> &vectorForSorting, int vectorSize)
{
    for (int gap = vectorSize / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < vectorSize; i += 1)
        {
            int temp = vectorForSorting[i];
            int j;
            for (j = i; j >= gap && vectorForSorting[j - gap] > temp; j -= gap)
            {
                vectorForSorting[j] = vectorForSorting[j - gap];
            }
            vectorForSorting[j] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 16)
    {
        if (rank == 0)
            cout << "Incorrect number of processes" << endl;
        return 1;
    }

    int N = 4;

    // vector<int> vectorForSorting(6400000);
    vector<int> vectorForSorting(16);
    vector<int> vectorForParallelSorting;
    vector<int> vectorForNonParallelSorting;
    int vectorSize;
    int subvectorSize;
    if (rank == 0)
    {
        srand(time(0));
        generate(vectorForSorting.begin(), vectorForSorting.end(), rand);
        vectorForSorting = {11, 50, 53, 95, 36, 44, 67, 86, 1, 16, 35, 81, 5, 15, 23, 44};
        cout << "\nVector for sorting:\n";
        for (int i = 0; i < vectorForSorting.size(); i++)
            cout << vectorForSorting[i] << " ";
        cout << endl;

        vectorSize = vectorForSorting.size();
        vectorForParallelSorting = vectorForSorting;
        vectorForNonParallelSorting = vectorForSorting;
        subvectorSize = int(vectorSize / pow(2, N));
    }
    MPI_Bcast(&vectorSize, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&subvectorSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        auto t_start = chrono::high_resolution_clock::now();

        shellSort(vectorForNonParallelSorting, vectorSize);

        auto t_end = chrono::high_resolution_clock::now();
        double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

        cout << "\nNon-parallel Shell-sort final vector:\n";
        for (int i = 0; i < vectorForNonParallelSorting.size(); i++)
            cout << vectorForNonParallelSorting[i] << " ";
        cout << endl;

        cout << "\nNon-parallel Shell-sort elapsed time = " << elapsed_time_ms << " ms\n";
    }

    vector<int> subvector(subvectorSize);
    MPI_Scatter(vectorForParallelSorting.data(), subvectorSize, MPI_INT, subvector.data(), subvectorSize, MPI_INT, 0, MPI_COMM_WORLD);

    shellSort(subvector, subvector.size());

    int rankSource, rankDest;
    vector<int> sendSubvector(subvector.begin(), subvector.end());
    vector<int> recvSubvector(subvectorSize);
    vector<int> sendAndRecvSubvector(subvectorSize);

    MPI_Comm nthCube;
    int nDim = N;
    int processPerDim[N] = {2, 2, 2, 2};
    int period[N] = {1, 1, 1, 1};
    MPI_Cart_create(MPI_COMM_WORLD, nDim, processPerDim, period, true, &nthCube);
    int rankInDim;
    MPI_Comm_rank(nthCube, &rankInDim);

    auto t_start = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        MPI_Cart_shift(nthCube, i, 1, &rankSource, &rankDest);

        cout << "Iteration " << i << ": Rank source " << rankInDim << ": Rank dest " << rankDest << endl;

        MPI_Sendrecv(
            sendSubvector.data(), subvectorSize, MPI_INT, rankDest, 0,
            recvSubvector.data(), subvectorSize, MPI_INT, rankDest, 0,
            nthCube, MPI_STATUS_IGNORE);

        if (sendSubvector.back() < recvSubvector.front())
        {
            sendAndRecvSubvector = sendSubvector;
            sendAndRecvSubvector.insert(sendAndRecvSubvector.end(), recvSubvector.begin(), recvSubvector.end());
        }
        else if (recvSubvector.back() < sendSubvector.front())
        {
            sendAndRecvSubvector = recvSubvector;
            sendAndRecvSubvector.insert(sendAndRecvSubvector.end(), sendSubvector.begin(), sendSubvector.end());
        }
        else
        {
            int i = 0, j = 0;
            sendAndRecvSubvector.clear();
            while (sendSubvector.size() != i && recvSubvector.size() != j)
            {
                if (sendSubvector[i] < recvSubvector[j])
                {
                    sendAndRecvSubvector.push_back(sendSubvector[i]);
                    i++;
                }
                else if (recvSubvector[j] <= sendSubvector[i])
                {
                    sendAndRecvSubvector.push_back(recvSubvector[j]);
                    j++;
                }
            }
            if (sendSubvector.size() == i)
            {
                for (int k = j; k < recvSubvector.size(); k++)
                    sendAndRecvSubvector.push_back(recvSubvector[k]);
            }
            else
            {
                for (int k = i; k < sendSubvector.size(); k++)
                    sendAndRecvSubvector.push_back(sendSubvector[k]);
            }
        }

        if (rankInDim < rankDest)
        {
            subvector.assign(sendAndRecvSubvector.begin(), sendAndRecvSubvector.begin() + subvectorSize);
        }
        else
        {
            subvector.assign(sendAndRecvSubvector.begin() + subvectorSize, sendAndRecvSubvector.end());
        }

        sendSubvector = subvector;
    }

    MPI_Gather(subvector.data(), subvectorSize, MPI_INT, vectorForParallelSorting.data(), subvectorSize, MPI_INT, 0, MPI_COMM_WORLD);

    int finish = 0;
    while (!finish)
    {
        sendSubvector = subvector;
        if (rank % 2 == 0)
        {
            rankDest = rank + 1;
            rankSource = rank + 1;
        }
        else
        {
            rankDest = rank - 1;
            rankSource = rank - 1;
        }

        MPI_Sendrecv(
            sendSubvector.data(), subvectorSize, MPI_INT, rankDest, 0,
            recvSubvector.data(), subvectorSize, MPI_INT, rankSource, 0,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        if (sendSubvector.back() <= recvSubvector.front())
        {
            if (rank < rankDest)
            {
                subvector = sendSubvector;
            }
            else
            {
                subvector = recvSubvector;
            }
        }
        else if (recvSubvector.back() <= sendSubvector.front())
        {
            if (rank < rankDest)
            {
                subvector = recvSubvector;
            }
            else
            {
                subvector = sendSubvector;
            }
        }
        else
        {
            int i = 0, j = 0;
            sendAndRecvSubvector.clear();
            while (sendSubvector.size() != i && recvSubvector.size() != j)
            {
                if (sendSubvector[i] < recvSubvector[j])
                {
                    sendAndRecvSubvector.push_back(sendSubvector[i]);
                    i++;
                }
                else if (recvSubvector[j] <= sendSubvector[i])
                {
                    sendAndRecvSubvector.push_back(recvSubvector[j]);
                    j++;
                }
            }
            if (sendSubvector.size() == i)
            {
                for (int k = j; k < recvSubvector.size(); k++)
                    sendAndRecvSubvector.push_back(recvSubvector[k]);
            }
            else
            {
                for (int k = i; k < sendSubvector.size(); k++)
                    sendAndRecvSubvector.push_back(sendSubvector[k]);
            }
            if (rank < rankDest)
            {
                subvector.assign(sendAndRecvSubvector.begin(), sendAndRecvSubvector.begin() + subvectorSize);
            }
            else
            {
                subvector.assign(sendAndRecvSubvector.begin() + subvectorSize, sendAndRecvSubvector.end());
            }
        }

        sendSubvector = subvector;
        if (!(rank == 0 || (rank % 2 == 1 && rank == (size - 1))))
        {
            if (rank % 2 == 1)
            {
                rankDest = rank + 1;
                rankSource = rank + 1;
            }
            else
            {
                rankDest = rank - 1;
                rankSource = rank - 1;
            }

            MPI_Sendrecv(
                sendSubvector.data(), subvectorSize, MPI_INT, rankDest, 0,
                recvSubvector.data(), subvectorSize, MPI_INT, rankSource, 0,
                MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            if (sendSubvector.back() <= recvSubvector.front())
            {
                if (rank < rankDest)
                {
                    subvector = sendSubvector;
                }
                else
                {
                    subvector = recvSubvector;
                }
            }
            else if (recvSubvector.back() <= sendSubvector.front())
            {
                if (rank < rankDest)
                {
                    subvector = recvSubvector;
                }
                else
                {
                    subvector = sendSubvector;
                }
            }
            else
            {
                int i = 0, j = 0;
                sendAndRecvSubvector.clear();
                while (sendSubvector.size() != i && recvSubvector.size() != j)
                {
                    if (sendSubvector[i] < recvSubvector[j])
                    {
                        sendAndRecvSubvector.push_back(sendSubvector[i]);
                        i++;
                    }
                    else if (recvSubvector[j] <= sendSubvector[i])
                    {
                        sendAndRecvSubvector.push_back(recvSubvector[j]);
                        j++;
                    }
                }
                if (sendSubvector.size() == i)
                {
                    for (int k = j; k < recvSubvector.size(); k++)
                        sendAndRecvSubvector.push_back(recvSubvector[k]);
                }
                else
                {
                    for (int k = i; k < sendSubvector.size(); k++)
                        sendAndRecvSubvector.push_back(sendSubvector[k]);
                }
                if (rank < rankDest)
                {
                    subvector.assign(sendAndRecvSubvector.begin(), sendAndRecvSubvector.begin() + subvectorSize);
                }
                else
                {
                    subvector.assign(sendAndRecvSubvector.begin() + subvectorSize, sendAndRecvSubvector.end());
                }
            }
        }

        MPI_Gather(subvector.data(), subvectorSize, MPI_INT, vectorForSorting.data(), subvectorSize, MPI_INT, 0, MPI_COMM_WORLD);

        if (rank == 0)
        {
            if (vectorForSorting == vectorForParallelSorting)
            {
                finish = 1;
            }
            else
            {
                vectorForParallelSorting = vectorForSorting;
            }
        }
        MPI_Bcast(&finish, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    auto t_end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();

    if (rank == 0)
    {
        cout << "\nParallel Shell-sort final vector:\n";
        for (int i = 0; i < vectorForParallelSorting.size(); i++)
            cout << vectorForParallelSorting[i] << " ";
        cout << endl;

        cout << "\nParallel Shell-sort elapsed time = " << elapsed_time_ms << " ms\n";
    }

    MPI_Finalize();
}