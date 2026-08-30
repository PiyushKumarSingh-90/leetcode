class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()

        ans = []

        def backtrack(index, path, total):
            if total == target:
                ans.append(path[:])
                return

            for i in range(index, len(candidates)):

                if total + candidates[i] > target:
                    continue

                backtrack(
                    i,
                    path + [candidates[i]],
                    total + candidates[i]
                )

        backtrack(0, [], 0)

        return ans