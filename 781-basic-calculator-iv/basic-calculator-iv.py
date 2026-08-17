class Solution:
    def basicCalculatorIV(self, expression, evalvars, evalints):

        values = dict(zip(evalvars, evalints))
        self.i = 0
        n = len(expression)

        def add(a, b, sign=1):
            result = a.copy()

            for term, coef in b.items():
                result[term] = result.get(term, 0) + sign * coef

            return result

        def multiply(a, b):
            result = {}

            for term1, coef1 in a.items():
                for term2, coef2 in b.items():

                    term = tuple(sorted(term1 + term2))

                    result[term] = (
                        result.get(term, 0)
                        + coef1 * coef2
                    )

            return result

        def skip_spaces():
            while self.i < n and expression[self.i] == ' ':
                self.i += 1

        def factor():
            skip_spaces()

            # Parentheses
            if expression[self.i] == '(':
                self.i += 1

                result = parse_expression()

                skip_spaces()
                self.i += 1

                return result

            # Number
            if expression[self.i].isdigit():
                num = 0

                while self.i < n and expression[self.i].isdigit():
                    num = num * 10 + int(expression[self.i])
                    self.i += 1

                return {(): num}

            # Variable
            name = ""

            while self.i < n and expression[self.i].isalpha():
                name += expression[self.i]
                self.i += 1

            if name in values:
                return {(): values[name]}

            return {(name,): 1}

        def term():
            result = factor()

            while True:
                skip_spaces()

                if self.i >= n or expression[self.i] != '*':
                    break

                self.i += 1

                result = multiply(result, factor())

            return result

        def parse_expression():
            result = term()

            while True:
                skip_spaces()

                if self.i >= n or expression[self.i] == ')':
                    break

                op = expression[self.i]
                self.i += 1

                next_term = term()

                if op == '+':
                    result = add(result, next_term)

                else:
                    result = add(result, next_term, -1)

            return result

        poly = parse_expression()

        terms = [
            (term, coef)
            for term, coef in poly.items()
            if coef != 0
        ]

        # Higher degree first,
        # lexicographic order second
        terms.sort(
            key=lambda x: (-len(x[0]), x[0])
        )

        ans = []

        for term, coef in terms:

            if term:
                ans.append(
                    str(coef) + "*" + "*".join(term)
                )
            else:
                ans.append(str(coef))

        return ans