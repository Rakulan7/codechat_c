#include<stdio.h>
#include<stdlib.h>

#include "database/database.h"

int main(int argc, char *argv[])
{

    MYSQL *conn;
    conn = database_connect();

    if (conn == NULL) {
        printf("Erreur lors de la connexion à la base de données.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Connexion réussie à la base de données.\n");
        // Effectuer d'autres opérations sur la base de données ici...
        mysql_close(conn);
    }

    exit(EXIT_SUCCESS);

}