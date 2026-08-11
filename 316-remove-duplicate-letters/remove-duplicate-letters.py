class Solution:
    def removeDuplicateLetters(self, s: str) -> str:

        last = {}

        # Store last position of each character
        for i in range(len(s)):
            last[s[i]] = i

        stack = []
        used = set()

        for i in range(len(s)):
            ch = s[i]

            # Already present
            if ch in used:
                continue

            # Remove bigger characters
            # only if they appear again later
            while (
                stack
                and stack[-1] > ch
                and last[stack[-1]] > i
            ):
                removed = stack.pop()
                used.remove(removed)

            stack.append(ch)
            used.add(ch)

        return ''.join(stack)