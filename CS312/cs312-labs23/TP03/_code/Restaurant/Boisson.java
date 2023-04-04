package Restaurant;

public class Boisson implements Consommable {

    private int volume; // en centilitres
    private int prix;
    private String name;


    public Boisson(String nom, int prix, int volume) {
        // super(nom, prix);
        this.volume = volume;
        this.prix=prix;
        this.name=nom;
    }
    @Override
    public int getPrix() {
        return this.prix;
    }
    @Override
    public String getNom() {
        return this.name;
    }
    @Override
    public String toString() {
        return this.name + " (" + this.prix + " $)";
    }

    public Boisson(String nom, int volume) {
        this(nom, 0, volume);
    }

    public int getVolume() {
        return volume;
    }
}
