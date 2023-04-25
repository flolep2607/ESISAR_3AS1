# CS312 TP05

  * Version: 2023/01
  * 1 séances de 1h30
  * Ce TP n'est pas à rendre

Objectifs de compétences:
* Consolidation: utiliser le mécanisme d'exception ([doc/oracle/java8](https://docs.oracle.com/javase/8/docs/api/java/lang/Exception.html))
[lien wikibook](https://fr.wikibooks.org/wiki/Programmation_Java/Exceptions)
* Consolidation:  implémenter des classes, des méthodes.
* Quelques éléments de librairies.

## Exercice 1 : Recherches dans un tableau (avec exceptions)

_On se posera la question de l'usage nécessaire ou pas du mot clé throws_

Dans un unique fichier `FindArray.java` (non fourni):

* Écrire une méthode qui recherche un élément dans un tableau. Si l'objet est trouvé, la fonction retourne la première position où se trouve l'objet, sinon elle lance une exception (on cherchera une exception existante adéquate). Tester.

* Écrire une méthode qui cherche dans un tableau de chaînes la première chaîne qui peut être lue comme un entier à l'aide de la méthode `ParseInt`. Elle lancera une exception adéquate si il n'y a pas de telle chaîne. Tester.


## Exercice 2 : Lecture/Écriture dans des fichiers (package IO)

Dans cet exercice et le suivant on réalise une application sous la forme de 2 fichiers java qui font partie du package `IO` (voir le TP1). On générera les .class dans le répertoire `IO/build/` (à créer). 
On lancera à partir du répertoire `IO` (ou dans BlueJ):
```
java -cp build/ IO.Files ...
```

* Lire la documentation de InputStream, FileInputStream, Reader, InputStreamReader.

Dans un unique fichier `Files.java`:

* Écrire une méthode prenant un nom de fichier (chaîne) en paramètre, qui parcourt le fichier en le lisant caractère par caractère, compte et retourne ce nombre de caractères. On prévoiera d'éventuelles exceptions.

* Tester (fonction main), en passant le nom du fichier en paramètre à la ligne de commande (possible avec BlueJ, clic droit sur la classe qui contient le main)

* Écrire une méthode qui copie un fichier en un autre en supprimant les blancs en fin de ligne. Tester.

Remplir la classe `BitOutputStream` permettant de faire des sorties bit à bit (en découpant les octets en petits bouts. On vous a fourni de la documentation javadoc pour comprendre les fonctionnalités, dans un premier temps).

* Tester: créer une instance de la classe dans le main de la class Files, et inventer comment tester les méthodes. 


## Exercice 3 : Java doc - classe BitOutputStream précédente.


Le SDK fournit un outil de génération de documentation (avec pour
cible privilégiée le langage HTML) nommé javadoc et basé sur
l'utilisation de balises (tags) dans le code source. Vous pouvez
consulter la partie de la documentation en ligne traitant de cet outil
afin de vous familiariser avec les balises et les paramètres de la
ligne de commande. La finalité de cet outil est de fournir une
documentation pour chaque classe, détaillant notamment la
signification des attributs, des méthodes, des paramètres et valeurs
de retour.

Les commentaires JavaDoc s'insèrent toujours avant ce qu'ils sont
censés décrire, et peuvent mélanger du texte qui sera inséré tel quel
dans la documentation et des balises interprétées par l'outil. Il est
par exemple possible, en utilisant cette syntaxe, de préciser à quoi
sert la classe, qui en sont les auteur·ice :s et quel est le numéro de version,
et de documenter les fonctionnalités des méthodes implémentées.

En lisant la classe `BitOutputStream` précédente: 
* Comment sont spécifiées les informations générales (version, etc) ?
* Dans la documentation d'une méthode, comment sont spécifiés les paramètres et leur type? l'éventuelle valeur de retour ? 


* Créer un répertoire docs dans le répertoire `IO`
* À partir du répertoire IO: lancer la commande `javadoc -d docs src/*.java` . 
* Consulter la documentation générée cette documentation à l'aide d'un navigateur (`firefox index.html &`).

* Documenter la classe `Files`, et regénérer la documentation.


## Exercice 4 : Jar

Il est dans certains cas utile (notamment pour livrer un logiciel) de
regrouper au sein d'une archive l'ensemble de classes d'une
application ou d'une librairie. Une telle archive a, en Java, un
format normalisé et se dénomme un `jar`. Un outil éponyme permet
d'archiver des classes.

La syntaxe de la commande de création d'archive est la suivante : 
```
jar -cvf [chemin-nom du jar à créer] [chemin-noms des fichiers à inclure]
``` 
Les fichiers à inclure sont désignés par leur nom uniquement.  Il est possible d'utiliser des jokers (par exemple A*.class) ou d'indiquer un nom de répertoire (ce qui aura pour effet d'inclure tous les fichiers du répertoire, en conservant la structure dans l'archive). L'outil `jar` considère comme répertoire de base celui à partir duquel il est exécuté, si l'on souhaite inclure des fichiers situés dans un autre répertoire, il faut spécifier avant leur nom le chemin conduisant au répertoire avec l'option `-C`.

Lorsque les fichiers `.class` sont archivés, il faut que la variable `CLASSPATH` contienne non pas le répertoire contenant l'archive jar mais le chemin désignant l'archive elle-même.

* À partir du  répertoire `build`, construire un fichier `IO.jar`, positionné à la racine du répertoire `IO`, contenant l'ensemble des .class de l'application.

L'exécution de cette commande donne chez moi quelque chose comme:
```
ajout : IO/BitOutputStream.class(entrée = 1464) (sortie = 809)(compression : 44 %)
ajout : IO/Files.class(entrée = 1726) (sortie = 984)(compression : 42 %)
```
* Utiliser l'option `tf` de jar pour regarder le contenu du .jar généré.

Nous désirons maintenant d'exécuter directement l'application contenue dans cette archive (à l'aide de l'option -jar de l'outil java). Il faut pour celà spécifier le point d'entrée de l'application, on utilise donc un fichier de métadonnées appelé `manifest.txt` (qui est parfois automatiquement créé par vos éditeurs).

* Editer un fichier `manifest.txt` contenant uniquement la ligne `Main-Class: IO.Files` (attention, la ligne doit se terminer par un saut de ligne)

* Recréer l'archive en incluant le manifest avec l'option `-m` (syntaxe : `jar -cvmf [manifeste] [jar] [fichiers]`)

```
jar cfm ../IO.jar manifest.txt IO/*.class
```

* Exécuter directement l'application avec l'option `-jar` de java. 

