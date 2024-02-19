CREATE TABLE Utilisateurs (
    ID_utilisateur INT AUTO_INCREMENT PRIMARY KEY,
    Nom_utilisateur VARCHAR(255),
    Mot_de_passe_hash VARCHAR(255),
    Salt VARCHAR(255)
);

CREATE TABLE Messages (
    ID_message INT AUTO_INCREMENT PRIMARY KEY,
    Contenu_chiffre TEXT,
    ID_utilisateur_emetteur INT,
    ID_utilisateur_destinataire INT,
    Est_valide BOOLEAN,
    FOREIGN KEY (ID_utilisateur_emetteur) REFERENCES Utilisateurs(ID_utilisateur),
    FOREIGN KEY (ID_utilisateur_destinataire) REFERENCES Utilisateurs(ID_utilisateur)
);

CREATE TABLE Fichiers (
    ID_fichier INT AUTO_INCREMENT PRIMARY KEY,
    Contenu_chiffre BLOB,
    ID_utilisateur_emetteur INT,
    ID_utilisateur_destinataire INT,
    Est_valide BOOLEAN,
    FOREIGN KEY (ID_utilisateur_emetteur) REFERENCES Utilisateurs(ID_utilisateur),
    FOREIGN KEY (ID_utilisateur_destinataire) REFERENCES Utilisateurs(ID_utilisateur)
);

CREATE TABLE Cle_RSA (
    ID_cle_RSA INT AUTO_INCREMENT PRIMARY KEY,
    Cle_publique TEXT,
    Cle_privee TEXT,
    ID_utilisateur INT,
    FOREIGN KEY (ID_utilisateur) REFERENCES Utilisateurs(ID_utilisateur)
);

CREATE TABLE Diffie_Hellman (
    ID_session INT AUTO_INCREMENT PRIMARY KEY,
    Secret_partage TEXT,
    ID_utilisateur_A INT,
    ID_utilisateur_B INT,
    FOREIGN KEY (ID_utilisateur_A) REFERENCES Utilisateurs(ID_utilisateur),
    FOREIGN KEY (ID_utilisateur_B) REFERENCES Utilisateurs(ID_utilisateur)
);
