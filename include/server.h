#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include<mutex>
class Server
{
private:
    int serverSocket;
    std::vector<int> clients;
    std::mutex clientsMutex;
public:
    Server();
    ~Server();

    bool start(int port);
    void run();
    void handleClient(int clientSocket);
    void broadcastMessage(const char* message, int senderSocket);
    void removeClient(int clientSocket);
};

#endif