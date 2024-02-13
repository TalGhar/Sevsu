#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <deque>
#include <unistd.h>
#include <queue>

#include "mpi.h"

#define SERVER 0
#define CLIENT1 1
#define CLIENT2 2

#define MESSAGE_SIZE 3
#define RESOURCES_SIZE 3

#define MESSAGE_ALLOCATE_RESOURCE 101
#define MESSAGE_DEALLOCATE_RESOURCE 102
#define MESSAGE_DONE 100

using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    switch (rank)
    {
        // SERVER
    case 0:
    {
        double resources[RESOURCES_SIZE] = {111.11, 11, 1111};

        vector<deque<vector<int>>> messages_queue(RESOURCES_SIZE);
        bool allocated_resources[RESOURCES_SIZE] = {false, false, false};
        vector<int> message(MESSAGE_SIZE);
        int queued_messages = 0;
        int temp;

        int clients_that_done_working = 0;

        while (true)
        {
            MPI_Recv(message.data(), MESSAGE_SIZE, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for (int i = 0; i < messages_queue.size(); i++)
            {
                if (messages_queue[i].empty() == false)
                {
                    cout << "Messages queue:\n";
                    for (int j = 0; j < messages_queue[i].size(); j++)
                    {
                        cout << "{" << messages_queue[i][j][0] << ',' << messages_queue[i][j][1] << ',' << messages_queue[i][j][2] << "}\n";
                    }
                }
            }

            sleep(1);
            if (message[1] == MESSAGE_ALLOCATE_RESOURCE)
            {
                if (allocated_resources[message[0]] == false)
                {
                    allocated_resources[message[0]] = true;
                    MPI_Send(&resources[message[0]], 1, MPI_DOUBLE, message[2], 0, MPI_COMM_WORLD);
                    cout << "Resource #" << message[0] << " is now allocated by Client#" << message[2] << '\n';
                }
                else
                {
                    messages_queue[0].push_back(message);
                }
            }

            if (message[1] == MESSAGE_DEALLOCATE_RESOURCE)
            {
                if (allocated_resources[message[0]] == true)
                {
                    if (messages_queue[0].empty() == false)
                    {
                        allocated_resources[message[0]] = false;
                        vector<int> nextMessage = messages_queue[0].front();
                        messages_queue[0].clear();
                        MPI_Send(nextMessage.data(), MESSAGE_SIZE, MPI_INT, SERVER, 0, MPI_COMM_WORLD);
                    }
                    allocated_resources[message[0]] = false;
                }
            }

            if (message[1] == MESSAGE_DONE)
            {
                clients_that_done_working++;
                if (clients_that_done_working == 2)
                    break;
            }
        }
    }
    break;

        // CLIENTS
    case 1:
    case 2:
    {
        srand(time(0) * rank);
        vector<int> message(MESSAGE_SIZE);

        int id_resource = rand() % 3;
        sleep(2);
        // CLIENT ALLOCATES RESOURCE AND SEND THE MESSAGE TO SERVER
        message = {id_resource, MESSAGE_ALLOCATE_RESOURCE, rank};
        MPI_Send(message.data(), MESSAGE_SIZE, MPI_INT, SERVER, 0, MPI_COMM_WORLD);
        cout << "Client #" << rank << " sent the message: {" << message[0] << ',' << message[1] << ',' << message[2] << "}\n";

        // CLIENT GETS THE RESPONSE FROM SERVER AND USES RESOURCES
        double response;
        MPI_Recv(&response, 1, MPI_DOUBLE, SERVER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "CLIENT #" << rank << " GETS THE RESPONSE =>" << response << '\n';

        // CLIENT ENDS WORKING WITH RESOURCES AND SENDS THE MESSAGE TO DEALLOCATE RESOURCES
        message[1] = MESSAGE_DEALLOCATE_RESOURCE;
        MPI_Send(message.data(), MESSAGE_SIZE, MPI_INT, SERVER, 0, MPI_COMM_WORLD);
        cout << "Client #" << rank << " sent the message: {" << message[0] << ',' << message[1] << ',' << message[2] << "}\n";

        // CLIENT DONE USING RESOURCES AND DEALLOCATES IT
        message[1] = MESSAGE_DONE;
        MPI_Send(message.data(), MESSAGE_SIZE, MPI_INT, SERVER, 0, MPI_COMM_WORLD);
        cout << "Client #" << rank << " finished working with resources\n";
    }

    break;

    default:
        break;
    }
    MPI_Finalize();
    return 0;
}