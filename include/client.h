#ifndef CLIENT_H
#define CLIENT_H

class Client
{
private:
    int clientSocket;

public:
    Client();
    ~Client();

    bool connectToServer(const char* ip, int port);
    void sendMessage(const char* message);
    void receiveMessage();
};

#endif