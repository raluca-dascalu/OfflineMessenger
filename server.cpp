#include "server.h"

void Server::setupStructures() {
    // setup database
    database.openDatabase();
    database.createTables();

    // setup server structure
    bzero(&server, sizeof(server));

    // fill server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);

    // setup descriptors set
    FD_ZERO(&activefds);
}

void Server::setupServer() {
    // create socket
    if ((serversd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[server] Socket error!\n");
        return;
    }

    // set reusable address option
    int optval = 1;
    setsockopt(serversd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // setup server structure
    setupStructures();

    // bind server
    if (bind(serversd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1)
    {
        perror("[server] Bind error!\n");
        return;
    }

    // add server to descriptors set
    FD_SET(serversd, &activefds);
    maxfds = serversd;

    // listen for clients
    if(listen(serversd, 5) == -1)
    {
        perror("[server] Listen error!\n");
        return;
    }
}

void Server::acceptClient() {
    // setup client structure
    int len = sizeof(client);
    bzero(&client, sizeof(client));

    // accept client
    int cl = accept(serversd, (struct sockaddr *) &client, reinterpret_cast<socklen_t *>(&len));
    if (cl < 0)
    {
        perror("[server] Accept error!\n");
    }

    // update active descriptors set
    maxfds = cl;
    FD_SET(cl, &activefds);

    printf("[server] New client connected!\n");
}

void Server::getMessage(int fd) {
    bzero(msg, 100);

    int bytes = read(fd, msg, 100);
    if (bytes < 0)
    {
        perror("[server] Read error!\n");
        return;
    }
    if (bytes > 0)
    {
        printf("[server] Message received: %s\n", msg);
    } else return;
}

void Server::sendResponse(int fd) {
    printf("[server] Sending back message %s...\n", rsp);

    if (write(fd, rsp, 100) < 0)
    {
        perror("[server] Write error!\n");
        return;
    }
}

void Server::login(int fd) {
    // get username
    char user[100];
    bzero(user, 100);
    getMessage(fd);
    strcat(user, msg);

    // get password
    char password[100];
    bzero(password, 100);
    getMessage(fd);
    strcat(password, msg);

    // check in database and send response
    bzero(rsp, 100);
    if (database.selectUser(user, password) <= 0)
    {
        strcat(rsp, "User not found");
    } else {
        strcat(rsp, "Hello ");
        strcat(rsp, user);
    }
    sendResponse(fd);
}

void Server::newAccount(int fd) {
    // get username
    char user[100];
    bzero(user, 100);
    getMessage(fd);
    strcat(user, msg);

    // get password
    char password[100];
    bzero(password, 100);
    getMessage(fd);
    strcat(password, msg);

    // check in database and send response
    bzero(rsp, 100);
    if (database.insertUser(user, password) == -1)
    {
        strcat(rsp, "Error creating account");
    } else {
        strcat(rsp, "Account created successfully");
    }
    sendResponse(fd);
}

void Server::addContact(int fd) {
    // get username
    char user[100];
    bzero(user, 100);
    getMessage(fd);
    strcat(user, msg);

    // get contact name
    char contact[100];
    bzero(contact, 100);
    getMessage(fd);
    strcat(contact, msg);

    // check in database and send response
    bzero(rsp, 100);
    if (database.insertContact(user, contact) == -1)
    {
        strcat(rsp, "Error adding user");
    } else {
        strcat(rsp, "User added successfully");
    }
    sendResponse(fd);
}

void Server::selectContact(int fd) {
    // get username
    char user[100];
    bzero(user, 100);
    getMessage(fd);
    strcat(user, msg);

    // get contact name
    char contact[100];
    bzero(contact, 100);
    getMessage(fd);
    strcat(contact, msg);

    // check in database and send response
    bzero(rsp, 100);
    if (database.selectContact(user, contact) == -1)
    {
        strcat(rsp, "Error selecting contact");
    } else {
        strcat(rsp, "Contact ");
        strcat(rsp, contact);
        strcat(rsp, " selected successfully");
    }
    sendResponse(fd);
}

void Server::sendToUser(int fd) {
    // get username
    getMessage(fd);
    char username[100];
    bzero(username, 100);
    strcat(username, msg);

    // get contact to chat with
    getMessage(fd);
    char userChat[100];
    bzero(userChat, 100);
    strcat(userChat, msg);

    // get message from user to contact
    getMessage(fd);
    char message[100];
    bzero(message, 100);
    strcat(message, msg);

    bzero(rsp, 100);
    if (database.insertMessage(username, userChat, msg) == -1)
    {
        strcat(rsp, "Error sending message");
    } else {
        strcat(rsp, "Message sent successfully");
    }
    sendResponse(fd);
}

void Server::showContacts(int fd) {
    // get contact list from database and send it one by one (number of contacts first) FIXME
    bzero(rsp, 100);
    strcat(rsp, "success or fail");
    sendResponse(fd);
}

void Server::showMessages(int fd) {
    // get message list from database and send it one by one (number of messages first) FIXME
    bzero(rsp, 100);
    strcat(rsp, "success or fail");
    sendResponse(fd);
}

void Server::quit(int fd) {
    printf("[server] Client disconnected!\n");
    fflush(stdout);

    // close fd and delete from list of active descriptors
    close(fd);
    FD_CLR(fd, &activefds);
}

void Server::handleCommand(int opt, int fd) {
    switch (opt) {
        case LOGIN:
            login(fd);
            break;
        case REGISTER:
            newAccount(fd);
            break;
        case ADDCONTACT:
            addContact(fd);
            break;
        case SELECTCONTACT:
            selectContact(fd);
            break;
        case SENDMESSAGE:
            sendToUser(fd);
            break;
        case SHOWCONTACTS:
            showContacts(fd);
            break;
        case SHOWMESSAGES:
            showMessages(fd);
            break;
        case QUIT:
            quit(fd);
            break;
    }
}

void Server::handleClient(int fd) {
    getMessage(fd);

    // check if it is command
    if (msg[0] == 'c' && msg[1] == 'm' && msg[2] == 'd')
    {
        handleCommand(int(msg[3] - '0'), fd);
    }
}

void Server::runServer() {
    // setup server
    setupServer();

    while (1)
    {
        // update active descriptors
        bcopy((char *) &activefds, (char *) &readfds, sizeof(readfds));

        // select()
        if (select(maxfds + 1, &readfds, NULL, NULL, NULL) < 0)
        {
            perror("[server] Select error!\n");
            return;
        }

        for (int fd = 0; fd <= maxfds; ++fd)
        {
            if (fd == serversd && FD_ISSET(fd, &readfds))
            {
                // accept a new client
                acceptClient();
            }
            else if (fd != serversd && FD_ISSET(fd, &readfds))
            {
                // handle clients
                handleClient(fd);
            }
        }
    }
}

// database TODO
// show contacts TODO
// show history option TODO
// app will store messages in db: id, sent by user, message TODO
// reply feature by id of message and strcat(msg, r to id) before inserting in database TODO

