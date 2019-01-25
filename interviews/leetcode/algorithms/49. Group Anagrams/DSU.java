public class DSU {
    int[] pai, sz;
    Map<String, Integer> id;
    Map<Integer, String> idt;
    List<List<String>> groups;

    public DSU(String[] strs) {
        int n = strs.length;
        
        pai = new int[n]; sz = new int[n];
        id = new HashMap<>();
        idt = new HashMap<>();

        for (int i = 0; i < n; i++) {
            pai[i] = i; sz[i] = 1;

            id.put(strs[i], i);
            idt.put(i, strs[i]);
        }
    }

    public void build() {

    }
}