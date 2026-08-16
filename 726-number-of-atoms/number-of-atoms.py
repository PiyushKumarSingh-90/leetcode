class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [{}]
        i = 0
        n = len(formula)

        while i < n:

            if formula[i] == '(':
                stack.append({})
                i += 1

            elif formula[i] == ')':
                group = stack.pop()
                i += 1

                num = 0

                while i < n and formula[i].isdigit():
                    num = num * 10 + int(formula[i])
                    i += 1

                num = num or 1

                for atom, count in group.items():
                    stack[-1][atom] = (
                        stack[-1].get(atom, 0)
                        + count * num
                    )

            else:
                atom = formula[i]
                i += 1

                while i < n and formula[i].islower():
                    atom += formula[i]
                    i += 1

                num = 0

                while i < n and formula[i].isdigit():
                    num = num * 10 + int(formula[i])
                    i += 1

                num = num or 1

                stack[-1][atom] = (
                    stack[-1].get(atom, 0) + num
                )

        count = stack[0]

        ans = ""

        for atom in sorted(count):
            ans += atom

            if count[atom] > 1:
                ans += str(count[atom])

        return ans