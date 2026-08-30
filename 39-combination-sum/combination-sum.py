class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()

        ans = []

        def backtrack(start, path, total):

            if total == target:
                ans.append(path[:])
                return

            for i in range(start, len(candidates)):

                if total + candidates[i] > target:
                    break

                path.append(candidates[i])

                backtrack(
                    i,
                    path,
                    total + candidates[i]
                )

                path.pop()

        backtrack(0, [], 0)

        return ans