#ifndef OFFLINEMESSENGER_DB_H
#define OFFLINEMESSENGER_DB_H

#include <sqlite3.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

struct user {char name[100]; char password[100];};
struct contacts {char user1[100]; char user2[100];};
struct messages {int id; char fromUser[100]; char toUser[100]; char message[500];};

class db {
private:
    sqlite3 *db;                                                // database
    char *err = 0;                                              // error code
    int rc;                                                     // response
    char query[500];                                            // query
    sqlite3_stmt *stmt;                                         // statement

public:
    void openDatabase();                                        // open database
    void createTables();                                        // create tables
    int insertUser(char name[], char password[]);               // register a user
    int selectUser(char name[], char password[]);               // verify login credentials
    void insertContact();                                       // add a new contact
    void showContacts();                                        // show all contacts for a user
    void selectContact();                                       // select a contact to chat with
    void insertMessage();                                       // insert a new message
    void showMessages();                                        // show all messages

};


#endif //OFFLINEMESSENGER_DB_H
