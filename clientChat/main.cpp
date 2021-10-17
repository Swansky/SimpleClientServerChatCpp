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

static constexpr int PORT{19};

int main(int argc, char *argv[]) {

    //create a message buffer
    char msg[1500];

    //setup a socket and connection tools
    struct hostent *host = gethostbyname("127.0.0.1");
    sockaddr_in sendSockAddress{};
    bzero((char *) &sendSockAddress, sizeof(sendSockAddress));
    sendSockAddress.sin_family = AF_INET;
    sendSockAddress.sin_addr.s_addr =
            inet_addr(inet_ntoa(*(struct in_addr *) *host->h_addr_list));
    sendSockAddress.sin_port = htons(PORT);
    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
    //try to connect...
    int status = connect(clientSd,
                         (sockaddr *) &sendSockAddress, sizeof(sendSockAddress));
    if (status < 0) {
        std::cout << "Error connecting to socket!" << std::endl;
        exit(0);
    }
    std::cout << "Connected to the server!" << std::endl;
    int bytesRead = 0, bytesWritten = 0;
    struct timeval start1{}, end1{};
    gettimeofday(&start1, nullptr);
    while (true) {
        std::cout << ">";
        std::string data;
        getline(std::cin, data);
        memset(&msg, 0, sizeof(msg));//clear the buffer
        strcpy(msg, data.c_str());
        if (data == "exit") {
            send(clientSd, (char *) &msg, strlen(msg), 0);
            break;
        }
        bytesWritten += send(clientSd, (char *) &msg, strlen(msg), 0);
        std::cout << "Awaiting server response..." << std::endl;
        memset(&msg, 0, sizeof(msg));//clear the buffer
        bytesRead += recv(clientSd, (char *) &msg, sizeof(msg), 0);
        if (!strcmp(msg, "exit")) {
            std::cout << "Server has quit the session" << std::endl;
            break;
        }
        std::cout << "Server: " << msg << std::endl;
    }
    gettimeofday(&end1, nullptr);
    close(clientSd);
    std::cout << "********Session********" << std::endl;
    std::cout << "Bytes written: " << bytesWritten <<
              " Bytes read: " << bytesRead << std::endl;
    std::cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
              << " secs" << std::endl;
    std::cout << "Connection closed" << std::endl;
    return 0;
}
