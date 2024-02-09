#include<stdio.h>
#include<stdlib.h>

#include "../database/database.h"

#include <openssl/rsa.h>
#include <openssl/pem.h>

#define RSA_KEY_LENGTH 2048

int generate_rsa_keys(const char *private_key_file_path, const char *public_key_file_path) {
    RSA *rsa_keypair = RSA_generate_key(RSA_KEY_LENGTH, RSA_F4, NULL, NULL);

    if (rsa_keypair == NULL) {
        fprintf(stderr, "Erreur lors de la génération des clés RSA.\n");
        return 1;
    }

    FILE *private_key_file = fopen(private_key_file_path, "wb");
    FILE *public_key_file = fopen(public_key_file_path, "wb");

    if (private_key_file == NULL || public_key_file == NULL) {
        fprintf(stderr, "Erreur lors de la création des fichiers pour les clés.\n");
        RSA_free(rsa_keypair);
        return 1;
    }

    PEM_write_RSAPrivateKey(private_key_file, rsa_keypair, NULL, NULL, 0, NULL, NULL);
    PEM_write_RSAPublicKey(public_key_file, rsa_keypair);

    RSA_free(rsa_keypair);
    fclose(private_key_file);
    fclose(public_key_file);

    printf("Génération des clés RSA terminée avec succès.\n");

    return 0;
}

void creer_compte(const char *username, const char *password)
{

    generate_rsa_keys('private.txt', 'public.txt');

    MYSQL *conn = database_connect();
    if (conn == NULL) {
        printf("Impossible de se connecter à la base de données.\n");
        return;
    }
    
    char query[255];
    sprintf(query, "INSERT INTO user_c (username, password) VALUES ('%s', '%s')", username, password);
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Erreur lors de l'exécution de la requête : %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }
    
    printf("Compte créé avec succès pour l'utilisateur : %s\n", username);
    
    mysql_close(conn);
}

int main() {
    if (generate_rsa_keys("private_key.pem", "public_key.pem") != 0) {
        fprintf(stderr, "Erreur lors de la génération des clés RSA.\n");
        return 1;
    }

    return 0;
}


/*
int main(int argc, char *argv[])
{

    char username[100];
    char password[255];

    printf("Bienvenue sur codechat !\n");
    printf("Entrez un username :\n");
    scanf("%s", &username);
    printf("Entrez un mot de passe :\n");
    scanf("%s", &password);
    creer_compte(username, password);

}
*/