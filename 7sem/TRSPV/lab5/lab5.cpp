#include <iostream>
#include <unistd.h>
#include <string.h>

#include "mpi.h"

#define ZOND 101
#define ECHO 102

#define MESSAGE_SIZE 200

using namespace std;

MPI_Status status;
// void test()
// {
//     cout << "at 2:\n 0 0 0 0 0\n0 0 0 0 0 \n0 0 0 0 0\n 0 0 0 0 0\n 0 0 0 0 0\nat 4:\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0";
//     cout << "at 1:\n0 0 0 0 0\n0 0 1 0 0\n0 0 0 0 0\n0 0 0 0 0\n 0 0 0 0 0\n at 1:\n0 0 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n0 0 0 0 0\n 0 0 0 0 0\n";
//     cout << "at 3:\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 1 0 0\n0 0 0 0 0\n at 3:\n0 0 0 0 0 \n0 0 0 0 0\n0 0 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n";
//     cout << "at 0:\n0 0 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\nat 0:\n0 1 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\nat 0:\n0 1 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n0 0 1 0 1\n0 0 0 0 0\nat 0:\n0 1 0 1 0\n0 0 1 0 1\n0 0 0 0 0\n0 0 1 0 1\n0 0 0 0 0\n";
// }
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm_graph;

    /*
        лист - отправляет нулевую матрицу обратно, накапливая единицы
        на каждом предыдущем этапе она заполняется
        главное - как храню соседа (вектор в котором указаны его соседи)
    */

    // Node degrees
    int index[] = {2, 5, 7, 10, 12};

    // Graph edges
    int edges[] = {
        1, 3,
        0, 2, 4,
        1, 3,
        0, 2, 4,
        1, 3};

    MPI_Graph_create(MPI_COMM_WORLD, size, index, edges, false, &comm_graph);
    // Getting the number of neighbours on each tree node
    int count_neighbours;
    MPI_Graph_neighbors_count(comm_graph, rank, &count_neighbours);

    // Each node creates vector of nighbour nodes id's
    int *neighbours = new int[count_neighbours];
    MPI_Graph_neighbors(comm_graph, rank, count_neighbours, neighbours);
    MPI_Comm_rank(comm_graph, &rank);

    cout << "Neighbours of node : " << rank << '\n';
    for (int i = 0; i < count_neighbours; i++)
    {
        cout << neighbours[i] << ' ';
    }
    cout << '\n';
    /*
        message struct:
        message[0] -- message type (101 - ZOND, 102 - ECHO)
        message[1] -- num of node sender
        message[2] - message[27] -- 5*5 matrix if [i][j]=1 => have edge
        data[] are the same
    */
    int message[MESSAGE_SIZE];
    for (int i = 2; i < 27; i++)
    {
        message[i] = 0;
    }
    int first;

    // All proccesses except of 0 waiting for zond
    if (rank != 0)
    {

        MPI_Recv(message, MESSAGE_SIZE, MPI_INT, MPI_ANY_SOURCE, 99, comm_graph, &status);
        cout << "Node " << rank << "\t received zond from node " << message[1] << '\n';
        // Node which must receive final ECHO
        if (message[0] == ZOND)
        {
            first = message[1];
        }
    }

    message[0] = ZOND;
    message[1] = rank;

    // All nodes send zond's to their neighbours
    for (int i = 0; i < count_neighbours; i++)
    {
        cout << "Node " << rank << "\t send zond to node " << neighbours[i] << '\n';
        MPI_Send(message, MESSAGE_SIZE, MPI_INT, neighbours[i], 99, comm_graph);
    }

    int from;

    // All the nighbours send zond and receive echo, so 2 messages from each neighbour (count_neighbours * 2)
    int all_messages = count_neighbours * 2;
    if (rank != 0)
        all_messages--;

    int *data = new int[MESSAGE_SIZE];
    for (int i = 0; i < MESSAGE_SIZE; i++)
        data[i] = 0;

    //
    for (int i = 0; i < count_neighbours; i++)
    {
        data[rank * 5 + neighbours[i] + 2] = 1;
        data[neighbours[i] * 5 + rank + 2] = 1;
    }

    for (int i = 0; i < all_messages; i++)
    {
        // Receiving messages from neighbour
        MPI_Recv(message, MESSAGE_SIZE, MPI_INT, MPI_ANY_SOURCE, 99, comm_graph, &status);
        cout << "Node " << rank << "\t received message from node " << message[1];

        if (message[0] == ZOND)
        {
            // cout << "\t This is ZOND\n";
            from = message[1];
            message[0] = ECHO;
            message[0] = rank;

            // Empty ECHO
            message[99] = -1;
            cout << "Node " << rank << "\t send empty echo to node " << from << '\n';

            MPI_Send(message, MESSAGE_SIZE, MPI_INT, from, 99, comm_graph);
        }

        if (message[0] == ECHO)
        {
            cout << "\t This is ECHO\n";
            // If not empty ECHO received
            if (message[99] != -1)
            {
                for (int i = 2; i < MESSAGE_SIZE; i++)
                {
                    if (message[i] == 1)
                        data[i] = 1;
                }
            }
        }
    }

    // Sending final echo
    if (rank != 0)
    {
        cout << "Node " << rank << "\t send final echo to node " << first << '\n';
        data[99] = 1;
        data[0] = ECHO;
        data[1] = rank;
        MPI_Send(data, MESSAGE_SIZE, MPI_INT, first, 99, comm_graph);
    }

    int ostov[5][5];

    if (rank == 0)
    {
        // test();
        // Cluster topology
        sleep(2);
        cout << "\nFull cluster topology\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << data[5 * i + j + 2] << " ";
            }
            cout << '\n';
        }
        cout << '\n';

        // Ostov tree
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                ostov[i][j] = 0;
            }
        }

        bool used[5];
        for (int i = 0; i < 5; i++)
        {
            used[i] = false;
        }
        used[0] = true;

        for (int i = 0; i < 4; i++)
        {
            bool flag = false;
            for (int j = 0; j < 5; j++)
            {
                if (used[j] == true)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if ((used[k] == false) && (data[5 * j + k + 2] == 1))
                        {
                            ostov[j][k] = 1;
                            ostov[k][j] = 1;
                            flag = true;
                            used[k] = true;
                            break;
                        }
                    }
                }
                if (flag)
                    break;
            }
        }

        cout << "Ostov tree: \n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << ostov[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    // Sending messages
    char s[20];
    if (rank == 0)
    {
        scanf("%s", &s, sizeof(s));
        data[0] = strlen(s);

        for (int i = 0; i < data[0]; i++)
        {
            data[i + 1] = (int)s[i];
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                data[data[0] + 1 + 5 * i + j] = ostov[i][j];
            }
        }
    }

    if (rank != 0)
    {
        MPI_Recv(data, MESSAGE_SIZE, MPI_INT, MPI_ANY_SOURCE, 99, comm_graph, &status);

        for (int i = 0; i < data[0]; i++)
        {
            s[i] = (char)data[i + 1];
        }

        s[data[0]] = '\0';
        cout << "Node " << rank << " \t received message " << s << '\n';
    }

    // Nullify ostov column to not sending messages again
    for (int i = 0; i < 5; i++)
    {
        data[data[0] + 1 + 5 * i + rank] = 0;
    }

    // Sending messages to neighbours, if not received by itself
    for (int i = 0; i < 5; i++)
    {
        if (data[data[0] + 1 + 5 * rank + i] == 1)
        {
            cout << "Node " << rank << "\t send message to node " << i << '\n';
            MPI_Send(data, MESSAGE_SIZE, MPI_INT, i, 99, comm_graph);
        }
    }

    MPI_Finalize();
}