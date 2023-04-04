import java.util.*;

public class Creneau {
    private int annee;
    private int mois; // 1 à 12
    private int jour; // 1 à 31
    private int heure; // 0 à 23
    private int minute; // 0 à 59
    private int duree; // en minutes, maximum 210

    private Salle salle;
    private Activite activite;

    public Creneau(int a, int m, int j, int h, int min, int d, Salle s, Activite ac) {

        annee = a;
        mois = m;
        jour = j;
        heure = h;
        minute = min;
        duree = d;
        salle = s;
        activite = ac;

        if (!verifCapacite()) {
            System.exit(1); // On pourrait utiliser un mécanisme d'exception, aussi.
        }
        if (!verifDuree()) {
            System.exit(1);
        }
        if (!verifSalle()) {
            System.exit(1);
        }
    }

    // Verifie l'adéquation de la salle : la salle affectée doit être une des salles
    // appropriées de l'activité. Indication: utiliser une methode de liste.
    private boolean verifSalle() {
        for (final Salle sale : activite.getSalles()){
            if (sale.equals(salle))
                return true;
        }
        return false;
    }

    // Verifie que la taille de la salle convient à la promo
    private boolean verifCapacite() {
        int nombre_total=0;
        for(final Groupe grp:activite.getGroupes()){
            nombre_total+=grp.getEffectif();
        }
        return salle.getCapacite()>=nombre_total;
    }

    // Verifie que le début et la fin du créneau sont dans la même journée, entre 8h
    // et 19h
    private boolean verifDuree() {
        int temp_start=heure*60+minute;
        int temp_end=temp_start+duree;
        return 8*60<=temp_start && temp_start<=19*60 && 8*60<=temp_end && temp_end<=19*60;
    }

    public Salle getSalle() {
        return salle;
    }

    public Activite getActivite() {
        return activite;
    }

    public int getDuree() {
        return duree;
    }

    public String toString() {
        return jour + "/" + mois + "/" + annee + " " + heure + ":" + minute + " (" + duree + ") : " + activite + " " + salle;
    }

    // Intersection
    public boolean intersection(Creneau c) {
        // TODO : change implem
        // Vous pouvez utiliser toutes les fonctions auxiliaires que vous voulez.
        int temp1_start=heure*60+minute;
        int temp1_end=temp1_start+duree;
        int temp2_start=c.heure*60+c.minute;
        int temp2_end=temp2_start+c.duree;
        return 
               (temp1_start<=temp2_start && temp2_start<=temp1_end) || (temp1_start<=temp2_end   && temp2_end<=temp1_end) ||
               (temp2_start<=temp1_start && temp1_start<=temp2_end) || (temp2_start<=temp1_end   && temp1_end<=temp2_end);
    }

}
