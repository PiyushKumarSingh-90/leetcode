class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()

        ans = []

        def backtrack(start, path, total):

            if total == target:
                ans.append(path[:])
                return

            for i in range(start, len(candidates)):

                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                if total + candidates[i] > target:
                    break

                path.append(candidates[i])

                backtrack(
                    i + 1,
                    path,
                    total + candidates[i]
                )

                path.pop()

        backtrack(0, [], 0)

        return ans