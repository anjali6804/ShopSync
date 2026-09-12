#include "../include/client.h"

int main()
{
    Client client;

    if (!client.connectToServer("127.0.0.1", 8080))
    {
        return 1;
    }

    client.sendMessage("Hello Server!");

    client.receiveMessage();

    return 0;
}