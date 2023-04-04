package Restaurant;

import java.util.ArrayList;

public class Menu {
    private ArrayList<Consommable> items;
    private int prix; // en cents

    public Menu(int prix, Entree e, PlatPrincipal p, Dessert d, Boisson b) {
        items=new ArrayList<Consommable>();
        items.add(e);
        items.add(p);
        items.add(d);
        items.add(b);
        this.prix = prix;
        if (!verifPrixMenu()) throw new IllegalArgumentException("Le prix du menu est >= au prix des items");
    }

    public ArrayList<Consommable> getItems() {
        return this.items;
    }

    public int getPrix() {
        return this.prix;
    }

    public String toString() {
        String message = "Menu compose de ";
        for (Consommable c : items) {
            message += c.toString() + "\n";
        }
        message += "pour un prix de " + this.prix + " $";
        return message;
    }
    private boolean verifPrixMenu(){
        int prixMenu=0;
        for (Consommable c : items) {
            prixMenu+=c.getPrix();
        }
        return prixMenu>this.prix;
    }
}
