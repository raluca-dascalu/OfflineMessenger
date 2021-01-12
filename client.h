#ifndef OFFLINEMESSENGER_CLIENT_H
#define OFFLINEMESSENGER_CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "options.h"

class Client {
private:
    int port = 8001;            // port used
    int clientsd;               // socket descriptor for client
    struct sockaddr_in server;  // struct for server
    int cmd;                    // command to server
    char msg[100];              // message to be sent
    char msgrec[100];           // message received from server
    char username[100];         // name of logged in user
    char userChat[100];         // name of contact to chat with
    int screen = LOGREG;        // login/register, contacts, chat screens
    bool quitOption = false;    // quit command

    void setupServer();         // setup server structure
    void connectToServer();     // connect to the server

    void readCommand();         // read a command from stdin
    void sendCommand();         // send a command to server
    void readMessage();         // read a message from stdin
    void sendMessage();         // send a message to the server
    void getMessage();          // get a response from the server

    void login();               // handle login case
    void newAccount();          // handle register case
    void addContact();          // handle adding a new contact
    void selectContact();       // handle selecting a contact to chat with
    void sendToUser();          // send a message to the selected user
    void showContacts();        // show all your contacts
    void showMessages();        // show all your messages with a user
    void logout();              // handle logout case
    void quit();                // handle quit case
    void handleCommand(int opt);

public:
    void runClient();
};


#endif //OFFLINEMESSENGER_CLIENT_H
