class Solution:
    def combinationSum(self, candidates, target):
        ans = []

        def backtrack(index, path, total):
            if total > target:
                return

            if total == target:
                ans.append(path[:])
                return

            for i in range(index, len(candidates)):
                backtrack(
                    i,
                    path + [candidates[i]],
                    total + candidates[i]
                )

        backtrack(0, [], 0)

        return ans