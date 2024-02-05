#include<stdio.h>
#include<stdlib.h>

#include "database/database.h"

int main(int argc, char *argv[])
{

    char username[100];

    printf("Veuillez saisir votre nom d'utilisateur : ");
    scanf("%s", username);
    printf("%s\n", username);

    char query[255];
    sprintf(query, "SELECT * FROM user WHERE username='%s';", username);

    MYSQL *conn;
    conn = database_connect();

    if (conn == NULL) {
        printf("Erreur lors de la connexion à la base de données.\n");
        exit(EXIT_FAILURE);
    } else {
        
        if (mysql_query(conn, query)) {
            fprintf(stderr, "Erreur lors de l'exécution de la requête : %s\n", mysql_error(conn));
            mysql_close(conn);
            exit(EXIT_FAILURE);
        }


        MYSQL_RES *result = mysql_store_result(conn);
        if (result == NULL) {
            fprintf(stderr, "Aucun résultat retourné\n");
            mysql_close(conn);
            exit(EXIT_FAILURE);
        }

        int num_rows = mysql_num_rows(result);
        if (num_rows > 0) {
            printf("Le nom d'utilisateur existe dans la base de données.\n");
        } else {
            printf("Le nom d'utilisateur n'existe pas dans la base de données.\n");
        }

        mysql_free_result(result);

        mysql_close(conn);
    }

    exit(EXIT_SUCCESS);

}