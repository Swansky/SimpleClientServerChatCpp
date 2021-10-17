//
// Created by swansky on 17/10/2021.
//

#include "ServerManager.h"


void ServerManager::startServer() {
    serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSd < 0) {
        std::cerr << "Error establishing the server socket" << std::endl;
        exit(0);
    }
    //bind the socket to its local address

    int bindStatus = bind(serverSd, (struct sockaddr *) &serverAddress,
                          sizeof(serverAddress));
    if (bindStatus < 0) {
        std::cerr << "Error binding socket to local address" << std::endl;
        exit(0);
    }
    char *s = inet_ntoa(serverAddress.sin_addr);

    printf("IP address: %s:%d\n", s, htons(serverAddress.sin_port));

    std::cout << "Waiting for a client to connect..." << std::endl;
    //listen for up to 5 requests at a time
    listen(serverSd, 5);
    sockaddr_in newSocketAddress{};
    socklen_t newSockAddressSize = sizeof(newSocketAddress);
    //accept, create a new socket descriptor to
    //handle the new connection with client
    newSd = accept(serverSd, (sockaddr *) &newSocketAddress, &newSockAddressSize);
    if (newSd < 0) {
        std::cerr << "Error accepting request from client!" << std::endl;
        exit(1);
    }

    std::cout << "Connected with client!" << std::endl;
    //lets keep track of the session time

    gettimeofday(&start1, nullptr);
    //also keep track of the amount of data sent as well

    while (true) {
        //receive a message from the client (listen)
        std::cout << "Awaiting client response..." << std::endl;
        memset(&msg, 0, sizeof(msg));//clear the buffer
        bytesRead += recv(newSd, (char *) &msg, sizeof(msg), 0);
        if (!strcmp(msg, "exit")) {
            std::cout << "Client has quit the session" << std::endl;
            break;
        }
        std::cout << "Client: " << msg << std::endl;
        std::string message = msg;
        if (message.starts_with(CommandManager::TAG)) {
            message.replace(0, 2, "");
            printf("avant: : %s\n", message.c_str());

            message = CommandManager::executeCommand(&message);
            printf("valeur response : %s \n", message.c_str());
            memset(&msg, 0, sizeof(msg)); //clear the buffer
            strcpy(msg, message.c_str());
        } else {
            std::cout << ">";
            std::string data;
            getline(std::cin, data);
            memset(&msg, 0, sizeof(msg)); //clear the buffer
            strcpy(msg, data.c_str());

            if (data == "exit") {
                //send to the client that server has closed the connection
                send(newSd, (char *) &msg, strlen(msg), 0);
                break;
            }
        }

        //send the message to client
        bytesWritten += send(newSd, (char *) &msg, strlen(msg), 0);
    }

    closeServer();
}

void ServerManager::closeServer() {
    //we need to close the socket descriptors after we're all done
    gettimeofday(&end1, nullptr);
    close(newSd);
    close(serverSd);
    std::cout << "********Session********" << std::endl;
    std::cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << std::endl;
    std::cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
              << " secs" << std::endl;
    std::cout << "Connection closed..." << std::endl;
}

ServerManager::ServerManager(CommandManager *commandManager) : commandManager(commandManager) {
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(PORT);
}
