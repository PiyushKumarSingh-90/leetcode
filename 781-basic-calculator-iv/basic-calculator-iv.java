import java.util.*;

class Solution {

    private String expression;
    private int index;
    private Map<String, Integer> values;

    public List<String> basicCalculatorIV(
        String expression,
        String[] evalvars,
        int[] evalints
    ) {

        this.expression = expression;
        this.index = 0;

        values = new HashMap<>();

        for (int i = 0; i < evalvars.length; i++) {
            values.put(evalvars[i], evalints[i]);
        }

        Map<String, Integer> poly = parseExpression();

        List<String> terms = new ArrayList<>();

        for (String key : poly.keySet()) {

            int coef = poly.get(key);

            if (coef == 0)
                continue;

            if (key.length() == 0) {
                terms.add(String.valueOf(coef));
            } else {
                terms.add(coef + "*" + key);
            }
        }

        terms.sort((a, b) -> {

            String termA = removeCoefficient(a);
            String termB = removeCoefficient(b);

            int degreeA = degree(termA);
            int degreeB = degree(termB);

            if (degreeA != degreeB) {
                return degreeB - degreeA;
            }

            return termA.compareTo(termB);
        });

        return terms;
    }


    private Map<String, Integer> parseExpression() {

        Map<String, Integer> result = parseTerm();

        while (true) {

            skipSpaces();

            if (
                index >= expression.length()
                || expression.charAt(index) == ')'
            ) {
                break;
            }

            char op = expression.charAt(index);
            index++;

            Map<String, Integer> next = parseTerm();

            if (op == '+') {
                result = add(result, next, 1);
            } else {
                result = add(result, next, -1);
            }
        }

        return result;
    }


    private Map<String, Integer> parseTerm() {

        Map<String, Integer> result = parseFactor();

        while (true) {

            skipSpaces();

            if (
                index >= expression.length()
                || expression.charAt(index) != '*'
            ) {
                break;
            }

            index++;

            result = multiply(result, parseFactor());
        }

        return result;
    }


    private Map<String, Integer> parseFactor() {

        skipSpaces();

        Map<String, Integer> result = new HashMap<>();

        // Parentheses
        if (expression.charAt(index) == '(') {

            index++;

            result = parseExpression();

            skipSpaces();

            index++;

            return result;
        }

        // Number
        if (Character.isDigit(expression.charAt(index))) {

            int num = 0;

            while (
                index < expression.length()
                && Character.isDigit(expression.charAt(index))
            ) {
                num =
                    num * 10
                    + (expression.charAt(index) - '0');

                index++;
            }

            result.put("", num);

            return result;
        }

        // Variable
        StringBuilder name = new StringBuilder();

        while (
            index < expression.length()
            && Character.isLetter(expression.charAt(index))
        ) {
            name.append(expression.charAt(index));
            index++;
        }

        String var = name.toString();

        if (values.containsKey(var)) {

            result.put("", values.get(var));

        } else {

            result.put(var, 1);
        }

        return result;
    }


    private Map<String, Integer> add(
        Map<String, Integer> a,
        Map<String, Integer> b,
        int sign
    ) {

        Map<String, Integer> result = new HashMap<>(a);

        for (String key : b.keySet()) {

            result.put(
                key,
                result.getOrDefault(key, 0)
                    + sign * b.get(key)
            );
        }

        return result;
    }


    private Map<String, Integer> multiply(
        Map<String, Integer> a,
        Map<String, Integer> b
    ) {

        Map<String, Integer> result = new HashMap<>();

        for (String key1 : a.keySet()) {

            for (String key2 : b.keySet()) {

                String key = merge(key1, key2);

                int value =
                    a.get(key1) * b.get(key2);

                result.put(
                    key,
                    result.getOrDefault(key, 0) + value
                );
            }
        }

        return result;
    }


    private String merge(String a, String b) {

        List<String> vars = new ArrayList<>();

        if (!a.isEmpty()) {
            vars.addAll(Arrays.asList(a.split("\\*")));
        }

        if (!b.isEmpty()) {
            vars.addAll(Arrays.asList(b.split("\\*")));
        }

        Collections.sort(vars);

        return String.join("*", vars);
    }


    private void skipSpaces() {

        while (
            index < expression.length()
            && expression.charAt(index) == ' '
        ) {
            index++;
        }
    }


    private int degree(String term) {

        if (term.isEmpty())
            return 0;

        return term.split("\\*").length;
    }


    private String removeCoefficient(String s) {

        int pos = s.indexOf('*');

        if (pos == -1)
            return "";

        return s.substring(pos + 1);
    }
}