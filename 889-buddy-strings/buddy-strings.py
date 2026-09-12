class Solution:
    def buddyStrings(self, s, goal):
        if len(s) != len(goal):
            return False

        if s == goal:
            return len(set(s)) < len(s)

        diff = []

        for i in range(len(s)):
            if s[i] != goal[i]:
                diff.append(i)

        if len(diff) != 2:
            return False

        i, j = diff

        return (
            s[i] == goal[j] and
            s[j] == goal[i]
        )