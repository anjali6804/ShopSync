#include "../include/client.h"

#include <iostream>
#include <cstring>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

Client::Client()
{
    clientSocket = -1;
}

Client::~Client()
{
    if (clientSocket != -1)
    {
        close(clientSocket);
    }
}

bool Client::connectToServer(const char* ip, int port)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1)
    {
        std::cerr << "Failed to create client socket.\n";
        return false;
    }

    sockaddr_in serverAddress{};

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &serverAddress.sin_addr) <= 0)
    {
        std::cerr << "Invalid server IP address.\n";
        close(clientSocket);
        clientSocket = -1;
        return false;
    }

    if (connect(clientSocket,
                (struct sockaddr*)&serverAddress,
                sizeof(serverAddress)) == -1)
    {
        std::cerr << "Connection to server failed.\n";
        close(clientSocket);
        clientSocket = -1;
        return false;
    }

    std::cout << "Connected to ShopSync server!\n";

    return true;
}

void Client::sendMessage(const char* message)
{
    send(clientSocket, message, strlen(message), 0);
}

void Client::receiveMessage()
{
    char buffer[1024] = {0};

    int bytesReceived = recv(
        clientSocket,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytesReceived > 0)
    {
        buffer[bytesReceived] = '\0';
        std::cout << "Server: " << buffer << '\n';
    }
}
void Client::disconnect()
{
    if (clientSocket != -1)
    {
        close(clientSocket);
        clientSocket = -1;
    }
}
