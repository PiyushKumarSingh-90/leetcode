class Solution:
    def isValid(self, code: str) -> bool:
        stack = []
        i = 0
        n = len(code)

        def valid(tag):
            return (
                1 <= len(tag) <= 9
                and all('A' <= ch <= 'Z' for ch in tag)
            )

        while i < n:

            # Root tag already closed but characters remain
            if i > 0 and not stack:
                return False

            # CDATA
            if code.startswith("<![CDATA[", i):

                if not stack:
                    return False

                j = code.find("]]>", i + 9)

                if j == -1:
                    return False

                i = j + 3

            # Closing tag
            elif code.startswith("</", i):

                j = code.find('>', i + 2)

                if j == -1:
                    return False

                tag = code[i + 2:j]

                if not valid(tag):
                    return False

                if not stack or stack[-1] != tag:
                    return False

                stack.pop()
                i = j + 1

            # Opening tag
            elif code[i] == '<':

                j = code.find('>', i + 1)

                if j == -1:
                    return False

                tag = code[i + 1:j]

                if not valid(tag):
                    return False

                stack.append(tag)
                i = j + 1

            # Normal text
            else:

                if not stack:
                    return False

                i += 1

        return not stack