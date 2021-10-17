//
// Created by swansky on 17/10/2021.
//

#ifndef SERVERCHAT_SERVERMANAGER_H
#define SERVERCHAT_SERVERMANAGER_H


#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include "CommandManager.h"

class ServerManager {
private:

    CommandManager *commandManager;
    sockaddr_in serverAddress{};
    struct timeval start1{}, end1{};
    int bytesRead = 0, bytesWritten = 0;
    int newSd{};
    int serverSd{};
    char msg[1500]{};
public:
    static constexpr int PORT{19};


    explicit ServerManager(CommandManager *commandManager);

    void startServer();

    void closeServer();


};


#endif //SERVERCHAT_SERVERMANAGER_H
