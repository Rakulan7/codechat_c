#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

MYSQL *database_connect() {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "Erreur d'initialisation de la connexion MySQL\n");
        return NULL;
    }

    if (mysql_real_connect(conn, "localhost", "root", "esgi", "codechat", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Erreur de connexion à la base de données MySQL : %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    return conn;
}

MYSQL_RES *query(MYSQL *conn, const char *query_string) {
    if (mysql_query(conn, query_string)) {
        fprintf(stderr, "Erreur lors de l'exécution de la requête : %s\n", mysql_error(conn));
        return NULL;
    }
    
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Aucun résultat retourné\n");
        return NULL;
    }
    
    return result;
}