#ifndef SIGNUP_H
#define SIGNUP_H

#include <mysql/mysql.h>

int signup_user(MYSQL *conn, const char *username, const char *password);

#endif / SIGNUP_H */