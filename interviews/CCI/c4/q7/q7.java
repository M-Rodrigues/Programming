import java.util.ArrayList;

public class q7 {
    public static void main(String[] args) {
        Graph g = new Graph();

        // Ler projetos
        g.addProject("a");
        g.addProject("b");
        g.addProject("c");
        g.addProject("d");
        g.addProject("e");
        g.addProject("f");

        // Ler dependecias
        g.addDependency("a", "d");
        g.addDependency("f", "b");
        g.addDependency("b", "d");
        g.addDependency("f", "a");
        g.addDependency("d", "c");
        
        // Construir ordem de projetos
        try {
            ArrayList<Project> ordem = buildOrder(g);
            showPath(ordem);
        } catch(NoOrderFound e) {
            System.out.println(e.message);
        }
        
    }
    
    private static class NoOrderFound extends Exception {
        public String message;
        public NoOrderFound(String m) { this.message = m; }
    }
    
    public static ArrayList<Project> buildOrder(Graph g) throws NoOrderFound {
        ArrayList<Project> ans = new ArrayList<Project>();
        for (Project p : g.nodes) {
            if (p.inc == 0) {
                ans.add(p);
                removeEdges(p, ans);
            }
        }
        
        if (ans.size() < g.nodes.size()) {
            throw new NoOrderFound("Não existe ordem que passa por todos os projetos.");
        }
        return ans;
    }
    
    private static void removeEdges(Project p, ArrayList<Project> ans) {
        for (Project pp : p.adj) {
            if (--pp.inc == 0) {
                ans.add(pp); removeEdges(pp, ans);
            }
        }
    }
    
    public static void showPath(ArrayList<Project> arr) {
        for (int i = 0; i < arr.size(); i++) {
            System.out.print(arr.get(i).name + (i == arr.size()-1 ? "\n" : ", "));
        }
    }
}