/*** This file is kind of empty as we only call two function from other module. ***/

#define MAX_INSTRUCTIONS_EXECUTE 50


/** La fonction principale, elle permet d'executer le programme chargéen mémoire.
	Elle prends en compte le mode pas à pas et le mode normal.
*/
void execute_program();

/** La fonction d'execution réservée au mode interractif.
	La manière dont le mode interractif fonctionne est la suivante:
	1 - L'utilisateur entre une instruction depuis l'entree standard
	2 - L'instruction est traduite puis écrite en mémoire à l'adresse pointée par le PC
	3- Le programme est executé à partir de cette addresse jusqu'à qu'il atteigne une zone mémoire non initialisée
	Ce fonctionement particulier permet de réaliser des boucles, notamment avec des fonction de type "branch".
*/
void interraction_profonde();
