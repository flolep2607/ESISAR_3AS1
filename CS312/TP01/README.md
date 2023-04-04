# CS312 TP01 

  * Version: 2023.01
  * Pas de rendu pour ce TP
  * Travail à effectuer sous Linux (1 séance, 1h30)

## Objectif

* Comprendre la compilation et l'exécution de programmes Java
* Comprendre les variables d'environnement associées (classpath)
* Modification de classes
* Pour ce TP : 1 éditeur qui colore + **compilation à la ligne de commande**.


## Startup

Récupérez le répertoire associé à ce TP: 
* soit en faisant un git pull après un clone initial.
* soit en récupérant l'archive associée à ce dépot git à partir de la page web.

Les fichiers sont pour ce TP dans [TP01/_code](TP01/_code).

##  Compilation et exécution d'un programme Java

On fait l'hypothèse que vous avez récupéré les fichiers du TP dans `_code/` et que vous y avez ouvert un terminal.

1. Regardez le contenu  du programme source `Premice.java` (vous pouvez utiliser la commande `cat` dans votre terminal).

2. Exécutez la commande `javac` sans paramètre pour obtenir l'aide en ligne.

3. Compilez le programme `Premice.java`. Vérifiez qu'un fichier `.class` a bien été produit dans le même répertoire. Exécutez la même commande avec l'option -verbose et observez les informations générées durant le processus de compilation. Ces informations vous en apprendront plus sur la manière dont se déroule la compilation.

4. Exécutez le programme ainsi compilé avec la commande `java`.

5. Modifiez ce programme de manière à ce qu'il provoque l'affichage suivant :
```
BONJOUR CECI EST MON PREMIER PROGRAMME JAVA
```
Compilez, exécutez! **Il ne sera pas rappelé de tester, mais vous devez toujours le faire**

6. Modifiez ce programme de manière à ce qu'il affiche 
```
JE SOUSSIGNÉ(E), xx,
```
où xx est votre nom que vous passerez comme premier argument de la (ligne de) commande.

## Répertoires et _classpath_

7. Recompilez le programme précédent, en vous plaçant cette fois-ci dans le répertoire parent, et visualisez l'endroit où le fichier .class a été produit.

8. Créez maintenant deux sous-répertoires de `_code`, que vous appellerez `src` et `build`. Placez le fichier Premice.java dans le premier et, en utilisant l'option -d de javac, faites en sorte que le fichier .class soit produit dans le second.

On vous fournit un répertoire Visages, avec un sous-répertoire `Visages/src`, contenant les fichiers suivants : `VisageRond.java`, `Dessin.java` et `AppliVisage1.java`

9. Regardez ces fichiers et devinez ce que fait l'application Java.

10. Créez un répertoire build en parallèle de `src` ("à côté").

11. Placez-vous dans le répertoire `src` et compilez l'application `AppliVisage1` en utilisant la commande `javac -d ../build AppliVisage1.java` pour placer les fichiers .class dans le répertoire build.

12. Placez-vous dans le répertoire `build` et constatez que l'ensemble des classes nécessaires a été compilé.

13. Depuis ce répertoire build exécutez l'application `AppliVisage1`. Faîtes CTRL-C sur la ligne de commandes pour arrêter l'application.

14. Replacez-vous à la racine du  répertoire Visages et exécutez l'application `AppliVisage1` en utilisant l'option `-classpath build` (ou `-cp`) pour indiquer à `java` où trouver les classes à charger.

15. Déplacer le fichier `AppliVisage1.class` du répertoire build vers le répertoire Visages (son répertoire parent)

16. Essayez de ré-exécuter java `AppliVisage1`, que constatez-vous ?

Un peu de doc:

> Le processus de compilation conduit (en cas de réussite) à la génération d'un fichier .class contenant le code interprétable de la classe spécifiée en entrée. Lorsque le compilateur détecte une instruction où l'utilisation d'une autre classe est faite (appel de méthode, accès à un attribut), il tente de se procurer le fichier .class associé à cette classe afin de vérifier simplement que ladite classe est correctement utilisée (i.e. l'attribut ou la méthode existent, sont visibles,...). Le compilateur sait implicitement localiser ces fichiers pour les classes des bibliothèques fournies avec le SDK (par exemple la classe System). Pour les autres, et notamment celles écrites par les développeurs tiers, il utilise le contenu de la variable d'environnement `CLASSPATH` (qu'il est donc utile de bien initialiser et de rendre publique). La valeur de cette variable est une suite de chemins de recherche séparés par : (convention Linux) ou ; (convention DOS/Windows). L'ordre des chemins dans cette variable est important, le compilateur cessant de chercher lorsqu'il a trouvé un chemin le conduisant au fichier souhaité. Lorsque cette variable n'est pas définie, il est considéré par défaut que la recherche s'effectue uniquement dans le répertoire courant. 
> Lors de l'exécution d'une application, les classes sont chargées au fur et à mesure de leur première utilisation, en commençant par celle contenant le main. La machine virtuelle a donc besoin, comme le compilateur, d'obtenir les fichiers .class correspondant aux différentes classes. La variable d'environnement `CLASSPATH` est alors utilisée à cette fin, de la même manière. Il est cependant important d'avoir à l'esprit que le fichier .class utilisé par la machine virtuelle n'est pas forcément celui ayant été utilisé par le compilateur. Si le contenu de ces deux fichiers n'est pas identique, il peut survenir des erreurs lors de l'exécution.

17. Positionnez la variable d'environnement CLASSPATH de manière appropriée pour l'application AppliVisage1 et recompilez puis exécutez les classes sans utiliser, cette fois, l'option `-cp`. On pourra faire en deux temps, d'abord localement dans le terminal qui va lancer la commande, et ensuite dans le `bashrc`.

```
# un peu d'aide:
export CLASSPATH= .. 
```

##  Maintenant, écrivons un peu de Java

18. Observer le code de la classe `VisageRond`. Repérer accesseurs/constructeurs/ etc . Observer les commentaires javadoc (on verra dans un TP à suivre). Chercher la documentation de la librairie de dessin utilisée.

19. Modifiez la classe `VisageRond` afin que la taille par défaut d'un visage soit de `100x100` au lieu de `50x50` et recompilez cette classe. 

20. Ajouter dans la classe `VisageRond` un attribut `humeur` de type `Humeur` pouvant prendre 3 valeurs distinctes (TRANQUILLE, JOYEUX et TRISTE. Ce type doit être implémenté dans la classe `Humeur.java`) et fixe l'expressivité du visage. Modifier la méthode `dessiner` en conséquence : dans l’état tranquille la bouche sera dessinée par un trait horizontal, joyeux par un demi-cercle inférieur et triste par un demi-cercle supérieur.

La syntaxe du Switch pourra être utile:
```Java
switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```
et la déclaration d'un type enum:
```Java
public enum Nomdutype{ VAL1, VAL2, ...}
```

et on pourra utiliser la méthode `drawArc` (Graphics).

21. Construire une nouvelle classe `Oeil` pour représenter les caractéristiques d'un oeil. 

22. Modifier la classe `VisageRond` pour intégrer 2 objets de cette classe pour représenter les yeux du visage. Tester.

20 (optionnel). On souhaite améliorer le mécanisme de rebond du visage. Lorsque le visage atteindra un bord on appliquera les lois du rebond (sans perte d’énergie).
