package Restaurant;


public class Plat implements Consommable{
    private String nom;
    private int prix;
    
    public Plat(String nom, int prix){
	    // super(nom,  prix);
        this.nom = nom;
        this.prix = prix;
    }
    @Override
    public String getNom() {
        return this.nom;
    }
    @Override
    public int getPrix() {
        return this.prix;
    }
    public String toString(){
        return this.nom + " (" + this.prix + " $)";
    }
}
