# CS312 TP06

  * Version: 2023/01
  * 2 séances de 1h30
  * Ce TP n'est pas à rendre

Objectifs de compétences:
* Consolidation:  implémenter des classes, des méthodes.
* Quelques éléments de librairies (collections)
* Librairies externes, installation, utilisation 


## Objectif 

Le site gouvernemental [data.gouv](https://www.data.gouv.fr/fr/datasets/consommation-annuelle-delectricite-et-gaz-par-departement-et-par-secteur-dactivite/) fournit des données de consommation d'énergie par secteur d'activité, département. Nous allons jouer un peu avec ces données, un peu en mode "base de données". Cela nous donnera l'occasion de pratiquer un peu l'utilisation des bibliothèques java.

Nous vous proposons des briques de base à tester séparément, et à intégrer au fur et à mesure, suivant l'ordre que vous voulez. Essayer de ne pas trop utiliser du code tout prêt de stackoverflow ou openclassroom, mais plutôt se contenter les documentations des librairies.

Le but du jeu est de réaliser une application complète, en se débrouillant et en cherchant à toutes les étapes (et en réutilisant les compétences acquises dans les TPs précédents).

## (Optionnel) Git

* Pour travailler à deux, vous pouvez vous créer un dépot git sur le gitlab institutionnel suivant [url](https://gricad-gitlab.univ-grenoble-alpes.fr/) **votre login de l'école/mdp associé, aussi appelé "login agalan", doit être utilisé (oui, ça marche, même si c'est noté LDAP UGA)**

* Pour créer un projet git, connectez vous et suivez les instructions. Créez un "projet" privé.

* Une cheat sheet git (pdf) pour démarrer simplement  l'utilisation de git est disponible sur le Chamilo du cours de Java [url]()


## Infrastructure de code java standard

On vous fournit un package HelloWorld et un fichier ant pour le compiler:
`cd HelloWorld; ant`

* Qu'est-ce que _ant_? 

* Lire les fichiers fournis, décider du nom de votre projet java,
  adapter, tester.


## CSV: Usage de librairie externe via .jar 

On utilise la librairie common-csv d'apache:
[apache link](https://commons.apache.org/proper/commons-csv/apidocs/org/apache/commons/csv/package-summary.html)


* Chercher l'existence de cette librairie sur votre système. Installer, le cas échéant.

_Une possibilité est de récupérer un .jar quelque part (par exemple sur le site mavenlibs.com)_.

* Réaliser un test de lecture (+ écriture sur la sortie standard) du fichier csv d'énergie dans un fichier et main à part, à l'aide de la documentation. Le plus difficile est de faire le bon "import" et de réussir à compiler. (utiliser l'option -cp à la ligne de commande, pour commencer). _il va peut être falloir encore utiliser/gérer les exceptions_

* Récupérer correctement la première ligne du CSV. 

* Intégrer cette lecture/écriture dans votre projet en modifiant le fichier de configuration de `ant`. Tester.


## (Optionnel) Eclipse

Ouvrir votre projet sous Éclipse. Normalement vous pouvez "exécuter" directement n'importe quelle règle de votre fichier de configuration ant.


## Choix d'une structure de donnée: 1- interface

Objectif: comparer expérimentalement ArrayList, LinkedList, et HashMap pour la construction et la recherche.

On se propose de comparer les consommations énergétiques de l'agriculture, pour l'ensemble des départements, pour une année donnée. On filtrera donc dans un premier temps les lignes pour ne garder que les informations département/conso.

_Dans un premier temps, réaliser cet exercice dans un répertoire à part, puis fusionner_.

* Proposer une classe abstraite de stockage qui permet de stocker de telles informations (supposées uniques) et de rechercher une information pour un département donné.

* Réaliser l'implémentation avec une ArrayList. Tester la fonctionnalité en stockant quelques informations "bidon"

* Idem avec les deux autres implémentations.

* Réaliser la fusion avec l'implémentation de votre application, pour récupérer les données à l'aide de votre lecteur de CSV.

* Tester.


## Jouons avec gnuplot

Regarder le format [gnuplot]() pour tracer des courbes.

* Lire un peu la documentation et jouer à la ligne de commande avec des données écrites dans un fichier (utiliser les histogrammes)

* (Java) créer une classe de Test qui permet de tracer une courbe à l'aide d'un tableau de points (tab(i) en fonction de i). On génère le fichier .dat (en s'inspirant des exemples) 


## Choix d'une structure de données : 2-profilage, dessin de courbes

Réaliser une comparaison expérimentale des trois structures de données. 

On fera varier la taille des structures de données en prenant des sous-fichiers du fichier csv, ou en dupliquant certaines informations, et on générera des fichiers gnuplot de performance des opérations en fonction de la taille de la structure. 


## Extensions

* Représenter, stocker, interroger une nouvelle structure de données pour pouvoir tracer à la demande des courbes représentant l'évolution de la consommation d'énergie des secteurs primaire, secondaire, tertiaire sur la durée proposée par le CSV, en passant le numéro de département en paramètre. 

* Quelle hiérarchie de classe pour stocker l'ensemble des informations du CSV ?

