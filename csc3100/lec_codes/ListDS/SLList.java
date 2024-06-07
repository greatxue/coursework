package ListDS;

public class SLList<Integer> implements ListDS<Integer>{
    private class Node {
        public int data;
        public Node next;
        
        public Node(int data) {
            this.data = data;
            this.next = null;
        }

        public void displayNodeData() {
            System.out.println("Node: {" + data + "}");
        }
    }

    private Node head;
    
    public boolean isEmpty() {
        return head == null;
    }

    public void insertFirst(int data) {
        Node newNode = new Node(data);
        head = newNode;
    }

    public void insertLast(int data) {
        if (head == null) {
            insertFirst(data);
        }
        else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new Node(data);
        }
    }

    public void deleteFirst() {
        if (head != null) {
            head = head.next;
        }
    }

    public void deleteLast() {
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current = null;
    }
    
    void insert(int x, int p) {

    }
    
}
