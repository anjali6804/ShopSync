#include "../include/server.h"

#include <iostream>
#include <cstring>
#include <thread>

#include <vector>
#include <mutex>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Server::Server()
{
    serverSocket = -1;
}

Server::~Server()
{
    if (serverSocket != -1)
    {
        close(serverSocket);
    }
}

bool Server::start(int port)
{
    // 1. Create TCP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        std::cerr << "Failed to create socket.\n";
        return false;
    }

    // 2. Create server address
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    // 3. Bind socket to IP + port
    if (bind(serverSocket,
             (struct sockaddr*)&serverAddress,
             sizeof(serverAddress)) == -1)
    {
        std::cerr << "Bind failed.\n";
        close(serverSocket);
        serverSocket = -1;
        return false;
    }

    // 4. Start listening
    if (listen(serverSocket, 5) == -1)
    {
        std::cerr << "Listen failed.\n";
        close(serverSocket);
        serverSocket = -1;
        return false;
    }

    std::cout << "ShopSync TCP Server started on port "
              << port << '\n';

    return true;
}
void Server::broadcastMessage(const char* message, int senderSocket)
{
    std::lock_guard<std::mutex> lock(clientsMutex);

    for (int clientSocket : clients)
    {
        if (clientSocket != senderSocket)
        {
            send(
                clientSocket,
                message,
                strlen(message),
                0
            );
        }
    }
}
void Server::removeClient(int clientSocket)
{
    std::lock_guard<std::mutex> lock(clientsMutex);

    for (auto it = clients.begin(); it != clients.end(); ++it)
    {
        if (*it == clientSocket)
        {
            clients.erase(it);

            std::cout << "Client removed from active client list.\n";

            break;
        }
    }
}
void Server::handleClient(int clientSocket)
{
    std::cout << "Handling client in separate thread...\n";

    char buffer[1024] = {0};

    while (true)
    {
        int bytesReceived = recv(
            clientSocket,
            buffer,
            sizeof(buffer) - 1,
            0
        );

        std::cout << "recv() returned: "
                  << bytesReceived << '\n';

        if (bytesReceived <= 0)
        {
            break;
        }

        buffer[bytesReceived] = '\0';

        std::cout << "Client: "
                  << buffer << '\n';

        broadcastMessage(buffer, clientSocket);
    }

   removeClient(clientSocket);

close(clientSocket);

std::cout << "Client disconnected.\n";}

void Server::run()
{
    std::cout << "Server is waiting for clients...\n";

    while (true)
    {
        sockaddr_in clientAddress{};
        socklen_t clientLength = sizeof(clientAddress);

        int clientSocket = accept(
            serverSocket,
            (struct sockaddr*)&clientAddress,
            &clientLength
        );

        if (clientSocket == -1)
        {
            std::cerr << "Failed to accept client.\n";
            continue;
        }

        std::cout << "Client connected successfully!\n";
        {
    std::lock_guard<std::mutex> lock(clientsMutex);
    clients.push_back(clientSocket);
        }
        std::thread clientThread(
            &Server::handleClient,
            this,
            clientSocket
        );

        clientThread.detach();
    }
}