class Solution:
    def isLongPressedName(self, name, typed):
        i = 0

        for j in range(len(typed)):

            if i < len(name) and typed[j] == name[i]:
                i += 1

            elif j > 0 and typed[j] == typed[j - 1]:
                continue

            else:
                return False

        return i == len(name)