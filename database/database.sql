CREATE TABLE user_c(
   id_user VARCHAR(50),
   username VARCHAR(50),
   password VARCHAR(255),
   clepublique INT,
   PRIMARY KEY(id_user)
);

CREATE TABLE message(
   id_message VARCHAR(50),
   message VARCHAR(50),
   dateheure DATETIME,
   id_user VARCHAR(50) NOT NULL,
   PRIMARY KEY(id_message),
   FOREIGN KEY(id_user) REFERENCES user_c(id_user)
);

CREATE TABLE message_by(
   id_user VARCHAR(50),
   id_message VARCHAR(50),
   PRIMARY KEY(id_user, id_message),
   FOREIGN KEY(id_user) REFERENCES user_c(id_user),
   FOREIGN KEY(id_message) REFERENCES message(id_message)
);
