###########################################
###					###
###		Rendu N°1		###
###					###
###########################################

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[] Option Makefile disponible:
	all, run, clean, dist

[] Utilisation:
	Les tests doivent être présent dans
un dossier test accessible depuis le 
répertoir d'appel du programme.
(Même syntaxe d'appel que l'exemple 2019)
Exemple:userir:$ pwd
/home/src
userir:$ ls
hexified tests emu-mips
userir:$ ls tests
in1.txt in4.txt
userir:$ ./emu-mips in4.txt
userir:$ 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[] Cahier des charges:
	Le programme que nous fournissont
doit uniquement être capable de traduire un
fichier asm en suite d'instruction en
language machine
(code hexadecimal dans un fichier texte).

[!] Suppositions:
	On supposera que le fichier passé
en argument sera syntaxiquement correct
et que le code sera correct lui aussi.
La détection d'erreur ne fait pas partie de
notre cahier des charges

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
[] Standard Output:
	Par défault le programme n'envoie
rien sur la sortie standard. Néanmoins,
il est possible d'avoir un aperçu du
travail éffectué au fur et à mesure en 
compilant avec l'option "–D DEBUG_BITS"
(pas pris en charge par le makefile)
ou en définissant DEBUG_BITS dans le
code source.

___________________________________________

 		- CS351 - 

		Rougé Jean, Patard Gauthier
				 27/12/2021

