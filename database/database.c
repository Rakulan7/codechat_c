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

    printf("Connexion à la base de données réussie\n");
    return conn;
}
