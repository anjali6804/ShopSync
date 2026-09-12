#include "../include/client.h"

#include <iostream>
#include <string>
#include <thread>

int main()
{
    Client client;

    if (!client.connectToServer("127.0.0.1", 8080))
    {
        return 1;
    }

    std::thread receiver([&client]()
    {
        client.receiveMessage();
    });

    std::string message;

    while (true)
    {
        std::cout << "Enter message (type exit to quit): ";
        std::getline(std::cin, message);

        if (message == "exit")
        {
            client.disconnect();
            break;
        }

        client.sendMessage(message.c_str());
    }

    receiver.join();

    return 0;
}