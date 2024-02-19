#include "signup.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int signup_user(MYSQL *conn, const char *username, const char *password) {
    // Vérifier que l'utilisateur n'existe pas déjà
    char query[256];
    MYSQL_RES *result;
    MYSQL_ROW row;

    snprintf(query, sizeof(query), "SELECT * FROM codechat_user WHERE username='%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Erreur lors de la recherche de l'utilisateur existant: %s\n", mysql_error(conn));
        return 0; // Échec de la recherche
    }
    printf("test 1");
    result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Erreur lors de la récupération du résultat de la requête: %s\n", mysql_error(conn));
        return 0; // Échec de la récupération du résultat
    }
    printf("test 2");
    if (mysql_num_rows(result) > 0) {
        mysql_free_result(result);
        printf("Le nom d'utilisateur existe déjà. Veuillez en choisir un autre.\n");
        return 0; // Nom d'utilisateur déjà existant
    }
    printf("test 3");
    mysql_free_result(result);

    // Insérer le nouvel utilisateur dans la base de données avec le mot de passe en texte brut
    snprintf(query, sizeof(query), "INSERT INTO codechat_user (username, user_password) VALUES ('%s', '%s')", username, password);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Erreur lors de l'insertion de l'utilisateur dans la base de données: %s\n", mysql_error(conn));
        return 0; // Échec de l'insertion
    }
    printf("test 4");

    printf("Utilisateur inscrit avec succès !\n");
    return 1; // Succès
}