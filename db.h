#ifndef OFFLINEMESSENGER_DB_H
#define OFFLINEMESSENGER_DB_H

#include <sqlite3.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class db {
private:
    sqlite3 *db;                                                            // database
    char *err = 0;                                                          // error code
    int rc;                                                                 // response
    char query[500];                                                        // query
    sqlite3_stmt *stmt;                                                     // statement

public:
    void openDatabase();                                                    // open database
    void createTables();                                                    // create tables
    int insertUser(char name[], char password[]);                           // register a user
    int selectUser(char name[], char password[]);                           // verify login credentials
    int insertContact(char user1[], char user2[]);                          // add a new contact
    int contactsCount(char user[]);                                         // get count of contacts
    int showContacts(char user[], const unsigned char *contacts[]);         // show all contacts for a user
    int selectContact(char user1[], char user2[]);                          // check to see if the contact is in your list
    int insertMessage(char fromuser[], char touser[], char message[]);      // insert a new message
    int messagesCount(char fromuser[], char touser[]);                      // get count of messages
    void showMessages(char fromuser[], char touser[]);                      // show all messages


};


#endif //OFFLINEMESSENGER_DB_H
