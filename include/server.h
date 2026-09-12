#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
    int serverSocket;

public:
    Server();
    ~Server();

    bool start(int port);
    void run();
    void handleClient(int clientSocket);
};

#endif