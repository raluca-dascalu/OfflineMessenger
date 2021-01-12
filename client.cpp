#include "client.h"

void Client::setupServer() {
    // create socket
    if ((clientsd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[client] Socket error!\n");
        return;
    }

    // setup server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    server.sin_port = htons(port);
}

void Client::connectToServer() {
    // setup server
    setupServer();

    if (connect(clientsd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
        perror("[client] Connect error!\n");
        return;
    }
    printf("[client] Connected to server!\n");
    printf("[client] Welcome to Offline Messenger!\n");
}

void Client::readMessage() {
    bzero(msg, 100);
    printf("[client] Enter message: ");
    fflush(stdout);
    char m[100];
    scanf("%s", m);
    strcat(msg, m);
}

void Client::sendMessage() {
    if (write(clientsd, msg, 100) <= 0)
    {
        perror("[client] Write error!\n");
        return;
    }
    printf("[client] Message sent: %s\n", msg);
}

void Client::getMessage() {
    bzero(msgrec, 100);
    if (read(clientsd, msgrec, 100) < 0)
    {
        perror("[client] Read error!\n");
        return;
    }
    printf("[client] Message received: %s\n", msgrec);
}

void Client::readCommand() {
    printf("[client] Please choose one of the options from below:\n");
    printf("[client] 1. Login\n");
    printf("[client] 2. Register\n");
    printf("[client] 3. Add Contact\n");
    printf("[client] 4. Select Contact\n");
    printf("[client] 5. Send Message\n");
    printf("[client] 6. Show All Contacts\n");
    printf("[client] 7. Show all messages with a contact\n");
    printf("[client] 8. Logout\n");
    printf("[client] 9. Quit\n");
    printf("[client] Enter your command: ");
    fflush(stdout);
    scanf("%d", &cmd);
}

void Client::sendCommand() {
    // send command in format 'cmdX' where X is the command
    char buf[100];
    bzero(buf, 100);
    cmd = cmd + '0';
    strcat(buf, (char *) &cmd);

    if (write(clientsd, buf, 100) <= 0)
    {
        perror("[client] Write error!\n");
        return;
    }
    printf("[client] Command sent: %s\n", buf);
}

void Client::login() {
    if (screen != LOGREG)
    {
        printf("[client] You are already logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send username to server
    printf("[client] Enter your username: ");
    readMessage();
    char usr[100];
    bzero(usr, 100);
    strcat(usr, msg);
    sendMessage();

    // send password to server
    printf("[client] Enter your password: ");
    readMessage();
    sendMessage();

    // handle server response (change screens or try again)
    getMessage();
    if (strstr(msg, usr))
    {
        screen = CONTACTS;
        bzero(username, 100);
        strcat(username, usr);
    }
}

void Client::newAccount() {
    if (screen != LOGREG)
    {
        printf("[client] You are already logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send username to server
    printf("[client] Enter a username: ");
    readMessage();
    sendMessage();

    // send password to server
    printf("[client] Enter a password: ");
    readMessage();
    sendMessage();

    // handle server response to see if name is available
    getMessage();

    // go back to login/register screen
    screen = LOGREG;
}

void Client::addContact() {
    if (screen == LOGREG)
    {
        printf("[client] You are not logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send your name to server
    bzero(msg, 100);
    strcat(msg, username);
    sendMessage();

    // send contact name to server
    printf("[client] Enter a contact name to add to your list: ");
    readMessage();
    sendMessage();

    // get server response to see if contact exists or is already in your list
    getMessage();
}

void Client::selectContact() {
    if (screen == LOGREG)
    {
        printf("[client] You are not logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send your username
    bzero(msg, 100);
    strcat(msg, username);
    sendMessage();

    // send contact name to server to start or continue chat
    printf("[client] Enter a contact name from your list to chat: ");
    readMessage();
    char usr[100];
    bzero(usr, 100);
    strcat(usr, msg);
    sendMessage();

    // get server response to see if contact is in your list
    getMessage();
    if (strstr(msg, usr))
    {
        bzero(userChat, 100);
        strcat(userChat, usr);
    }
}

void Client::sendToUser() {
    sendCommand();

    // send your username
    bzero(msg, 100);
    strcat(msg, username);
    sendMessage();

    // send contact's name
    bzero(msg, 100);
    strcat(msg, userChat);
    sendMessage();

    // send your message
    readMessage();
    sendMessage();

    // get server's feedback
    getMessage();
}

void Client::showContacts() {
    if (screen == LOGREG)
    {
        printf("[client] You are not logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send your username
    bzero(msg, 100);
    strcat(msg, username);
    sendMessage();

    // get count of contacts
    getMessage();
    int cnt = atoi(msgrec);

    // for and get contact one by one
    printf("[client] Your contacts are:\n");
    for (int i = 0; i < cnt; ++i)
    {
        getMessage();
    }
}

void Client::showMessages() {
    if (screen == LOGREG)
    {
        printf("[client] You are not logged in.\n");
        return;
    }

    // send command to server
    sendCommand();

    // send your username
    bzero(msg, 100);
    strcat(msg, username);
    sendMessage();

    // send contact's name
    bzero(msg, 100);
    strcat(msg, userChat);
    sendMessage();

    // get count of messages
    getMessage();
    int cnt = atoi(msgrec);

    // for and get messages one by one
    printf("[client] Your messages are:\n");
    for (int i = 0; i < cnt; ++i)
    {
        getMessage();
    }
}

void Client::logout() {
    if (screen == LOGREG)
    {
        printf("[client] You are not logged in.\n");
        return;
    }
    printf("[client] Logging out...\n");
    screen = LOGREG;
}

void Client::quit() {
    // send command to server
    sendCommand();
    printf("[client] Quitting messenger...\n");
    quitOption = true;
    close(clientsd);
}

void Client::handleCommand(int opt) {
    switch (opt) {
        case LOGIN:
            login();
            break;
        case REGISTER:
            newAccount();
            break;
        case ADDCONTACT:
            addContact();
            break;
        case SELECTCONTACT:
            selectContact();
            break;
        case SENDMESSAGE:
            sendToUser();
            break;
        case SHOWCONTACTS:
            showContacts();
            break;
        case SHOWMESSAGES:
            showMessages();
            break;
        case LOGOUT:
            logout();
            break;
        case QUIT:
            quit();
            break;
        default:
            printf("[client] There is no such command.\n");
            break;
    }
}

void Client::runClient() {
    // connect
    connectToServer();

    while (!quitOption)
    {
        readCommand();
        handleCommand(cmd);
    }
}
