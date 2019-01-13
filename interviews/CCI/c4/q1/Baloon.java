public class Baloon {
    public String name;

    public void setName(String name) { this.name = name; }
    public String getName() { return this.name; }

    public Baloon(String name) { this.name = name; }

    @Override
    public String toString() { return "Nome: " + this.name; }
}