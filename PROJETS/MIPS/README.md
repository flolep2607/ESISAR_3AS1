# Projet CS351 (2022-2023): Émulateur MIPS

---
title: Projet CS351 (2022-2023): Émulateur MIPS
author: MONCORGE Lukas x LEPRAT Florian
date: 14/11/22
---

## Rendu 1

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [x] Vérifié que `make test-cli` ne renvoie pas d'erreur.
  - [x] Vérifié que `make tests` se plaint sur le nombre d'instructions et pas sur l'existence des fichiers de sortie.
  - [x] Vu que les soumissions se font avec `make tar`.


## Rendu 2

(Une dizaine de lignes devrait suffire à chaque fois)

* Comment avez-vous choisi de programmer l'analyse de texte (dont la lecture
des opérandes entières) ?

Pour cela, nous avons une fonction qui prend l'instruction en paramètre, et nous avons une liste d'opcodes, la fonction compare les premiers caractères de cette instruction avec les éléments de notre liste.

* Avez-vous vu des motifs récurrents émerger ? Avez-vous "factorisé" ces motifs
pour éviter de les répéter ? Si non, serait-ce difficile ?

Oui, il y a 3 types différents d'instructions : I, J et R. Nous avons classé les différents types entre eux, puis nous avons fait une boucle. Sans ça, ce serait plus pénible que difficile.

* Comment avez-vous procédé pour écrire les tests ? Étes-vous confiant·e·s que
toutes les instructions gérées sont couvertes ? 

Nous avons testé avec un jeu d'instructions assez varié. Nous sommes confiants que toutes les instructions soient couvertes, car notre jeu était assez large.

* Quelle a été votre expérience avec l'utilisation et la compréhension de la
documentation (ie. des annexes) ?

Tout n'était pas forcément très clair.

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :
  - [x] Implémenté la traduction pour des instructions de toutes les catégories
      (calcul, comparaisons, sauts, HI/LO, mémoire)
  - [x] Implémenté la traduction pour toutes les instructions de l'annexe 2
  - [x] Pris en compte les cas particuliers : valeurs négatives, hors limites,
      noms d'instructions ou opérandes invalides...


## Rendu 3

(10/15 lignes devrait suffire à chaque fois)

* Quelle structure en modules planifiez-vous d'utiliser pour l'émulateur ?
L'émulateur MIPS est divisé en modules tels que:

- Un module de lecture des instructions MIPS qui lit les instructions MIPS depuis une source (par exemple, un fichier ou une mémoire) et les prépare pour l'exécution.

- Un module d'exécution des instructions MIPS qui effectue les opérations définies par les instructions MIPS sur les données stockées dans les registres et la mémoire.

- Un module de gestion des registres qui gère les registres utilisés par le processeur MIPS et stocke les données utilisées par les instructions MIPS.

- Un module de gestion de la mémoire qui gère l'accès à la mémoire utilisée par le processeur MIPS et stocke les données utilisées par les instructions MIPS.


* Quelles seront les fonctions principales de chaque module ?

- Le module de lecture des instructions MIPS peut avoir pour fonction principale de lire les instructions MIPS depuis une source (par exemple, un fichier ou une mémoire), de les décoder et de les préparer pour l'exécution.

- Le module d'exécution des instructions MIPS peut avoir pour fonction principale d'exécuter les instructions MIPS en effectuant les opérations définies par ces instructions sur les données stockées dans les registres et la mémoire.

- Le module de gestion des registres peut avoir pour fonction principale de gérer les registres utilisés par le processeur MIPS, en stockant les données utilisées par les instructions MIPS et en gérant l'accès à ces données par les instructions MIPS.

- Le module de gestion de la mémoire peut avoir pour fonction principale de gérer l'accès à la mémoire utilisée par le processeur MIPS, en stockant les données utilisées par les instructions MIPS et en gérant l'accès à ces données par les instructions MIPS.

* Quels avantages voyez vous à cette structure (à comparer à un unique fichier)?

Une structure en modules permet de rendre le code plus facile à maintenir et à mettre à jour,
car les différentes parties du programme sont organisées de manière claire et logique.
De plus, une structure en modules peut permettre une meilleure réutilisation du code,
ce qui peut accélérer le développement de l'émulateur.
Enfin, une structure en modules peut également faciliter la collaboration entre plusieurs développeurs sur un même projet.

## Rendu 4

* Avez-vous réussi à suivre la structure prévue au rendu 3 ? Quelles
modifications ont été nécessaires ? Rétrospectivement, est-ce que cette
structure était bien prévue ?

Oui, nous avons réussi à obtenir la structure prévue, elle était bien prévue.

* Avez-vous compris le fonctionnement de chaque instruction à partir de la
documentation fournie ? Si non, quels sont les points obscurs ?

Nous avons compris le fonctionnement de chacune des instructions à partir de la documentation, ou à défaut après de rapides recherches.

* Quels exemples de programmes avez-vous choisi pour tester le calcul ? Les
comparaisons et sauts ? La mémoire ?

Nous avons testé avec des programmes comprenant des instructions diverses.

* Le sujet spécifie-t-il tous les détails nécessaires pour bien implémenter la
mémoire ? Quels choix avec-vous faits ?

Puisque nous ne savions pas comment définir la fin d'un programme, nous avons considéré que le programme se finissait par un syscall.

* Reste-t-il des bugs que vous avez découverts et pas corrigés ?

Rien que nous n'ayons vu.

* D'autres remarques sur votre programme ?

Rien à signaler.

* Cochez (en remplaçant `[ ]` par `[x]`) si vous avez :**
  - [x] Implémenté l'émulation de toutes les instructions gérées par le rendu 2.
  - [x] Implémenté l'émulation de toutes les instructions.
  - [x] Tous vos tests qui passent.
  - [x] Vérifié que vous tests couvrent toutes les instructions émulées.
  - [x] Testé les cas particuliers : valeurs négatives, overflows...
  - [x] Testé les cas d'erreur : division par zéro, sauts invalides...
  - [ ] Un port fonctionnel de DOOM pour votre émulateur.

* Des retours sur le projet en général ?

Les créneaux sur le projet étaient en général assez mal placés, au moins pour notre groupe de TP.
