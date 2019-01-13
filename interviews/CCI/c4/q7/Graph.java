import java.util.ArrayList;

public class Graph {
    public ArrayList<Project> nodes;

    public Graph() { nodes = new ArrayList<Project>(); }

    public void addProject(String name) {
        nodes.add(new Project(name));
    }

    public void addDependency(String p1_name, String p2_name) {
        Project p1 = this.getProject(p1_name);
        Project p2 = this.getProject(p2_name);

        p1.addDependency(p2);
    }

    private Project getProject(String name) {
        for (Project p : nodes) { if (p.name == name) return p; } return null;
    }
}