#ifndef OFFLINEMESSENGER_SERVER_H
#define OFFLINEMESSENGER_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include "options.h"
#include "db.h"

class Server {
private:
    int port = 8001;                // port used
    struct sockaddr_in server;      // struct for sever
    struct sockaddr_in client;      // and client
    fd_set readfds;                 // set of readable descriptors
    fd_set activefds;               // set of active descriptors
    int maxfds;                     // maximum number of descriptors
    int serversd;                   // socket descriptor for server
    char rsp[100];                  // message response
    char msg[100];                  // message from client
    db database;                    // database

    void setupStructures();         // setup server structures
    void setupServer();             // prepare server to listen for clients
    void acceptClient();            // accept clients

    void getMessage(int fd);        // get message from client
    void sendResponse(int fd);      // send a response to the client

    void login(int fd);             // handle login case
    void newAccount(int fd);        // handle register case
    void addContact(int fd);        // handle adding a new contact
    void selectContact(int fd);     // handle selecting a contact to chat with
    void sendToUser(int fd);        // handle sending a message from client to a contact
    void showContacts(int fd);      // get the list of contacts for specified client
    void showMessages(int fd);      // get the list of messages for specified client and contact
    void quit(int fd);              // handle quit case
    void handleCommand(int opt, int fd);
    void handleClient(int fd);

public:
    void runServer();
};


#endif //OFFLINEMESSENGER_SERVER_H
