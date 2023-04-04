# CS312 TP02

  * Version: 2023/02
  * Pas de rendu pour ce TP
  * Travail à effectuer sous Linux (1 séance, 1.5 heures)

## Objectif et histoire de l'application

Vous allez réaliser une application (modeste) destinée à gérer les
emplois du temps d’établissements d’enseignement (telle que ADE pour
les emplois du temps de l’Esisar) en se limitant à la gestion des
salles et des activités pédagogiques. 

Compétences:
* Pratiquer la programmation Java: analyse, modification de classes existantes.
* Utiliser la notion d'héritage: compréhension de base 
* Éditeur à utiliser **obligatoirement** (cf J.-L. König) BlueJ. Vous continuerez à compiler dans un terminal à côté.


## Startup

Récupérez le répertoire associé à ce TP: 
* soit en faisant un `git pull` après un clone initial.
* soit en récupérant l'archive associée à ce dépot git à partir de la page web.
* si vous avez déjà un dépot local: commit, et pull. 

Toutes les classes de l'application (éventuellement incomplètes) sont
données dans le répertoire [TP02/_code](_code/). Vous pouvez naviguer dans ce code avec votre navigateur web, ou alors directement dans le répertoire.

On rappelle la compilation:
* Pour compiler, on écrira `javac *.java` dans le répertoire `_code`
* Pour exécuter `java Planning` ici, car c'est cette classe qui contient l'unique instance de la méthode `main`.

* Dans un terminal, **vérifier** que le code fourni compile et exécute. À ce stade, il ne fait pas grand chose, vu que vous devez le compléter. Repérer dans les classes `Planning` et `Creneau` les fonctions à implémenter: elles contiennent un commentaire avec `TODO`. (grep est votre ami)

## BlueJ 

* Installation, utilisation cf [Ce lien](INSTALL_BlueJ.md)

## Modélisation du problème

Les salles d'enseignement sont représentées à  l’aide des classes Salle, SalleCTD, SalleTP et de l'énumération Discipline.

Les groupes d'étudiants sont modélisés par la classe Groupe. Un groupe est caractérisé par son nom et son effectif (par exemple, "3ATP1" et 16 pour les élèves du premier groupe de TP de 3A).

Les activités pédagogiques sont, quant à elles, représentées par les classes Activité et ses sous-classes CM, TD, TP. Ainsi, une instance de la classe Activité correspond à une activité pédagogique (CM, TD ou TP) caractérisée par:
* son nom (par exemple, "CS312 TP1")
* les groupes d’étudiants qui lui sont associés (par exemple, le groupe TP1 pour "CS312 TP1"),
* la liste des salles qui techniquement peuvent l’accueillir (salles de cours pour un CM ou un TD, salles de TP pour les TP), _indépendamment de leur nombre de places_.

## À vous:  application version de base

* Est-il possible de créer une activité pédagogique de type TD et lui associer des salles de TP ?
* Dessiner rapidement le diagramme des classes fournies. Repérer les méthodes non implémentées (elles sont nommés en commentaire avec `TODO`).
* Ouvrez maintenant le code avec **BlueJ** (cf doc) et regardez le diagramme de classe.
* Dessiner **sans exécuter** les objets qui devront être créés lors de l'exécution de la partie du _main_ décrite ci-dessous (extrait de `Planning.java`)
```Java
		SalleCTD a042 = new SalleCTD(100, "A042");
		SalleCTD d030 = new SalleCTD(180, "D030");

		SalleTP b141 = new SalleTP(16, "B141", Discipline.Informatique);
		SalleCTD a048 = new SalleCTD(25, "A048");
		
		CM cs310cm = new CM("CM CS310");
		cs310cm.addSalle(a042);
		cs310cm.addSalle(d030);

		TP cs330tp1 = new TP("TP1 CS330");
		cs330tp1.addSalle(b141);
		
		CM cs410cm = new CM("CM CS410");
		cs410cm.addSalle(a042);
		cs410cm.addSalle(d030);
		cs410cm.addSalle(a048);
		
		CM cs421_422cm = new CM("CM CS421 - CS422");
		cs421_422cm.addSalle(a042);
		cs421_422cm.addSalle(d030);
		cs410cm.addSalle(a048);
		
		Groupe a3tp1 = new Groupe("3ATP1", 16);
		Groupe a3tp2 = new Groupe("3ATP2", 16);
		Groupe a3tp3 = new Groupe("3ATP3", 16);
		Groupe a3tp4 = new Groupe("3ATP4", 16);
		Groupe a3tp5 = new Groupe("3ATP5", 16);

		Groupe a4ir = new Groupe("4AIR", 29);
		Groupe a4eis = new Groupe("4AEIS", 35);
		
		cs310cm.addGroupe(a3tp1);
		cs310cm.addGroupe(a3tp2);
		cs310cm.addGroupe(a3tp3);
		cs310cm.addGroupe(a3tp4);
		cs310cm.addGroupe(a3tp5);

		cs330tp1.addGroupe(a3tp1);
```

