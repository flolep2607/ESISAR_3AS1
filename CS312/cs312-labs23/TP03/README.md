# CS312 TP03

  * Version: 2023/03
  * Travail à effectuer sous Linux (1 séance, 1.5 heures) et à terminer chez vous.
  * Travail à rendre sur Chamilo. Consignes de rendu: voir Chamilo.
  **Un travail qui ne compile pas aura la note de 0**.
  * Deadline : suivant le groupe, voir Chamilo.


## Objectif et Histoire de l'application

Nous développons ici  une application destinée à automatiser la gestion des menus et des commandes des restaurants. L'objectif est, dans un premier temps, de pouvoir créer la carte d'un restaurant à l'aide de plats et de boissons. La possibilité de créer de menus, à partir des plats de la carte, est également offerte. L'application permet ensuite de définir des commandes.
Une première version de la définition des classes de l'application (éventuellement incomplètes) est  donnée dans le répertoire `_code/`

Objectifs de compétences:
* Savoir compléter du code existant.
* Implémenter et tester de nouvelles méthodes.
* Comprendre les interfaces abstraites.
* Mécanisme d'exception


## Startup

Récupérez le répertoire associé à ce TP: 
* soit en faisant un git pull après un clone initial. 
* soit en récupérant l'archive associée à ce dépot git à partir de la page web.

Toutes les classes de l'application (éventuellement incomplètes) sont
données dans le répertoire [TP03/_code](_code/). Vous pouvez naviguer dans ce code avec votre navigateur web, ou alors directement dans le répertoire.


* Vérifier que le code fourni compile et exécute (à la main) (et que nous avons utilisé la notion de _package_).
* compilation `javac Restaurant/*.java` dans le répertoire `_code`
* exécuter `java Restaurant/TestRestaurant` ici, car c'est cette classe qui contient l'unique instance de la méthode `main`.

* Vous utiliserez BlueJ mais : vous livrerez l'ensemble des codes sources qui doivent compiler et exécuter. (uniquement les codes sources et un png du diagramme de classe). Le répertoire livré sera le répertoire `_code` dont le nom sera modifié en `TP3_VOTRENOM` ou `TP_3_NOM1_NOM2` en cas de binôme (sans espace sans accent).


## Réalisation

Nous représentons les plats et les boissons du restaurant à l'aide des classes Consommable, Boisson, Plat, Entrée, PlatPrincipal, Dessert. 

### Compréhension/ Classe abstraite

* 0) Ouvrir le code avec BlueJ et imprimer une image du diagramme de classe.

* 1) Modifier le code de sorte que Consommable soit une interface (et non une classe).
```java
public interface Consommable {
	public String getNom(); 
	public int getPrix();
}
```
Modifier en conséquence les classes `Entree`, `Plat`, `Dessert` et `Boisson`. Il pourra être utile d'ajouter une méthode `toString` pour ces classes.

* 2) Modifier la classe de test `TestRestaurant` avec une méthode main que vous compléterez au fur et à mesure que vous répondrez aux questions pour tester vos solutions. 

À partir de **maintenant** il est sous-entendu que toutes les méthodes/constructeurs seront testé·e·s au fur et à mesure.


### Les menus

Un menu correspond à une offre groupée de plats avec une boisson, proposée à un prix inférieur ou égal à la somme des prix des produits commandés séparément. Il est matérialisé par la classe Menu.

* 3) Compléter le constructeur de la classe `Menu`.

* 4) Compléter la méthode `toString` de cette même classe afin qu'elle affiche la liste des plats et la boisson du menu (par exemple : "Menu composé de Salade verte, Pizza Reine, Tiramisu, Eau, au prix de  15 euros").


Nous souhaitons vérifier, à l'intérieur de la classe Menu, que le prix fixé pour un menu est bien inférieur ou égal au prix des plats et boisson pris séparément. 

* 5.1) Ajouter à la classe Menu la méthode privée `private boolean verifPrixMenu()`
Cette méthode retourne une valeur vraie uniquement si la somme des prix des items composant un menu est supérieure ou égale au prix du menu qui doit lui-même être strictement positif. 

On décide de lancer une exception à partir du constructeur de Menu si la vérification est fausse:
```java
if (!verifPrixMenu()){
	throw new Exception("Prix menu excessif");
}
```
on modifie donc la signature de la méthode en ajoutant `throws Exception`

5.2) Réaliser avec try/catch/finally un exemple de récupération de l'erreur dans la classe de test. Si l'erreur est lancée et rattrapée, alors on n'utilise pas la classe Menu.

**Remarque**
Documentation intéressante du mécanisme d'exception:
[lien](https://fr.wikibooks.org/wiki/Programmation_Java/Exceptions)

### La carte
La carte du restaurant contient l'ensemble de plats et boissons proposés par le restaurant classés par type (entrées, plats principaux, desserts, boissons) ainsi que les différents menus. La classe Carte joue ce rôle. On peut constater, en lisant son implémentation incomplète, qu'au moment d'ajouter un item dans la carte, on vérifie qu'un item du même nom n'y apparaît pas déjà (afin d'éviter qu'un plat nommé "Tiramisu" soit inséré tandis qu'une entrée du même nom figure déjà dans la carte). 

* 6) Compléter la méthode `verifCarte` qui effectue cette vérification.

Une autre vérification est effectuée au moment de l'insertion des menus dans la carte : tous les items (plats, boissons) composant le menu doivent figurer déjà dans la carte. 

* 7) Réaliser la méthode `verifMenu` qui effectue cette vérification.


### Les commandes

Une commande est constituée d'un ensemble d'items, plats et boissons. La classe Commande permet de représenter ce concept. Pour calculer le prix d'une commande, notre application vérifie automatiquement si un sous ensemble de ces items correspond à un menu de la carte, auquel cas, ils sont facturés au prix du menu.
Par exemple, considérons une carte qui comporte:	
  * une entrée Salade verte à 4 €
  * une entrée Salade composée à 6 €
  * un plat principal Pizza Reine à 9 €
  * un plat principal Pizza Margarita à 8 €
  * un plat principal Spaghetti à la Bolognaise à 25 €
  * un dessert Tiramisu à 4 €
  * une boisson Eau gratuite
  * un menu Salade verte, Pizza Reine, Tiramisu, Eau au prix de 15 €. 

Un client commandant une Pizza Reine, une Pizza Margarita, une Salade verte et un Tiramisu avec de l'Eau devrait payer:
    * 8 €pour la Pizza Margarita
    * 15 € pour le menu composé de la Salade verte, la Pizza Reine, le Tiramisu et l'Eau
soit 23 € (et non pas 25 € qui est la somme des prix des items).

Au cas où la même combinaison de plats peut apparaître dans plusieurs menus, on privilégie systématiquement celui qui apparait en premier dans la liste des menus de la carte.

* 8) Ajouter la méthode `public int calculerPrixCommande(Commande c)` à la classe `Carte` calculant le prix d'une commande selon le principe ci-dessus.

* 9) Ajouter une méthode d'impression d'une commande. (`toString` c'est plus sympa!)

* 10) (optionnel) En utilisant les classes `BufferedReader` et `FileReader`, ajouter à la classe Carte un nouveau constructeur ayant un paramètre qui est le nom d'un fichier texte contenant la totalité des informations sur les plats et menus (dans une syntaxe que vous définirez).
