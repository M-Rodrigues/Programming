public class q1 {
    public static void main(String[] args) {
        Baloon b1 = new Baloon("Azul");
        Baloon b2 = new Baloon("Verde");

        System.out.println(b1);
        System.out.println(b2);

        swap(b1,b2);

        System.out.println(b1);
        System.out.println(b2);

    }

    public static void swap(Baloon b1, Baloon b2) {
        Baloon aux = new Baloon(b1.getName());
        b1.setName(b2.getName());
        b2.setName(aux.getName());
    }
}