package Restaurant;

import java.util.ArrayList;

public class Carte {
    private ArrayList<Consommable> entrees;
    private ArrayList<Consommable> platsPrincipaux;
    private ArrayList<Consommable> desserts;
    private ArrayList<Consommable> boissons;

    private ArrayList<Menu> menus;

    public Carte() {
        entrees = new ArrayList<Consommable>();
        platsPrincipaux = new ArrayList<Consommable>();
        desserts = new ArrayList<Consommable>();
        boissons = new ArrayList<Consommable>();
        menus = new ArrayList<Menu>();
    }

    public void addEntree(Entree e) {
        if (verifCarte(e))
            this.entrees.add(e);
    }

    public void addPlatPrincipal(PlatPrincipal p) {
        if (verifCarte(p))
            this.platsPrincipaux.add(p);
    }

    public void addDessert(Dessert d) {
        if (verifCarte(d))
            this.desserts.add(d);
    }

    public void addBoisson(Boisson b) {
        if (verifCarte(b))
            this.boissons.add(b);
    }

    public void addMenu(Menu m) {
        if(this.verifMenu(m)) this.menus.add(m);
    }

    public ArrayList<Consommable> getEntrees() {
        return this.entrees;
    }

    public ArrayList<Consommable> getPlatsPrincipaux() {
        return this.platsPrincipaux;
    }

    public ArrayList<Consommable> getDesserts() {
        return this.desserts;
    }

    public ArrayList<Consommable> getBoissons() {
        return this.boissons;
    }

    // Vérifie qu'il n'y a pas d'homonymes dans la carte
    // utiliser equals et des iterateurs
    //
    private boolean verifCarte(Consommable c) {
        ArrayList<Consommable> tmp = new ArrayList<Consommable>();
        tmp.addAll(entrees);
        tmp.addAll(platsPrincipaux);
        tmp.addAll(desserts);
        tmp.addAll(boissons);
        for (Consommable e : tmp) {
            if (e.getNom().equals(c.getNom()))
                return false;
        }
        return true;
    }

    // Vérifie que les plats et boissons du menu sont bien dans la carte
    private boolean verifMenu(Menu m) {
        for (Consommable c : m.getItems()) {
            if (!entrees.contains(c) &&
                !platsPrincipaux.contains(c) &&
                !desserts.contains(c) &&
                !boissons.contains(c)) {
                return false;
            }
        }
        return true;
    }

    /*
     * Calcule le prix de la commande. A priori, ce prix est la somme des prix des
     * items
     * SAUF si une partie de ces items constituent un menu; dans ce cas, le tarif
     * menu s'applique pour ces items.
     */
    public int calculerPrixCommande(Commande c) {
        int prix = 0;
        for (Consommable item : c.getItemsCommandes()) {
            prix += item.getPrix();
        }
        return prix;
    }

    public void afficherMenu() {
        System.out.println("Liste des entrees:" + entrees);
        System.out.println("Liste des plats principaux:" + platsPrincipaux);
        System.out.println("Liste des desserts:" + desserts);
        System.out.println("Liste des boissons:" + boissons);
    }
}
