package Restaurant;

public class TestRestaurant {

    public TestRestaurant() {
    }
    
    public static void main(String args[]){
        Consommable[] menu = new Consommable[4];
        menu[0] = new Entree("Salade", 500);
        menu[1] = new PlatPrincipal("sandwich jambion boure", 500);
        menu[2] = new Dessert("Tarte", 500);
        menu[3] = new Boisson("Coca", 500, 50);
        
        for (int i = 0; i < menu.length; i++) {
            System.out.println(menu[i]);
        }
        Menu m = new Menu(1800,(Entree)menu[0],(PlatPrincipal)menu[1],(Dessert)menu[2],(Boisson)menu[3]);
        System.out.println(m);
        
    }
    
}
