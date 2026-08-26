class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace("-", "").upper()

        first = len(s) % k
        ans = []

        if first > 0:
            ans.append(s[:first])

        for i in range(first, len(s), k):
            ans.append(s[i:i + k])

        return "-".join(ans)