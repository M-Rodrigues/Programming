class MyLinkedList {
    private class Node {
        public int val;
        public Node next;
        public Node(int val) { this.val = val; next = null; }
    }
    
    private Node head;
    private int size;
    
    public MyLinkedList() {
        head = null; size = 0;
    }
    
    public int get(int index) {
        if (index >= size) return -1;
        
        Node aux = head;
        while (index > 0) {
            aux = aux.next;
            index--;
        }
        return aux.val;
    }
    
    public void addAtHead(int val) {
        Node aux = new Node(val);
        aux.next = head;
        head = aux;
        size++;
    }
    
    public void addAtTail(int val) {
        if (isEmpty()) {
            addAtHead(val);
            return;
        }
        Node aux = head;
        while (aux.next != null) aux = aux.next;
        aux.next = new Node(val);
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size) return;
            
        if (index == 0) {
            addAtHead(val);
            return;
        }    
        
        if (index == size) {
            addAtTail(val);
            return;
        }
        
        index--;
        Node aux = head;
        
        while (index > 0) {
            aux = aux.next;
            index--;
        }
        Node aux2 = aux.next;
        aux.next = new Node(val);
        aux.next.next = aux2;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if (isEmpty()) return;
        
        if (index >= size) return;
        
        index--;
        Node aux = head;
        while (index > 0) {
            aux = aux.next;
            index--;
        } 
        Node aux2 = aux.next;
        aux.next = aux2.next;
        aux2 = null;
        size--;
    }
    
    private boolean isEmpty() { return head == null; }
}
