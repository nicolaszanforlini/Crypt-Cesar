## Crypt-Cesar
programme de chiffrement de messages (César)

Lors de ses batailles, l'empereur romain JULES CÉSAR cryptait les messages qu'il envoyait à ses généraux.
Sa méthode de codage consistait à décaler les lettres de n rangs, vers la droite, dans l'alphabet.
Cette méthode de cryptage est appelée chiffrement de César, ou Code César.

programme :
Soit un fichier "message.txt" contenant un message :

      Bonjour Cesar,
      Chiffre Ceci,
      merci !!!
      aka = xyzXYZ
      
Le programme chiffre le message et réecrit dans le fichier avec un décallage de 5 rangs,
si le décallage dépasse alors il revient au début. exemple lettre "y" = "d".

message chiffré :

      Gtsotzw Hjxfw,
      Hmnkkwj Hjhn,
      rjwhn !!!
      fpf = cdeCDE
      
Le programme comprend un tableau en 2 dimensions pour les lowerCase et upperCase.
5 méthodes :

  - méthode de lecture de fichier.
  - méthode de récupération du message.
  - méthode d'écriture dans le fichier
  - méthode de chiffrement.
  - méthode de déchiffrement.

C
