# Projet de Messagerie Chiffrée en C avec RSA

## Description du Projet
Ce projet consiste en la création d'une messagerie chiffrée en langage C, utilisant l'algorithme de chiffrement RSA. L'objectif principal est de permettre à deux utilisateurs de communiquer de manière sécurisée en chiffrant leurs messages. Le programme prend en charge le chiffrement et le déchiffrement des messages à l'aide de la cryptographie asymétrique RSA.

## Fonctionnalités
1. **Inscription et Connexion :** Les utilisateurs peuvent créer un compte avec un identifiant unique et un mot de passe sécurisé. Ils peuvent également se connecter à leur compte existant.

2. **Chiffrement des Messages avec RSA :** Les messages envoyés par les utilisateurs sont chiffrés à l'aide de l'algorithme de chiffrement RSA, assurant une sécurité robuste.

3. **Déchiffrement des Messages avec RSA :** Les messages chiffrés peuvent être déchiffrés uniquement par le destinataire autorisé grâce à la paire de clés publique/privée RSA.

4. **Liste de Contacts :** Les utilisateurs peuvent gérer leur liste de contacts, ajoutant ainsi une couche de convivialité à la messagerie.

## Utilisation
1. **Compilation :** Compilez le programme en utilisant un compilateur C standard. Par exemple, avec GCC, utilisez la commande suivante :
   ```bash
   gcc main.c -o secure_messaging -lSDL 
