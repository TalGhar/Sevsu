#include <iostream>
#include "mpi.h"
#include <sstream>

using namespace std;

#define CLIENT_CONNECTED 0
#define CLIENT_DISCONNECTED 1
#define CLIENT_REQUEST 2
#define CLIENT_CHANGE 3

#define SERVER_RESOURCE_FREE 10
#define SERVER_RESOURCE_BUSY 11
#define SERVER_RESOURCE_SET 12
#define SERVER_RESOURCE_MISSING 13
#define SERVER_NO_ACTION 14

#define RESOURCE_AMOUNT 3

double get_resource(int i_resource);
bool set_resource(int n, double value);

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {

        // Server
        MPI_Status status;

        double resources[] = {999.99, 25, 13}, resource;

        cout << "SERVER BEFORE CLIENTS INTERRUPTION:\n";
        for (int i_resource = 0; i_resource < RESOURCE_AMOUNT; i_resource++)
        {
            cout << "Resource " << i_resource << ' ' << resources[i_resource] << '\n';
        }
        cout << '\n';

        int busy[] = {0, 0, 0};

        bool first_client_connected = false;

        int queue = 0, out_tag, i_resource;

        double *inbuf = new double[2], *outbuf = new double[1];

        while (!first_client_connected || queue)
        {
            outbuf[0] = 0;
            MPI_Recv(inbuf, 2, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG,
                     MPI_COMM_WORLD, &status);
            switch (status.MPI_TAG)
            {
            case CLIENT_CONNECTED:
            {
                first_client_connected = true;
                queue++;
                break;
            }

            case CLIENT_DISCONNECTED:
            {
                queue--;
                break;
            }

            case CLIENT_REQUEST:
            {
                i_resource = (int)inbuf[0];
                if (i_resource < RESOURCE_AMOUNT)
                {
                    if (busy[i_resource] != 0)
                    {
                        out_tag = SERVER_RESOURCE_BUSY;
                    }
                    else
                    {
                        outbuf[0] = resources[i_resource];
                        busy[i_resource] = status.MPI_SOURCE;
                        out_tag = SERVER_RESOURCE_FREE;
                    }
                }
                else
                {
                    out_tag = SERVER_RESOURCE_MISSING;
                }
                MPI_Send(outbuf, 1, MPI_DOUBLE, status.MPI_SOURCE, out_tag,
                         MPI_COMM_WORLD);
                break;
            }

            case CLIENT_CHANGE:
            {
                i_resource = (int)inbuf[0];
                resource = inbuf[1];
                if (i_resource < RESOURCE_AMOUNT)
                {
                    if (busy[i_resource] != status.MPI_SOURCE)
                    {
                        out_tag = SERVER_RESOURCE_BUSY;
                    }
                    else
                    {
                        resources[i_resource] = resource;
                        busy[i_resource] = 0;
                        out_tag = SERVER_RESOURCE_SET;
                    }
                }
                else
                {
                    out_tag = SERVER_RESOURCE_MISSING;
                }
                MPI_Send(outbuf, 1, MPI_DOUBLE, status.MPI_SOURCE, out_tag, MPI_COMM_WORLD);
                break;
            }

            default:
            {
                MPI_Send(outbuf, 1, MPI_DOUBLE, status.MPI_SOURCE, SERVER_NO_ACTION, MPI_COMM_WORLD);
            }
            }
        }

        delete[] inbuf;
        delete[] outbuf;

        cout << "SERVER AFTER CLIENTS INTERRUPTION:\n";
        for (int i_resource = 0; i_resource < RESOURCE_AMOUNT; i_resource++)
        {
            cout << "Resource " << i_resource << ' ' << resources[i_resource] << '\n';
        }
    }
    else
    {

        // Clients

        double *outbuf = new double[1];
        outbuf[0] = 0;
        MPI_Send(outbuf, 1, MPI_DOUBLE, 0, CLIENT_CONNECTED, MPI_COMM_WORLD);
        
        stringstream output;
        output << "Client №" << rank << '\n';
        double resource, _resource;

        for (int i_resource = 0; i_resource < RESOURCE_AMOUNT; i_resource++)
        {
            resource = get_resource(i_resource);
            _resource = resource + (rank * 10);
            set_resource(i_resource, _resource);
            output << "Resource " << i_resource << " old value: " << resource << " new value: " << _resource << '\n';
        }

        output << '\n';
        cout << output.str();
        
        MPI_Send(outbuf, 1, MPI_DOUBLE, 0, CLIENT_DISCONNECTED, MPI_COMM_WORLD);

        delete[] outbuf;
    }

    MPI_Finalize();
    return 0;
}

double get_resource(int i_resource)
{
    MPI_Status status;

    double *inbuf = new double[1], *outbuf = new double[1];
    outbuf[0] = i_resource;
    bool received = false;

    while (!received)
    {
        MPI_Send(outbuf, 1, MPI_DOUBLE, 0, CLIENT_REQUEST, MPI_COMM_WORLD);
        MPI_Recv(inbuf, 1, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        if (status.MPI_TAG == SERVER_RESOURCE_FREE)
        {
            received = true;
        }
    }

    double returned = inbuf[0];

    delete[] inbuf;
    delete[] outbuf;

    return returned;
}

bool set_resource(int n, double value)
{
    MPI_Status status;

    double *outbuf = new double[2], *inbuf = new double[1];

    outbuf[0] = n;
    outbuf[1] = value;

    MPI_Send(outbuf, 2, MPI_DOUBLE, 0, CLIENT_CHANGE, MPI_COMM_WORLD);
    MPI_Recv(inbuf, 1, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

    delete[] inbuf;
    delete[] outbuf;

    return status.MPI_TAG == SERVER_RESOURCE_SET;
}