* Compilez : javac ou le bouton compile dans BlueJ.
* Exécutez le code:
- ` java Planning` à la ligne de commande 
- Ou clic droit sur la classe Planning (dans BlueJ)

La classe Créneau permet d'associer une activité pédagogique à une salle effective dans une tranche horaire donnée. Ainsi, son constructeur reçoit en paramètre un horaire (année, mois, jour, heure et minute de début, durée), une activité et une salle. Il procède à trois vérifications réalisées par les trois méthodes privées `vérifSalle`, `vérifDurée`, `vérifCapacité`, qui sont à implémenter:

* Réaliser la méthode `verifDuree` qui retourne vrai si et seulement si le créneau horaire est contenu entre 8h et 19h. 
* Réaliser la méthode `verifSalle` qui retourne vrai si et seulement si la salle du créneau est bien une des salles appropriées pour l'activité.
* Réaliser la méthode `verifCapacite` qui retourne vrai si la salle du créneau a une capacité au **plus** égale à la somme des effectifs des groupes associés à l'activité.

Dans les trois cas on évitera l'atrocité algorithmique suivante:
```
if (machin == true) return true else return false
```
qui est, rappellons-le, équivalent à:
```
return machin
```
* Tester ces trois vérifications en réalisant dans le main des appels "illicites" au constructeur de `Creneau`: modifier le _main_, compiler, exécuter. On regardera en particulier comment l'exécution s'arrête en cas d'appel "illicite".


La classe principale de notre application est la classe Planning. Elle gère une liste de créneaux en effectuant quelques opérations de vérification et de consultation. La méthode addCréneau, notamment, permet d'insérer dans l'emploi du temps  un créneau préalablement créé. Avant l'insertion du créneau, il faut s'assurer qu'il est compatible avec ceux déjà insérés ou, autrement dit, il ne présente pas d'intersection avec eux. Deux créneaux ont une intersection si leurs tranches horaires se chevauchent et, soit ils occupent la  même salle, soit ils sont associés à des activités ayant des groupes d'élèves en commun. Par exemple, à  la suite du code proposé ci-dessus (gros pâté de code du main) les instructions:
```Java
c1 = new Creneau(2014, 1, 17, 13, 15, 105, a042, cs310cm);
c2 = new Creneau(2014, 1, 17, 13, 15, 210, b141, cs330tp1);
```
créent deux créneaux qui ne pourront pas coexister dans l'emploi du temps étant donné qu'ils concernent tous les deux le même groupe a3tp1. Ainsi, la méthode `addCreneau` n'ajoute à l'emploi du temps un créneau qu'après avoir appelé la méthode `verifCreneau` qui effectue cette vérification, en faisant elle-même appel à la méthode intersection de la classe Créneau.

**IMPORTANT**  chaque écriture de méthode doit être suivie d'un ou plusieurs tests, qui sont en général fournis dans le main. Ne pas passer à la suite si le test n'est pas concluant. 

* Réaliser la méthode intersection de la classe Créneau. 
* Réaliser la méthode planningGroupe de la classe Planning qui, pour un groupe donné, retourne la liste des créneaux qui lui sont associés dans l'emploi du temps. 
* Réaliser la méthode totalHeuresGroupe de la classe Planning qui, pour un groupe donné, retourne le nombre total d'heures d'enseignement le concernant dans l'emploi du temps.


## Extensions (conception)

Cette première version de l'application peut être améliorée de plusieurs manières, dont deux exemples suivants:

* Actuellement, rien n'empêche qu'un TP d'automatique se déroule dans une salle de TP d'informatique. Quelles modifications doit-on apporter à l'application pour que les TP d'une discipline donnée ne puissent se dérouler que dans des salles de TP de cette discipline? (question à rédiger)

* Dans la réalité, la notion de groupe est plus riche que sa représentation par la classe Groupe. En effet, la totalité de la promotion p2018 constitue un groupe décomposé en groupes de TD et groupes de TP. On peut donc naturellement souhaiter pouvoir introduire cette notion de dépendance (ou appartenance) entre groupes. Par exemple, si a3promo est le groupe associé à l'ensemble de la promotion de 3A et a3tp1 est le premier groupe de TP, la séquence de code suivante ne devrait pas ajouter le créneau c2 dans l'emploi du temps.
```
        cs310cm.addGroupe(a3promo);
		cs330tp1.addGroupe(a3tp1);
				
		Créneau c1 = null, c2 = null;

		c1 = new Créneau(2014, 1, 17, 13, 15, 105, a042, cs310cm);
		c2 = new Créneau(2014, 1, 17, 13, 15, 210, b141, cs330tp1);
			
 		p.addCréneau(c1);
		p.addCréneau(c2);
```

Comment peut-on modifier la définition des classes pour atteindre ce résultat? 

* Réaliser si le temps le permet une implémentation des deux extensions citées.
