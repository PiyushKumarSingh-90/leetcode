class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        depth = 0
        ans = []

        for ch in s:

            if ch == '(':

                if depth > 0:
                    ans.append(ch)

                depth += 1

            else:

                depth -= 1

                if depth > 0:
                    ans.append(ch)

        return ''.join(ans)