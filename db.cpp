#include "db.h"

void db::openDatabase() {
    rc = sqlite3_open("messenger.db", &db);

    if (rc != SQLITE_OK)
    {
        printf("Error opening database! %s\n", sqlite3_errmsg(db));
        return;
    } else {
        printf("Database opened successfully!\n");
    }
}

void db::createTables() {
    // create table users
    bzero(query, 500);
    strcat(query, "CREATE TABLE users("
                  "name TEXT PRIMARY KEY NOT NULL, "
                  "password TEXT NOT NULL);");
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Error creating table users: %s\n", err);
    }

    // create table contacts
    bzero(query, 500);
    strcat(query, "CREATE TABLE contacts("
                  "user1 TEXT NOT NULL, "
                  "user2 TEXT NOT NULL,"
                  "PRIMARY KEY(user1, user2),"
                  "FOREIGN KEY(user1) REFERENCES users(name),"
                  "FOREIGN KEY(user2) REFERENCES users(name));");
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Error creating table contacts: %s\n", err);
    }

    // create table messages
    bzero(query, 500);
    strcat(query, "CREATE TABLE messages("
                  "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "fromuser TEXT NOT NULL, "
                  "touser TEXT NOT NULL,"
                  "message TEXT,"
                  "FOREIGN KEY(fromuser, touser) REFERENCES contacts(user1, user2));");
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Error creating table messages: %s\n", err);
    }
}

int db::insertUser(char name[], char password[]) {
    // build query
    bzero(query, 500);
    strcat(query, "INSERT INTO users VALUES('");
    strcat(query, name);
    strcat(query, "', '");
    strcat(query, password);
    strcat(query, "');");

    // insert into table
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Insert user error: %s\n", err);
        return -1;
    }
    return rc;
}

int db::selectUser(char name[], char password[]) {
    // build query
    bzero(query, 500);
    strcat(query, "SELECT count(*) FROM users WHERE name = '");
    strcat(query, name);
    strcat(query, "' AND password = '");
    strcat(query, password);
    strcat(query, "';");

    // check if user is in database and if name matches with password
    sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    sqlite3_step(stmt);
    int cnt = sqlite3_column_int(stmt, 0);

    if(cnt > 0) return 1;
    else return 0;
}

int db::insertContact(char user1[], char user2[]) {
    // build query
    bzero(query, 500);
    strcat(query, "INSERT INTO contacts VALUES('");
    strcat(query, user1);
    strcat(query, "', '");
    strcat(query, user2);
    strcat(query, "');");

    // insert into table
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Insert contact error: %s\n", err);
        return -1;
    }
    return rc;
}

int db::contactsCount(char user[]) {
    // build query
    bzero(query, 500);
    strcat(query, "SELECT count(*) FROM contacts WHERE user1 = '");
    strcat(query, user);
    strcat(query, "';");

    sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    sqlite3_step(stmt);
    int cnt = sqlite3_column_int(stmt, 0);

    return cnt;
}

int db::showContacts(char user[], const unsigned char *contacts[]) {
    int cnt = contactsCount(user);

    // build query
    bzero(query, 500);
    strcat(query, "SELECT user2 FROM contacts WHERE user1 = '");
    strcat(query, user);
    strcat(query, "';");

    for (int i = 0; i < cnt; ++i)
    {
        sqlite3_prepare_v2(db, query, -1, &stmt, 0);
        sqlite3_step(stmt);
        contacts[i] = sqlite3_column_text(stmt, 0);
    }

    return cnt;
}

int db::selectContact(char user1[], char user2[]) {
    // build query
    bzero(query, 500);
    strcat(query, "SELECT count(*) FROM contacts WHERE user1 = '");
    strcat(query, user1);
    strcat(query, "' AND user2 = '");
    strcat(query, user2);
    strcat(query, "';");

    // check if user is in database and if name matches with password
    sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    sqlite3_step(stmt);
    int cnt = sqlite3_column_int(stmt, 0);

    if(cnt > 0) return 1;
    else return -1;
}

int db::insertMessage(char fromuser[], char touser[], char message[]) {
    // build query
    bzero(query, 500);
    strcat(query, "INSERT INTO messages(fromuser, touser, message) VALUES('");
    strcat(query, fromuser);
    strcat(query, "', '");
    strcat(query, touser);
    strcat(query, "', '");
    strcat(query, message);
    strcat(query, "');");

    // insert into table
    rc = sqlite3_exec(db, query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        printf("Insert user error: %s\n", err);
        return -1;
    }
    return 0;
}

int db::messagesCount(char fromuser[], char touser[]) {
    // build query
    bzero(query, 500);
    strcat(query, "SELECT count(*) FROM messages WHERE (fromuser = '");
    strcat(query, fromuser);
    strcat(query, "' AND touser = '");
    strcat(query, touser);
    strcat(query, "') OR (fromuser = '");
    strcat(query, touser);
    strcat(query, "' AND touser = '");
    strcat(query, fromuser);
    strcat(query, "');");

    sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    sqlite3_step(stmt);
    int cnt = sqlite3_column_int(stmt, 0);

    return cnt;
}

int db::showMessages(char fromuser[], char touser[], const unsigned char *messages[]) {
    // message format "id:? from:? message:?"
    int cnt = messagesCount(fromuser, touser);

    // build query
    bzero(query, 500);
    strcat(query, "SELECT select 'id:' || id || ' from:' || fromuser || ' message:' || message "
                  " as MSG FROM messages WHERE (fromuser = '");
    strcat(query, fromuser);
    strcat(query, "' AND touser = '");
    strcat(query, touser);
    strcat(query, "') OR (fromuser = '");
    strcat(query, touser);
    strcat(query, "' AND touser = '");
    strcat(query, fromuser);
    strcat(query, "');");

    for (int i = 0; i < cnt; ++i)
    {
        sqlite3_prepare_v2(db, query, -1, &stmt, 0);
        sqlite3_step(stmt);
        messages[i] = sqlite3_column_text(stmt, 0);
    }

    return cnt;
}