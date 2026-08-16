import java.util.*;

class Solution {
    public String countOfAtoms(String formula) {

        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());

        int i = 0;
        int n = formula.length();

        while (i < n) {

            char ch = formula.charAt(i);

            if (ch == '(') {

                stack.push(new HashMap<>());
                i++;

            } else if (ch == ')') {

                Map<String, Integer> group = stack.pop();
                i++;

                int num = 0;

                while (i < n && Character.isDigit(formula.charAt(i))) {
                    num = num * 10 + (formula.charAt(i) - '0');
                    i++;
                }

                if (num == 0) {
                    num = 1;
                }

                Map<String, Integer> current = stack.peek();

                for (String atom : group.keySet()) {

                    int count = group.get(atom) * num;

                    current.put(
                        atom,
                        current.getOrDefault(atom, 0) + count
                    );
                }

            } else {

                StringBuilder atom = new StringBuilder();

                atom.append(formula.charAt(i));
                i++;

                while (
                    i < n &&
                    Character.isLowerCase(formula.charAt(i))
                ) {
                    atom.append(formula.charAt(i));
                    i++;
                }

                int num = 0;

                while (
                    i < n &&
                    Character.isDigit(formula.charAt(i))
                ) {
                    num = num * 10 + (formula.charAt(i) - '0');
                    i++;
                }

                if (num == 0) {
                    num = 1;
                }

                String name = atom.toString();

                stack.peek().put(
                    name,
                    stack.peek().getOrDefault(name, 0) + num
                );
            }
        }

        Map<String, Integer> count = stack.pop();

        List<String> atoms = new ArrayList<>(count.keySet());
        Collections.sort(atoms);

        StringBuilder ans = new StringBuilder();

        for (String atom : atoms) {

            ans.append(atom);

            if (count.get(atom) > 1) {
                ans.append(count.get(atom));
            }
        }

        return ans.toString();
    }
}