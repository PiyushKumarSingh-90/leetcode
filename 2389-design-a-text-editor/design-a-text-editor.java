class TextEditor {

    StringBuilder left;
    StringBuilder right;

    public TextEditor() {
        left = new StringBuilder();
        right = new StringBuilder();
    }

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        int count = Math.min(k, left.length());

        left.delete(left.length() - count, left.length());

        return count;
    }

    public String cursorLeft(int k) {

        int move = Math.min(k, left.length());

        while (move-- > 0) {
            char ch = left.charAt(left.length() - 1);

            left.deleteCharAt(left.length() - 1);
            right.append(ch);
        }

        return getLast10();
    }

    public String cursorRight(int k) {

        int move = Math.min(k, right.length());

        while (move-- > 0) {
            char ch = right.charAt(right.length() - 1);

            right.deleteCharAt(right.length() - 1);
            left.append(ch);
        }

        return getLast10();
    }

    private String getLast10() {
        int start = Math.max(0, left.length() - 10);

        return left.substring(start);
    }
}