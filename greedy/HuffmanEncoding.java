

class HuffmanEncoding {
    
    public static void main(String[] args) {
        String text = "To be, or not to be: that is the question: " +
        "Whether tis nobler in the mind to suffer " +
        "The slings and arrows of outrageous fortune, " +
        "Or to take arms against a sea of troubles, " +
        "And by opposing end them? To die: to sleep; " +
        "No more; and, by a sleep to say we end " +
        "The heart-ache and the thousand natural shocks " +
        "That flesh is heir to, tis a consummation " +
        "Devoutly to be wishd. To die, to sleep; " +
        "To sleep: perchance to dream: ay, there’s the rub.";
        
        char[] chars = new char[256];
        
        
        // Build frequency table
        for (int i = 0; i < text.length(); i++) {
            char ch = text.chatAt(i);
            chars[(int) ch]++;
        }
        
        
        // create min-heap with frequencies
        PriorityQueue pqueue = new PriorityQueue(chars.length, new NodeComparator());
        for (int i = 0; i < chars.length; i++) {
            String str = String.valueOf((char) i);
            pqueue.add(new Node(str, chars[i], null, null));
        }
        
        // Build encoding tree
        while (pqueue.size() > 1) {
            Node left = pqueue.poll();
            Node right = pqueue.poll();
            Node parent = new Node(left.chars + right.chars, left.freq + right.freq, left, right);
            pqueue.add(parent);
        }
        
        // Traverse the tree and generate the encoding table
        traverseTree(pqueue.poll(), "", "");
        
    }
    
    static traverseTree(Node n, String parentStr, String code) {
        if (n == null) {
            System.out.println("char: " + parentStr + " code : " + code);
        }
        
        traverseTree(n.left, n.chars, code + "0");
        traverseTree(n.right, n.chars, code + "1");
    }
    
    public static class NodeComparator implements Comparator<Node> {
        public int compare(Node a, Node b) {
            return a.freq - b.freq;
        }
    }
    
    public static class Node {
        
        public (String str, int freq, Node left, Node right) {
            this.chars = str;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }
    
        public String chars;
        public int freq;
        public Node left;
        public Node right; 
    }
    
}
