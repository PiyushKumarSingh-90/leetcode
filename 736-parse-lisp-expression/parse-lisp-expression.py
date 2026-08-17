class Solution:
    def evaluate(self, expression: str) -> int:

        self.tokens = (
            expression
            .replace("(", "( ")
            .replace(")", " )")
            .split()
        )

        self.i = 0

        def is_number(token):
            return token.lstrip('-').isdigit()

        def parse(env):

            token = self.tokens[self.i]

            # Integer or variable
            if token != "(":
                self.i += 1

                if is_number(token):
                    return int(token)

                return env[token]

            # Skip "("
            self.i += 1

            op = self.tokens[self.i]
            self.i += 1

            # ADD
            if op == "add":

                a = parse(env)
                b = parse(env)

                self.i += 1      # skip ")"

                return a + b

            # MULT
            if op == "mult":

                a = parse(env)
                b = parse(env)

                self.i += 1      # skip ")"

                return a * b

            # LET
            local = env.copy()
            result = 0

            while self.tokens[self.i] != ")":

                token = self.tokens[self.i]

                # Final expression is nested expression or number
                if token == "(" or is_number(token):

                    result = parse(local)
                    break

                # Final expression is a variable
                if self.tokens[self.i + 1] == ")":

                    result = local[token]
                    self.i += 1
                    break

                # Variable assignment
                variable = token
                self.i += 1

                value = parse(local)

                local[variable] = value

            self.i += 1      # skip ")"

            return result

        return parse({})