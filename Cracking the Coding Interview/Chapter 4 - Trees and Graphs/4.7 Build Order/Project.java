import java.util.ArrayList;

public class Project {
    public String name;
    public int inc; // Incoming edges
    public ArrayList<Project> adj;

    public Project(String name) {
        this.name = name; this.inc = 0;
        this.adj = new ArrayList<Project>();
    }
    
    public void addDependency(Project p) {
        this.adj.add(p);
        p.inc++;
    }
}