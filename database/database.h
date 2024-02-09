#ifndef DATABASE_CONNECTOR_H
#define DATABASE_CONNECTOR_H

#include <mysql/mysql.h>


MYSQL *database_connect();

MYSQL_RES *query(MYSQL *conn, const char *query_string);

#endif
