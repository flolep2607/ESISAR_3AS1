package Restaurant;

import java.util.ArrayList;

public class Commande {
    private ArrayList<Consommable> itemsCommandes;

    public Commande() {
        this.itemsCommandes = new ArrayList<Consommable>();
    }

    public void addItem(Consommable c) {
        this.itemsCommandes.add(c);
    }

    public ArrayList<Consommable> getItemsCommandes() {
        return this.itemsCommandes;
    }
    
    public String toString(){
        String message = "Commande compose de ";
        for (Consommable c : itemsCommandes) {
            message += c.toString() + "\n";
        }
        return message;
    }

}
