#include <stdio.h>
#include <stdlib.h>
#include "compte/signup.h"

void administrateur() {
    // Code pour l'administrateur
}

void signup() {
    MYSQL *conn;
    char username[50];
    char password[255];

    // Connexion à la base de données
    conn = database_connect();
    if (!conn) {
        fprintf(stderr, "Impossible de se connecter à la base de données\n");
        return;
    }

    // Saisie du nom d'utilisateur et du mot de passe
    printf("Création d'un nouveau compte utilisateur\n");
    printf("Nom d'utilisateur : ");
    scanf("%49s", username); // Limite la saisie à 49 caractères
    printf("Mot de passe : ");
    scanf("%255s", password); // Limite la saisie à 255 caractères

    // Création du compte utilisateur
    if (!signup_user(conn, username, password)) {
        fprintf(stderr, "Erreur lors de la création du compte utilisateur\n");
    }

    // Fermeture de la connexion à la base de données
    mysql_close(conn);
}

void utilisateur() {
    int choix;
    int boucle;

    while (boucle) {
        printf("-----------------------------\n");
        printf("Vous avez choisi Utilisateur.\n");
        printf("Veuillez choisir :\n");
        printf("1. Connexion\n");
        printf("2. Créer un compte\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                boucle = 0;
                break;
            case 1:
                // Code pour la connexion
                break;
            case 2:
                signup();
                break;
            default:
                printf("Choix invalide. Veuillez saisir 1, 2 ou 0.\n");
                // Vidage du tampon d'entrée
                while (getchar() != '\n');
                break;
        }
    }
}

int main() {
    int choix;
    int boucle = 1;

    while (boucle) {
        printf("Veuillez choisir :\n");
        printf("1. Administrateur\n");
        printf("2. Utilisateur\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                printf("Au revoir !\n");
                boucle = 0;
                break;
            case 1:
                printf("Vous avez choisi Administrateur.\n");
                administrateur();
                boucle = 0;
                break;
            case 2:
                printf("Vous avez choisi Utilisateur.\n");
                utilisateur();
                boucle = 0;
                break;
            default:
                printf("Choix invalide. Veuillez saisir 1, 2 ou 0.\n");
                // Vidage du tampon d'entrée
                while (getchar() != '\n');
                break;
        }
    }

    exit(EXIT_SUCCESS);
}